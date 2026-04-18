#pragma once
#include<iostream>
#include<string>
using namespace std;

class cNhanVienSX
{
private:
	string maNV;
	string hoTen;
	int namSinh;
	int soSP;
	double donGia;

public:
	cNhanVienSX();
	void Nhap();
	void Xuat();
	double TinhLuong();
	int getNamSinh();
	double getLuong();
};
