#include <iostream>
#include <iomanip>
using namespace std;

class dynarr
{
    private:
    int* array, n;

    public:

    void MakeArray()
    {
        for (int i = 0; i<n; i++) array[i] = (rand()%(10));
    }

    dynarr(int size)
    {
        n = size;
        try
        {
            array = new int[n];
        }
        catch (bad_alloc &er)
        {
            cerr << "bad_alloc caught: " << er.what() << '\n';
        }
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

	int GetVal(int i)
	{
        if (i>n)
        {
            try
            {
                throw out_of_range("Out of range \n");
            }
            catch (out_of_range &error)
            {
                cout << error.what();
            }
        }
        else cout <<"val: " << array[i] << "\n";
	}

    void SetVal(int i, int val)
    {
		if (val < -100 or val > 100)
        {
			try
			{
			    throw invalid_argument("Invalid argument \n");
            }
            catch(invalid_argument &o)
            {
                cout << o.what();
            }
		}
		else array[i] = val;
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
    lol.GetVal(size+1);
    lol.SetVal(3, 110);
    return 0;
}
