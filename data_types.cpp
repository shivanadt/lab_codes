#include<iostream>
using namespace std;

int main()
{
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of wide char : " << sizeof(wchar_t) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of boolean : " << sizeof(bool) << endl;
	enum colors { blue = 6, red, green, yellow} c, d;
	c = blue;
	d = red;
	cout << c <<  " "  << d <<   endl;
	return 0;
}
