#! /usr/bin/env python
import sys, os, re

from glob import glob
from os import path

from ROOT import TFile

def printProgress(step, total):
    from sys import stdout
    stdout.write("\r [%3d %%]" % (100*float(step+1)/float(total)) )

def serialize(entry):
    """
    Serialize a possibly nested structure and
    turn them into lists of lists
    """
    try:
        return [serialize(pos) for pos in entry]
    except TypeError, e:
        return entry

def serializeTree((treefile, treename)):
    """
    Open a ROOT.TFile from <treefile>, extract a tree
    named <treename>, and turn it into a list of
    dictionaries of format branchname -> value

    Return the filename and list of dictionaries
    """
    try:
        fb = TFile.Open(treefile)
        tree = fb.Get(treename)
        tot_entries = tree.GetEntries()
    except AttributeError:
        print "ERROR: tree %s not found in %s" %(treename, treefile)
        return None
    print '  processing %s (%d entries)' % (treefile, tot_entries)

    branch_names = [b.GetName() for b in tree.GetListOfBranches()]

    result = []
    for n,entry in enumerate(tree):
        if(n%100==0): printProgress(n, tot_entries)
        entry_dict = {}
        for bn in branch_names:
            entry_dict[bn] = serialize(getattr(tree, bn))
            # Note this might be inefficient(?), calling once to extract
            # tree structure, then just filling would be better.
        result.append(entry_dict)

    print '\n  %s done' % (treefile)
    return treefile, result

def main(args, options):
    inputfiles = []
    try:
        inputfiles = [f for f in args if path.splitext(f)[1] == '.root']
        # print "Processing these files:", inputfiles

    except IndexError:
        print "Please provide at least one argument"
        parser.print_help()
        sys.exit(1)

    print 50*'%'


    # Serialize the trees
    tasks = [(f, 'finalTree') for f in inputfiles]
    results = {}

    if options.jobs < 0: pass ## Dry run
    elif options.jobs > 0:
        from multiprocessing import Pool
        pool = Pool(options.jobs)
        results = dict(pool.map(serializeTree, tasks))
    else:
        results = dict(map(serializeTree, tasks))

    # Process the results
    # Extract different components from comp_<number>.root pattern
    files = [path.basename(f.rsplit('_',1)[0]) for f in inputfiles]
    comps = [(c,files.count(c)) for c in list(set(files))]

    # Add up the results for each split component
    combined = {}
    for comp,nfiles in comps:
        print "... combining %s (%d files)" % (comp, nfiles)
        for fname in inputfiles:
            if not path.basename(fname.rsplit('_',1)[0]) == comp: continue
            combined.setdefault(comp,[]).extend(results[fname])

    # Make sure we have the same number of branches everywhere
    assert(len(set([len(combined[c][0].keys()) for c,_ in comps])) == 1)

    # Dump everything to JSON files
    import json
    for comp in combined.keys():
        with open(path.join(options.outDir, '%s.json'%comp), 'w') as ofile:
            json.dump(combined[comp], ofile, indent=2)
            # json.dump(combined[comp], ofile)

    print 50*'%'
    print "ALL DONE"
    print 50*'%'

    return 0


if __name__ == '__main__':
    from optparse import OptionParser
    usage = """
    dumpTreesToJSON.py

    Loop on a set of flat ROOT TTrees and convert their information
    into JSON documents, to be injected in a database or used further
    in a non-ROOT-based analysis.

    Note: json-serialized data uses about 10 times more diskspace.

    usage: %prog [options]
    run with --help to get list of options
    """
    parser = OptionParser(usage=usage)
    parser.add_option("-o", "--outDir", dest="outDir", default="jsonStream",
                      help="Location to place the output documents")
    parser.add_option("-j", "--jobs", dest="jobs", type="int", default=0,
                      help="Number of parallel threads to run")
    (options, args) = parser.parse_args()

    os.system('mkdir -p %s' % options.outDir)

    sys.exit(main(args, options))
