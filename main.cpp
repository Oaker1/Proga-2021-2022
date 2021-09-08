#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;


int main()
{
	strutils use;
	string a, str;
	cout << "Enter main string: \n";
	cin >> str;
	cout << "Enter string to find: \n";
	cin >> a;
	use.strConteins(a,str);
}
