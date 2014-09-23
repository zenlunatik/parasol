import argparse
import sys
import GenIterator
import GenCreate
import xml.etree.ElementTree as ET

def getSchemaDict (schemafile) :
        tree = ET.parse(schemafile)
        root = tree.getroot()
        schemaDict = {}
        schemaDict['root'] = root.tag
        mItems = {}
        for elem in tree.iter() :
            mItems[elem.tag] = elem.attrib
        schemaDict['data'] = mItems
        return schemaDict

def createHelper(namespace) : 
        contents = "\n\nnamespace " + namespace + "\n{\n     enum Status {\n          kSuccess = 0,\n          kSuccess = 255\n    };\n} // namespace Sessions"

        headerFO = open("helpers.h", "a")
        headerFO.write(contents)
        headerFO.close()


def main() :
    parser = argparse.ArgumentParser()
    parser.add_argument("--create", help="Will create a record create interface", action="store_true")
    parser.add_argument("--read", help="Will create a record read interface", action="store_true")
    parser.add_argument("--update", help="Will create a record update interface", action="store_true")
    parser.add_argument("--delete", help="Will create a record delete interface", action="store_true")
    parser.add_argument("--iterator", help="Will create an iterator interface", action="store_true")
    parser.add_argument("schema_file", help="The schema file that needs to be parsed")
    args = parser.parse_args()
    schemaDict = getSchemaDict(args.schema_file)
    namespace = schemaDict['root'] + 's'
    namespace = namespace.title()
    createHelper(namespace)

    if args.create :
        print "create requested"
        createG = GenCreate.GenCreate()
        createG.genHeader(schemaDict)
    if args.read :
        print "read requested"
    if args.update :
        print "update requested"
    if args.delete :
        print "delete requested"
    if args.iterator :
        print "Generating iterator"
        #iterG = GenIterator.GenIterator(args.schema_file)
        #iterG.genHeader()
        #iterG.genSource()



if __name__ == '__main__' :
        sys.exit(main())

