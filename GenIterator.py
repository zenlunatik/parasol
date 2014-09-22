class GenIterator:
    def __init__(self, schemafile) :
        self.namespace = schemafile.split('.')[0].title()
        self.intCN = self.namespace[:-1] + "Iterator"
        self.implCN = self.intCN + "Impl"
        self.factoryCN = self.intCN + "Factory"
        self.iterHeaderFileName = self.namespace[:-1].lower() + "Iterator.h"
        self.srcFileName = self.namespace[:-1].lower() + "Iterator.cc"

        # schema file = sessions.xml
        # namespace = Sessions
        # interface name = SessionIterator
        # impl name = SessionIteratorImpl
        # factory name = SessionIteratorFactory
    
    def printNames(self) :
        print "namespace = " + self.namespace
        print "interface name = " + self.intCN
        print "impl name = " + self.implCN
        print "factory name = " + self.factoryCN

    def genHeader(self) :
        macroBegin = "#ifndef __" + self.namespace.upper() + "_ITER_H__\n#define __" + self.namespace.upper() + "_ITER_H__\n\n"
        readme = "// This is an auto generated file. \n//\n\n"
        nsBegin = "namespace "+ self.namespace +"\n{\n"
        usageComment =  "     //\n     // Using the iterator\n     // " + self.intCN + "* iter = " + self.factoryCN + "::get" + self.namespace[:-1] + "Iterator();\n     // if (!iter) return;\n     // for (iter->first(); !iter->isDone(); iter->next()) {\n     //      std::string username;\n     //      iter->currentItem()->getUsername(username);\n     // }\n     //\n\n"
        iterClass = "     class " + self.intCN +"\n     {\n     public:\n          virtual ~" + self.intCN + "() {}\n          virtual void first() = 0;\n          virtual void next() = 0;\n          virtual bool isDone() const = 0;\n          virtual " + self.namespace[:-1] + "Reader* currentItem() const = 0;\n     }; // class " + self.intCN + "\n\n"
        factoryClass = "     class " + self.factoryCN + "\n     {\n     public:\n          static " + self.intCN + "*get" + self.intCN + "();\n     }; // class " + self.factoryCN + "\n\n"
        nsEnd = "\n} // namespace " + self.namespace + "\n"
        macroEnd = "\n#endif\n"
        print self.iterHeaderFileName
        headerFO = open(self.iterHeaderFileName, "w")
        headerFO.write(macroBegin)
        headerFO.write(readme)
        headerFO.write(nsBegin)
        headerFO.write(usageComment)
        headerFO.write(iterClass)
        headerFO.write(factoryClass)
        headerFO.write(nsEnd)
        headerFO.write(macroEnd)
        headerFO.close()
    
    def genSource(self) :
        readme = "// This is an auto generated file. \n//\n\n"
        headers = "#include \"" + self.iterHeaderFileName + "\"\n#include <stdint.h>\n#include <boost/utility.hpp>\n"
        namespace = "using namespace " + self.namespace +";\n"
        iterimplClass = "\n//------------" + self.intCN + "-------------------\nclass " + self.implCN + ": public " + self.intCN + ",\n                          private boost::noncopyable\n{\npublic:\n    " + self.implCN + "();\n    ~" + self.implCN + "();\n\n    // ----------------BEGIN " + self.intCN + " interface--------------------------------\n    void first();\n    void next();\n    bool isDone() const;\n    " + self.namespace[:-1] + "Reader* currentItem() const;\n    //----------------END " + self.intCN + " interface----------------------------------\n\nprivate:\n    uint64_t m_current;\n}; // class " + self.implCN + "\n\n"

        iterimplMethods = "\n" + self.implCN + "::" + self.implCN + "()\n{\n    // Add code here to set up db to iterate\n    // over records\n    //\n\n}\n\n" + self.implCN + "::~" + self.implCN +"()\n{\n}\n\nvoid\n" + self.implCN + "::first()\n{\n}\n\nvoid\n" + self.implCN +"::next()\n{\n}\n\nbool" + self.implCN + "::isDone() const\n{\n    return true;\n}\n\n" + self.namespace[:-1] + "Reader*\n" + self.implCN + "::currentItem() const\n{    return NULL;\n}\n\n"
        iterFactoryImplMethods = self.intCN + "* \n" + self.factoryCN + "::get" + self.intCN + "()\n{\n    return new " + self.implCN + "();\n}"

        print self.srcFileName
        srcFO = open(self.srcFileName, "w")
        srcFO.write(readme)
        srcFO.write(headers)
        srcFO.write(namespace)
        srcFO.write(iterimplClass)
        srcFO.write(iterimplMethods)
        srcFO.write(iterFactoryImplMethods)
        srcFO.close()
