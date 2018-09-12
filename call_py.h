#ifndef _CALL_PY_H_
#define _CALL_PY_H_

#include <iostream>
#include <vector>
#include <string>
#include <python2.7/Python.h>

class CallPy
{
public:
	CallPy(const char* callpyfile = NULL);
	~CallPy();
	int GetArgc(int num);
	int FeedArgv(int argv,int i);
	int FeedArgv(const char* str,int i);
	int FeedFunc(const char* funcname);

private:
	PyObject* m_pName;
	PyObject* m_pModel;
	PyObject* m_pArgc;
	std::vector<PyObject*> m_pArgvs;
	PyObject* m_pFunc;
	PyObject* m_pRet;
};

#endif