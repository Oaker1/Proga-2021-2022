#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

class Protocol
{
    public:
	    virtual void send(char *buf, int len){};
};

class HexProtocol:public Protocol
{
    public:
	    void send(char *buf, int len)
	{
		for (int i = 0; buf[i] != '\0'; i++)
			cout << "0x" << hex << (int)(buf[i] & 0xff) << ' ';
	}
};

class BinaryProtocol:public Protocol
{
public:
	void send(char* buf, int len)
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
		{
			bitset<8> x(buf[i]);
			cout << x << ' ';
		}
	}
};

void sendAll(Protocol **a, int protocols_num)
{
	char strng[50];
	cout << "Enter string" << "\n" ;
	cin >> strng;
	for (int i = 0; i < protocols_num; i++)
	{
		cout << "Line " << i + 1 << ": ";
		a[i]->send(strng, 50);
		cout << endl;
	}
}

void readFile()
{
	string text = "task3.txt", line;
	vector <string> protocols;
	fstream file;
	file.open(text);
	
	while (file >> line)
	{
		protocols.push_back(line);
	}
	file.close();

	Protocol **a = new Protocol *[protocols.size()];
	for (int i = 0; i < protocols.size(); i++)
	{
		if(protocols[i] == "HexProtocol")
        {
            a[i] = new HexProtocol;
        } 
		else if(protocols[i] == "BinaryProtocol")
        {
            a[i] = new BinaryProtocol;
        } 
        else
        {
            cout << "Cant read file, make sure to use either HexProtocol or BinaryProtocol";
            exit(0);
        }
	}
	sendAll(a, protocols.size());
	delete[] a;
}

int main()
{
	readFile();
}
