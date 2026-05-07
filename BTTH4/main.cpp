#include<iostream>
#include<iomanip>
#include"cSoPhuc.h"
using namespace std;

int main()
{
	cSoPhuc A, B;
	cout << "Nhap so phuc A: " << endl;
	cin >> A;
	cout << "Nhap so phuc B: " << endl;
	cin >> B;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "Tong 2 so phuc: ";
	cout << A + B << endl;
	cout << "Hieu 2 so phuc: ";
	cout << A - B << endl;
	cout << "Tich 2 so phuc : ";
	cout << A * B << endl;
	cout << "Thuong 2 so phuc: ";
	cout << setprecision(2) <<  A / B << endl;
	if (A == B)
	{
		cout << "A = B";
	}
	else
		cout << "A != B";
}
