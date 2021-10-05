#include <iostream>
#include <Windows.h>

using namespace std;

class Image
{
    int* img;
    int mx;
    int my;
public:
	
    Image(int tmx, int tmy) :mx(tmx), my(tmy)
    {
        img = new int[mx * my]();
    }
    
    virtual ~Image()
    {
        delete[] img;
    }
    
    int get(int x, int y);
    
    int set(int x, int y, int color);
    
    void show();
    
    Image& operator=(const Image& a)
    {
        int size = a.mx * a.my;
        cout << "\n";
        for (int i = 0; i < size; i++)
        {
            img[i] = a.img[i];
            mx = a.mx;
            my = a.my;
        }
    }
};

int Image::set(int x, int y, int color)
{
    try
    {
        if ((x >= mx) || (y >= my) || (x < 0) || (y < 0))
            throw 204;
        if (mx * my < y * my + x)
            throw 205;
    }
    catch (int error)
    {
        cout << "Error" << endl;
        exit(-1);
    }
    img[y * my + x] = color;
    return color;
}

int Image::get(int x, int y)
{
    try
    {
        if ((x >= mx) || (y >= my) || (x < 0) || (y < 0))
            throw 204;
        if (mx * my < y * my + x)
            throw 205;
    }
    catch (int error)
    {
        cout << "Error" << endl;
        exit(-1);
    }
    return img[y * my + x];
}

void Image::show()
{
    for (int i = 0; i < my; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            cout << img[i * my + j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Image pict(3,2);
    pict.set(0,0,0);
    pict.set(1, 0, 0);
    pict.set(1, 0, 5);
    pict.set(0, 1, 5);
    pict.set(1, 1, 5);
    pict.set(2, 1, 0);
    pict.show();
    pict.get(2, 1);
    Image pict1(3,2);
    pict1 = pict;
    pict1.show();
}
