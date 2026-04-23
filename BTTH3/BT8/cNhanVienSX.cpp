#include<iostream>
#include<string>
#include <iomanip>
#include"cNhanVienSX.h"
using namespace std;

/*
cNhanVienSX: Ham khoi tao mac dinh
Input: Khong
Output: Tao nhan vien voi gia tri mac dinh
Thuat toan:
1. Gan maNV = ""
2. Gan hoTen = ""
3. Gan namSinh = 0
4. Gan soSP = 0
5. Gan donGia = 0
*/
cNhanVienSX::cNhanVienSX()
{
	maNV = "";
	hoTen = "";
	namSinh = 0;
	soSP = 0; 
	donGia = 0;
}

/*
Nhap: Nhap thong tin nhan vien san xuat
Input: maNV, hoTen, namSinh, soSP, donGia
Output: Gan gia tri cho cac thuoc tinh
Thuat toan:
1. Bo qua ky tu xuong dong truoc do (cin.ignore)
2. Nhap maNV bang getline
3. Nhap hoTen bang getline
4. Nhap namSinh
5. Nhap soSP
6. Nhap donGia
*/
void cNhanVienSX::Nhap()
{
	cin.ignore();
	cout << "Ma NV: "; getline(cin, maNV);
	cout << "Ho ten: "; getline(cin, hoTen);
	cout << "Nam sinh:"; cin >> namSinh;
	cout << "So san pham: "; cin >> soSP;
	cout << "Don gia: "; cin >> donGia;
}

/*
Xuat: Xuat thong tin nhan vien
Input: Khong
Output: In ra thong tin nhan vien va luong
Thuat toan:
1. Dinh dang so khong lay phan thap phan
2. In maNV, hoTen, namSinh, soSP, donGia
3. Goi ham TinhLuong de in luong
*/
void cNhanVienSX::Xuat()
{
	cout << fixed << setprecision(0);
	cout << maNV << " | " << hoTen << " | " << namSinh
		<< " | " << soSP << " | " << donGia
		<< " | Luong: " << TinhLuong() << endl;
}

/*
TinhLuong: Tinh luong nhan vien
Input: Khong
Output: Luong (double)
Thuat toan:
1. Luong = soSP * donGia
2. Tra ve ket qua
*/
double cNhanVienSX::TinhLuong()
{
	return soSP * donGia;
}

/*
getNamSinh: Lay nam sinh
Input: Khong
Output: Gia tri namSinh (int)
Thuat toan:
1. Tra ve namSinh
*/
int cNhanVienSX::getNamSinh()
{
	return namSinh;
}

/*
getLuong: Lay luong nhan vien
Input: Khong
Output: Luong (double)
Thuat toan:
1. Goi ham TinhLuong()
2. Tra ve ket qua
*/
double cNhanVienSX::getLuong()
{
	return TinhLuong();
}
