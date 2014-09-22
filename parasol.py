import argparse
import sys
import GenIterator
import SchemaParser

def main() :
    parser = argparse.ArgumentParser()
    parser.add_argument("--create", help="Will create a record create interface", action="store_true")
    parser.add_argument("--read", help="Will create a record read interface", action="store_true")
    parser.add_argument("--update", help="Will create a record update interface", action="store_true")
    parser.add_argument("--delete", help="Will create a record delete interface", action="store_true")
    parser.add_argument("--iterator", help="Will create an iterator interface", action="store_true")
    parser.add_argument("schema_file", help="The schema file that needs to be parsed")
    args = parser.parse_args()
    sp = SchemaParser.SchemaParser(args.schema_file)
    if args.create :
        print "create requested"
    if args.read :
        print "read requested"
    if args.update :
        print "update requested"
    if args.delete :
        print "delete requested"
    if args.iterator :
        print "Generating iterator"
        iterG = GenIterator.GenIterator(args.schema_file)
        iterG.genHeader()
        iterG.genSource()



if __name__ == '__main__' :
        sys.exit(main())

