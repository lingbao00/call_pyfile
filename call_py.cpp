#include "call_py.h"

CallPy::CallPy(const char* callpyfile)
{
	Py_Initialize();
	if(!Py_IsInitialized())
	{
		std::cout<<"init error"<<std::endl;
		return;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	m_pName = PyString_FromString(callpyfile);
	m_pModel = PyImport_Import(m_pName);
	if(!m_pModel)
	{
		std::cout<<"cannot found "<<callpyfile<<" file"<<std::endl;
		return;
	}	
}

CallPy::~CallPy()
{
	Py_Finalize();
}

int CallPy::GetArgc(int num)
{
	m_pArgc = PyTuple_New(num);
	m_pArgvs.resize(num);
	return 0;
}

int CallPy::FeedArgv(int argv,int i)
{
	m_pArgvs[i] = PyInt_FromLong(argv);
	PyTuple_SetItem(m_pArgc,i,m_pArgvs[i]);
	return 0;
}

int CallPy::FeedArgv(const char* str,int i)
{
	m_pArgvs[i] = PyString_FromString(str);
	PyTuple_SetItem(m_pArgc,i,m_pArgvs[i]);
	return 0;
}

int CallPy::FeedFunc(const char* funcname)
{
	m_pFunc = PyObject_GetAttrString(m_pModel,funcname);
	 if (!m_pFunc || !PyCallable_Check(m_pFunc))  // 验证是否加载成功
    {
        std::cout << "[ERROR] Can't find funftion (test_add)" << std::endl;
        return 0;
    }
    std::cout << "[INFO] Get function (test_add) succeed." << std::endl;
    m_pRet = PyObject_CallObject(m_pFunc,m_pArgc);
    if(m_pRet)
    {
    	std::cout<<"result: "<<m_pRet<<std::endl;
    	return 0;
    }
    return -1;
}