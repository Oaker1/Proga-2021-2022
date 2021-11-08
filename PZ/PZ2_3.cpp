#include <iostream>

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
	Number num1(1);
	Number num2(3);
	std::cout << num1 << num2;
    num1 = num2;
    std:: cout << num1;
	return 0;
}
