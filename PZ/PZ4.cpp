#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void Map()
{
    map<string, int> stringmap;
    string object;
    string zapas = "";
    getline(cin, object);
    int i = 0;
    while (i < object.length())
    {
        while ((object[i] != ' ') and (i != object.length()))
        {
            zapas.push_back(object[i]);
            i++;
        }
        stringmap[zapas]++;
        zapas.clear();
        i++;
    }
    map<string, int>::iterator it;
    it = stringmap.begin();
    for (int j = 0; it != stringmap.end(); it++, j++)
    {
        cout << "String " << it->first << " - Total " << it->second << "\n";
    }
}

void Vector()
{
    int v1, v2;
    cout << "Enter vectors lengths"
         << "\n";
    cin >> v1 >> v2;
    if (v1 < 1 or v2 < 1)
    {
        cout << ("Bad length");
    }
    else
    {
        vector<int> vect1(v1);
        vector<int> vect2(v2);
        float sredn_ar1(0), sredn_ar2(0);

        for (int i = 0; i < v1; i++)
        {
            vect1[i] = rand() % 101 - 100;
            cout << vect1[i] << " ";
        }
        cout << "\n";

        for (int i = 0; i < v2; i++)
        {
            vect2[i] = rand() % 101 - 100;
            cout << vect2[i] << " ";
        }
        cout << "\n";

        for (int i = 0; i < v1; i++)
        {
            sredn_ar1 += vect1[i];
        }
        sredn_ar1 = sredn_ar1 / v1;
        cout << sredn_ar1 << "\n";

        for (int i = 0; i < v2; i++)
        {
            sredn_ar2 += vect2[i];
        }
        sredn_ar2 = sredn_ar2 / v2;
        cout << sredn_ar2 << "\n";

        if (v1 > v2)
        {
            for (int i = 0; i < v1; i++)
            {
                for (int j = i; j < v2; j++)
                {
                    if (vect1[i] == vect2[j])
                    {
                        cout << vect1[i] << " ";
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < v2; i++)
            {
                for (int j = i; j < v1; j++)
                {
                    if (vect2[i] == vect1[j])
                    {
                        cout << vect2[i] << " ";
                    }
                }
            }
        }
    }
    cout << "\n";
}

int main()
{
    srand(time(NULL));
    Map();
    Vector();

    return 0;
}
