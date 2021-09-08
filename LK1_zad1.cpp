#include <iostream>
#include <string>
using namespace std;

int main()
{
	string lastname;
	int variants;
	cout << "Enter last name \n";
	cin >> lastname;
	cout << "Enter number of variants \n";
	cin >> variants;
	cout << "Your variant is: " << (lastname.size() % variants + 1);
}
