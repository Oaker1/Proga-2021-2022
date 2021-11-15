#include <iostream>
#include <iomanip>
#include <typeinfo>
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

	int GetVal(int i)
	{
        if (i>=n)
        {
            throw out_of_range("Out of range \n");
        }
        else cout <<"val: " << array[i] << "\n";
	}

    void SetVal(int i, int val)
    {
		if (val < -100 or val > 100)
        {
			    throw invalid_argument("Invalid argument \n");
		}
		if (i >= n)
		{
            cout << "Wrong size" << endl;
		}
		else array[i] = val;
	}
};

template <class T>
class Array
{
    private:
        T* array;
        int n;

    public:

        Array(int size)
        {
            array = new T[size];
            n = size;
            if (typeid(T) == typeid(int))
            {
                for (int i = 0; i<n; i++)
                {
                    array[i] = (rand()%(10));
                }
            }
        };

        Array(Array &Copy)
        {
            n = Copy.n;
            array = new T[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = Copy.array[i];
            }
        }

        ~Array(){delete[] array;};

        void PrintArray()
        {
            for (int i = 0; i < n; i++)
            {
                cout << array[i] << " ";
            }
            cout <<  "\n";
        }

        void SetVal(int i, int val)
        {
            if (typeid(T) == typeid(int) && (i<n) && (i>=0))
            {
                array[i] = val;
            }
            else cout << "Type not int or wrong place \n";
        }

        void distance(Array& ar1, Array& ar2)
        {
            if (typeid(T) == typeid(int))
            {
                cout << "vector: ";
                for(int i=0; i<n; i++)
                cout << ar1.array[i]-ar2.array[i] << " ";
            }
            else
            {
                throw std::logic_error("logic failure");
            }
        }
};

class Number
{
private:
	int num;

public:
	  Number(int val) { num = val; }
    Number(const Number &copy) :
        num(copy.num){}

    Number& operator= (const Number &number);

    friend std::ostream& operator<<(std::ostream &out, const Number &number);

    friend void swap(const Number &lhs, const Number &rhs);

};

std::ostream& operator<< (std::ostream &out, const Number &number)
{
    out << number.num << ", ";
    return out;
}

Number& Number::operator= (const Number &val)
{
    num = val.num+1;

    return *this;
}


int main()
{
    srand(time(0));
    int size;
    cout << "Enter array size: \n" ;
    cin >> size;
    dynarr lol(size);

    try
    {
        dynarr lol(size);
    }
    catch (bad_alloc &er)
    {
        cerr << "bad_alloc caught: " << er.what() << '\n';
        exit(0);
    }
    lol.PrintArray();

    try
    {
        lol.SetVal(size-1, 99);
    }
    catch(invalid_argument &o)
    {
        cout << o.what();
        exit(0);
    }

    try
    {
        lol.GetVal(size-1);
    }
    catch(invalid_argument &o)
    {
        cout << o.what();
        exit(0);
    }

    int size2, place2,val2;
    cout << "input size: ";
    cin >> size2;
    Array<int> kek(size2);
    cout << "input place: ";
    cin >> place2;
    cout << "input val: ";
    cin >> val2;
    kek.SetVal(place2,val2);
    kek.PrintArray();

    Number num1(1);
	  Number num2(3);
	  cout << num1 << num2;
    num1 = num2;
    cout << num1 << "\n";

    Array<int> kek2(size2);
    try
    {
        kek.distance(kek, kek2);
    }
    catch(logic_error &o)
    {
        cout << o.what();
    }
    return 0;
}
