#include<iostream>
#include<string>
#include <iomanip>
#include"cNhanVienSX.h"
using namespace std;

cNhanVienSX::cNhanVienSX()
{
	maNV = "";
	hoTen = "";
	namSinh = 0;
	soSP = 0; 
	donGia = 0;
}

void cNhanVienSX::Nhap()
{
	cin.ignore();
	cout << "Ma NV: "; getline(cin, maNV);
	cout << "Ho ten: "; getline(cin, hoTen);
	cout << "Nam sinh:"; cin >> namSinh;
	cout << "So san pham: "; cin >> soSP;
	cout << "Don gia: "; cin >> donGia;
}

void cNhanVienSX::Xuat()
{
	cout << fixed << setprecision(0);
	cout << maNV << " | " << hoTen << " | " << namSinh
		<< " | " << soSP << " | " << donGia
		<< " | Luong: " << TinhLuong() << endl;
}

double cNhanVienSX::TinhLuong()
{
	return soSP * donGia;
}

int cNhanVienSX::getNamSinh()
{
	return namSinh;
}

double cNhanVienSX::getLuong()
{
	return TinhLuong();
}