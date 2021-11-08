#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

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
                    array[i] = 0;
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
            if (typeid(T) == typeid(int))
            {
                array[i] = val;
            }
            else cout << "Type not int \n";
        }
};

int main()
{
    int size;
    int kek;
    cout << "input size: ";
    cin >> size;
    Array<int> lol(size);
    lol.PrintArray();

    int place, val;
    cout << "input place: ";
    cin >> place;
    cout << "input val: ";
    cin >> val;
    lol.SetVal(place,val);
    lol.PrintArray();
    return 0;
}
