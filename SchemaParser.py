import xml.etree.ElementTree as ET

class SchemaParser :
    def __init__(self, schemafile) :
        self.tree = ET.parse(schemafile)
        self.root = self.tree.getroot()
        self.rootTag = self.root.tag
        self.mItems = {}
        for elem in self.tree.iter() :
            self.mItems[elem.tag] = elem.attrib
