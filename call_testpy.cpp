#include "call_py.h"

int main(int argc,char* argv)
{
	CallPy *callpy = new CallPy("test");
	if(!callpy)
	{
		std::cout<<"init call fasiled."<<std::endl;
		return -1;
	}

	callpy->GetArgc(1);
	callpy->FeedArgv("/home/e0028/workspace/tensorflow_study/facenet/dataset",0);
	callpy->FeedFunc("get_dataset");
	std::cout<<"end-----------"<<std::endl;
	return 0;
}