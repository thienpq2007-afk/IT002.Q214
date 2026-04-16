#pragma once
#include<iostream>
#include"Diem.h"
using namespace std;

class cTamGiac
{
private:
	cDiem A, B, C;

public:
	void Nhap();
	void Xuat();
	double ChuVi();
	double DienTich();
	bool LaTamGiac();
	void KiemTraLoai();
	void TinhTien(double dx, double dy);
	void PhongTo(double k);
	void ThuNho(double k);
};

