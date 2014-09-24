class GenUpdate:

    def genHeader(self, schemaDict) :
        className = schemaDict['root']
        namespace = className + 's'
        namespace = namespace.title()

        headers = "#include \"helpers.h\"\n#include <string>\n#include <vector>\n\n"         
        namespaceBegin = "namespace " + namespace + "\n{\n"
        classBegin = "     class " + className.title() + "\n     {\n"
        classDef = "     public:\n          virtual ~" + className.title() + "() {};\n\n"
        methodNames = ''
        for key,value in schemaDict['data'].items() :
            if key == schemaDict['root'] :
                continue
            # Ideally this mapping should come for a config file
            #
            dataType = 'int'
            if value['type'] == 'int' :
                dataType = 'int'
            elif value['type'] == 'string' :
                dataType = 'std::string'
            elif value['type'] == 'stringvector' :
                dataType = 'std::vector<std::string>'


            methodNames = methodNames + "          virtual Status set" + key.title() + "(const " + dataType + " " + key
            if 'default' in value :
                methodNames = methodNames + " = " + value['default']

            methodNames = methodNames + ") = 0;\n"

        commitMethod = "\n          virtual Status commitChanges() = 0;\n\n"
        classEnd = "     }; // class " + className.title() + "\n\n"
        factory = "     class " + className.title() + "Factory \n     {\n     public:\n          static " + className.title() + " *createNew" + className.title() + "(const char* " + className + "Id);\n     }; // class " + className.title() + "Factory\n"
        namespaceEnd = "\n} // namespace " + namespace
        headerFO = open(className + "Update.h", "w")
        headerFO.write(headers)
        headerFO.write(namespaceBegin)
        headerFO.write(classBegin)
        headerFO.write(classDef)
        headerFO.write(methodNames)
        headerFO.write(commitMethod)
        headerFO.write(classEnd)
        headerFO.write(factory)
        headerFO.write(namespaceEnd)
        headerFO.close()

    def genSource(self, schemaDict) :
        className = schemaDict['root']
        namespace = className + 's'
        namespace = namespace.title()

        headers = "#include \"" + className + "Update.h\"\n#include <boost/utility.hpp>\n\n"
        namespaceSet = "using namespace " + namespace + ";\n\n"
        comment = "//------------------" + className.title() + "-------------\n"
        implClassName = className.title() + "Impl"
        implClassNameSig = "class " + implClassName + " : public " + className.title() + ",\n               private boost::noncopyable\n"
        constructor = "{\npublic:\n     " + implClassName + "(const char* " + className + "Id);\n"
        destructor = "     ~" + implClassName + "() {}\n\n"
        comment2 = "// ----------------BEGIN " + className.title() + " interface --------------------------------\n"
        comment3 = "// ----------------END " + className.title() + " interface -----------------------------------\n"
        
        data = schemaDict['data']
        pvtVarNames =  "private:\n"
        rootTag = schemaDict['root']
        commitMethod = "\n     Status commitChanges();\n"
        methodNames = ""
        methodDefs = ""
        pvtVarInits = ''
        for key,value in data.items() :
            if key == rootTag :
	        continue
            dataType = 'int'
            if value['type'] == 'int' :
		dataType = 'int'
	    elif value['type'] == 'string' :
                dataType = 'std::string'
            elif value['type'] == 'vector' :
                dataType = 'std::vector<std::string>'
            defaultValue = ''
            if 'default' in value :
                defaultValue = ' = ' + value['default']
                pvtVarInits = pvtVarInits + "m_" + key + "(" + value['default'] + "),"
                 
 
            pvtVarNames = pvtVarNames + "\n     " + dataType + " m_" + key
            methodNames = methodNames + "\n     Status set" + key.title() + "(const " + dataType + " " + key + defaultValue + ");"
            methodDefs = methodDefs + "\nStatus\n" + implClassName + "::set" + key.title() + "(const " + dataType + " " + key + ")\n{\n     return kSuccess\n}\n"
        
        methodNames = methodNames + "\n"
        classEnd = "\n}; // end " + implClassName + "\n\n"
        factoryMethod = "\n\n" + className.title() + "*\n" + className.title() + "Factory::createNew" + className.title() + "(const char* " + className + "Id)\n{\n     return new " + implClassName + "(" + className + "Id);\n}"
        commitImpl = "\nStatus\n" + implClassName + "::commitChanges()\n{\n     // Insert code here to commit\n     // changes to a new  record\n     //\n\n     return kSuccess;\n}"
        
        constImpl = implClassName + "::" + implClassName + "(const char* " + className + "Id) : " + "\n          " + pvtVarInits[:-1] + "\n{\n     //Set up defaults here\n}\n"
        
        srcFO = open( className + "Update.cc" , "w")
        srcFO.write(headers)
        srcFO.write(namespaceSet)
        srcFO.write(comment)
        srcFO.write(implClassNameSig)
        srcFO.write(constructor)
        srcFO.write(destructor)
        srcFO.write(comment2)
        srcFO.write(methodNames)
        srcFO.write(commitMethod)
        srcFO.write(comment3)
        srcFO.write(pvtVarNames)
        srcFO.write(classEnd)
        srcFO.write(constImpl)
        srcFO.write(methodDefs)
        srcFO.write(commitImpl)
        srcFO.write(factoryMethod)
        srcFO.close()
