class GenReader :
	def genHeader(self, schemaDict) :
		className=schemaDict['root']
		namespace = className + 's'
                namespace = namespace.title()
                className = className.title() + "Reader"
                headers = "#include \"helpers.h\"\n#include <string>\n#include <vector>\n\n"
                namespaceBegin = "namespace " + namespace + "\n{\n"
                classBegin = "     class " + className + "\n     {\n"
                classDef = "     public:\n          virtual ~" + className + "() {};\n\n"
                methodNames = ''
                for key,value in schemaDict['data'].items() :
			if key == schemaDict['root'] :
				continue
		        dataType = 'int'
            		if value['type'] == 'int' :
                		dataType = 'int'
            		elif value['type'] == 'string' :
                		dataType = 'std::string'
            		elif value['type'] == 'stringvector' :
                		dataType = 'std::vector<std::string>'
                	methodNames = methodNames + "          virtual Status get" + key.title() + "(" + dataType + "& " + key + ") = 0;\n"

                classEnd = "     }; // class " + className + "\n\n"
                factory = "     class " + className + "Factory \n     {\n     public:\n          static " + className + "* createNew" + className + "(const char* " + className + "Id);\n     }; // class " + className + "Factory\n"
        	namespaceEnd = "\n} // namespace " + namespace
        	headerFO = open(className + ".h", "w")
        	headerFO.write(headers)
		headerFO.write(namespaceBegin)
		headerFO.write(classBegin)
                headerFO.write(classDef)
                headerFO.write(methodNames)
                headerFO.write(classEnd)    
                headerFO.write(factory)
                headerFO.write(namespaceEnd)
                headerFO.close()

	def genSource(self, schemaDict) :
        	className = schemaDict['root']
        	namespace = className + 's'
        	namespace = namespace.title()
                className = className.title()
                className = className + "Reader"
        	headers = "#include \"" + className + "Update.h\"\n#include <boost/utility.hpp>\n\n"
        	namespaceSet = "using namespace " + namespace + ";\n\n"
        	comment = "//------------------" + className + "-------------\n"
        	implClassName = className + "Impl"
        	implClassNameSig = "class " + implClassName + " : public " + className + ",\n               private boost::noncopyable\n"
        	constructor = "{\npublic:\n     " + implClassName + "(const char* " + className + "Id);\n"
        	destructor = "     ~" + implClassName + "() {}\n\n"
        	comment2 = "// ----------------BEGIN " + className + " interface --------------------------------\n"
        	comment3 = "// ----------------END " + className + " interface -----------------------------------\n"
        
        	data = schemaDict['data']
        	pvtVarNames =  "private:\n"
        	rootTag = schemaDict['root']
        	methodNames = ""
        	methodDefs = ""
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
                 
 			pvtVarNames = pvtVarNames + "\n     " + dataType + " m_" + key
           		methodNames = methodNames + "\n     Status get" + key.title() + "(" + dataType + " " + key + ");"
            		methodDefs = methodDefs + "\nStatus\n" + implClassName + "::get" + key.title() + "(" + dataType + "&  " + key + ")\n{\n     return kSuccess\n}\n"
        
        	methodNames = methodNames + "\n"
        	classEnd = "\n}; // end " + implClassName + "\n\n"
        	factoryMethod = "\n\n" + className + "*\n" + className + "Factory::createNew" + className + "(const char* " + className + "Id)\n{\n     return new " + implClassName + "(" + className + "Id);\n}"
        
        	constImpl = implClassName + "::" + implClassName + "(const char* " + className + "Id) : " + "\n          " +  "\n{\n     //Set up defaults here\n}\n"
        
        	srcFO = open( className + ".cc" , "w")
                print className + ".cc"
        	srcFO.write(headers)
        	srcFO.write(namespaceSet)
        	srcFO.write(comment)
        	srcFO.write(implClassNameSig)
        	srcFO.write(constructor)
        	srcFO.write(destructor)
        	srcFO.write(comment2)
        	srcFO.write(methodNames)
        	srcFO.write(comment3)
        	srcFO.write(pvtVarNames)
        	srcFO.write(classEnd)
        	srcFO.write(constImpl)
        	srcFO.write(methodDefs)
        	srcFO.write(factoryMethod)
        	srcFO.close()
		

