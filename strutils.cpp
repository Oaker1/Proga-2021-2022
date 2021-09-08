#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;
int strConteins(string a, string str)
{
	if (str.find(a))
	{
		cout << "Found";
		return 1;
	}
	else
	{
		cout << "Not found";
		return -1;
	}	
	
}
