#include <iostream>
#include <iomanip>
using namespace std;

class dynarr
{
    private:
    int* array;
    int n;

    public:

    void MakeArray()
    {
        for (int i = 0; i<n; i++) array[i] = (rand()%(10));
    }

    dynarr(int siz)
    {
	n = siz;
	array = new int[n];
        MakeArray();
    }

    ~dynarr() { delete[] array; };

    void PrintArray()
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout <<  "\n";
    }

    dynarr(dynarr &Copy)
    {
		n = Copy.n;
		array = new int[n];
		for (int i = 0; i < n; i++)
        	{
			array[i] = Copy.array[i];
		}
    }

	int GetVal(int i)
	{
		if (i > n or i < 0)
        	{
			cout << "Wrong size \n";
		}
		else cout <<"val: " << array[i] << "\n";
	}

    void SetVal(int i, int val)
    {
		if (array[i] < -100 or array[i] > 100)
        	{
			cout << "Wrong value" << endl;
		}
	    	if (i > n or i < 0)
		{
			cout << "Wrong size" << endl;
		}
		else array[i] = val;
	}

	void AddVal(int val)
	{
	if (val > -100 or val < 100)
        {
		n = n+1;
		int* newArray = new int[n];
		for (int i = 0; i < n-1; i++)
		{
			newArray[i] = array[i];
		}
		delete array;
		newArray[n-1] = val;
		array = newArray;
		}
	}

	void ArraySum(dynarr& Copy)
	{
		for (int i = 0; i < n; i++)
        	{
			array[i] = array[i] + Copy.array[i];
		}
	}

	void ArraySub(dynarr& Copy)
	{
		for (int i = 0; i < n; i++)
        	{
			array[i] = array[i] - Copy.array[i];
		}
	}

};

int main()
{
    srand(time(0));
    int size;
    cout << "Enter array size: \n" ;
    cin >> size;
    dynarr lol(size);
    lol.PrintArray();

    cout << "\nTesting SetVal func \n";
    cout << "Enter place: \n" ;
    int place;
    cin >> place;
    cout << "Enter val: \n";
    int newvalue;
    cin >> newvalue;
    lol.SetVal(place,newvalue);
    lol.PrintArray();

    cout << "\nTesting GetVal func \n";
    cout << "Enter place: \n" ;
    cin >> place;
    lol.GetVal(place);

    cout << "\nTesting AddVal func \n";
    cout << "Enter val: \n";
    cin >> newvalue;
    lol.AddVal(newvalue);
    lol.PrintArray();

    dynarr Copy(lol);
    cout << "\nTesting ArraySub func \n";
    lol.ArraySub(Copy);
    lol.PrintArray();

    cout << "\nTesting ArraySum func \n";
    lol.ArraySum(Copy);
    lol.PrintArray();
    return 0;
}
