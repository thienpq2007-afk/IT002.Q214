#include<iostream>
#include<string>
using namespace std;

struct ThongTinHocSinh
{
	string Hoten;
	float DiemToan;
	float DiemVan;
};

void Nhap(ThongTinHocSinh& x)
{
	getline(cin, x.Hoten);
	cin >> x.DiemToan >> x.DiemVan;
}

void Xuat(ThongTinHocSinh x)
{
	float DTB = (x.DiemToan + x.DiemVan) / 2;

	cout << x.Hoten << "\t";
	cout << x.DiemToan << "\t";
	cout << x.DiemVan << "\t";
	cout << DTB;
}

int main()
{
	ThongTinHocSinh x;

	Nhap(x);
	Xuat(x);

	return 0;
}
