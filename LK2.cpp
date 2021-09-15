#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std; 

class FooString
{
	char* buf;
	int dlina, a;
public:
	FooString(char* tbuf)
	{
	    dlina = strlen(tbuf) + 1;
		buf = new char[dlina];
		for (int i = 0; i < dlina; i++)
			buf[i] = tbuf[i];
	}
	
	~FooString()
	{
		delete[] buf;
	}
	
	void Show()
	{
	cout << buf << endl;
	}
	
	bool Compare(FooString str)
	{
		if (str.dlina != dlina)
			a = 1;
		else
		{
			for (int i = 0; i < dlina; i++)
			{
				if (buf[i] != str.buf[i])
					a = 1;
					else
					a = 0;
			} 
		}	
		if (a)
		return false;
		else return true;
	}
	
	int Test()
	{
		char str1[] = "Test";
		char str2[] = "Test2";
		FooString a(str1);
		FooString b(str2);
		if (a.Compare(b))
			cout << "Same";
		else
			cout << "Different";
	}
};

int main()
{
	char str[] = "test";
	FooString task(str);
	task.Show();
	task.Test();
}
