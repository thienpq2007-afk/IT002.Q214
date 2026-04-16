#include<iostream>
#include<cmath>
#include"TamGiac.h"
using namespace std;

double LamTron2(double x) {
	return round(x * 100) / 100.0;
}

void cTamGiac::Nhap()
{
	cout << "Nhap A:\n";
	A.Nhap();
	cout << "Nhap B:\n";
	B.Nhap();
	cout << "Nhap C:\n";
	C.Nhap();
}

void cTamGiac::Xuat()
{
	cout << "A";
	A.Xuat();
	cout << "B";
	B.Xuat();
	cout << "C";
	C.Xuat();
	cout << "\n";
}

bool cTamGiac::LaTamGiac()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double CA = C.KhoangCach(A);
	return (AB + BC > CA && AB + CA > BC && BC + CA > AB);
}

double cTamGiac::ChuVi()
{
	return LamTron2(A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A));
}

double cTamGiac::DienTich()
{
	double a = A.KhoangCach(B);
	double b = B.KhoangCach(C);
	double c = C.KhoangCach(A);
	double p = (a + b + c) / 2;
	return LamTron2(sqrt(p * (p - a) * (p - b) * (p - c)));
}

void cTamGiac::KiemTraLoai()
{
	double a = A.KhoangCach(B);
	double b = B.KhoangCach(C);
	double c = C.KhoangCach(A);
	if (a == b && b == c)
	{
		cout << "Tam giac deu\n";
	}
	else if (a == b || b == c || c == a)
	{
		cout << "Tam giac can\n";
	}
	else
	{
		cout << "Tam giac thuong\n";
	}
}

void cTamGiac::TinhTien(double dx, double dy)
{
	A.setX(A.getX() + dx);
	A.setY(A.getY() + dy);
	B.setX(B.getX() + dx);
	B.setY(B.getY() + dy);
	C.setX(C.getX() + dx);
	C.setY(C.getY() + dy);
}

void cTamGiac::PhongTo(double k) {
	A.setX(A.getX() * k);
	A.setY(A.getY() * k);
	B.setX(B.getX() * k);
	B.setY(B.getY() * k);
	C.setX(C.getX() * k);
	C.setY(C.getY() * k);
}

void cTamGiac::ThuNho(double k) {
	if (k == 0) {
		cout << "k khong hop le!\n";
		return;
	}
	double xG = (A.getX() + B.getX() + C.getX()) / 3.0;
	double yG = (A.getY() + B.getY() + C.getY()) / 3.0;
	A.setX(LamTron2(xG + (A.getX() - xG) / k));
	A.setY(LamTron2(yG + (A.getY() - yG) / k));
	B.setX(LamTron2(xG + (B.getX() - xG) / k));
	B.setY(LamTron2(yG + (B.getY() - yG) / k));
	C.setX(LamTron2(xG + (C.getX() - xG) / k));
	C.setY(LamTron2(yG + (C.getY() - yG) / k));
}
