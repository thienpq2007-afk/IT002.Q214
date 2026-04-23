#include<iostream>
#include<cmath>
#include"TamGiac.h"
using namespace std;

/*
LamTron2: Lam tron so thuc den 2 chu so thap phan
Input: x (double)
Output: Gia tri da lam tron den 2 chu so thap phan
Thuat toan:
1. Nhan x voi 100
2. Dung ham round de lam tron
3. Chia nguoc lai cho 100.0
4. Tra ve ket qua
*/
double LamTron2(double x) {
	return round(x * 100) / 100.0;
}

/*
Nhap: Nhap 3 dinh cua tam giac
Input: Toa do 3 diem A, B, C (nhap tu ban phim)
Output: Gan gia tri cho 3 diem A, B, C
Thuat toan:
1. Thong bao nhap diem A -> goi A.Nhap()
2. Thong bao nhap diem B -> goi B.Nhap()
3. Thong bao nhap diem C -> goi C.Nhap()
*/
void cTamGiac::Nhap()
{
	cout << "Nhap A:\n";
	A.Nhap();
	cout << "Nhap B:\n";
	B.Nhap();
	cout << "Nhap C:\n";
	C.Nhap();
}

/*
Xuat: Xuat toa do 3 dinh tam giac
Input: Khong
Output: In ra toa do A, B, C
Thuat toan:
1. In diem A
2. In diem B
3. In diem C
*/
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

/*
LaTamGiac: Kiem tra 3 diem co tao thanh tam giac khong
Input: 3 diem A, B, C
Output: true neu la tam giac, false neu khong
Thuat toan:
1. Tinh do dai AB, BC, CA
2. Kiem tra dieu kien:
   - AB + BC > CA
   - AB + CA > BC
   - BC + CA > AB
3. Neu dung het -> return true, nguoc lai false
*/
bool cTamGiac::LaTamGiac()
{
	double AB = A.KhoangCach(B);
	double BC = B.KhoangCach(C);
	double CA = C.KhoangCach(A);
	return (AB + BC > CA && AB + CA > BC && BC + CA > AB);
}

/*
ChuVi: Tinh chu vi tam giac
Input: 3 diem A, B, C
Output: Chu vi (double, da lam tron 2 chu so)
Thuat toan:
1. Tinh AB, BC, CA
2. Cong 3 canh
3. Lam tron ket qua
*/
double cTamGiac::ChuVi()
{
	return LamTron2(A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A));
}

/*
DienTich: Tinh dien tich tam giac theo cong thuc Heron
Input: 3 diem A, B, C
Output: Dien tich (double, da lam tron)
Thuat toan:
1. Tinh 3 canh a, b, c
2. Tinh nua chu vi p = (a + b + c) / 2
3. Tinh dien tich S = sqrt(p*(p-a)*(p-b)*(p-c))
4. Lam tron va tra ve
*/
double cTamGiac::DienTich()
{
	double a = A.KhoangCach(B);
	double b = B.KhoangCach(C);
	double c = C.KhoangCach(A);
	double p = (a + b + c) / 2;
	return LamTron2(sqrt(p * (p - a) * (p - b) * (p - c)));
}

/*
KiemTraLoai: Xac dinh loai tam giac
Input: 3 diem A, B, C
Output: In ra loai tam giac (deu, can, thuong)
Thuat toan:
1. Tinh 3 canh a, b, c
2. Neu a == b == c -> tam giac deu
3. Neu co 2 canh bang nhau -> tam giac can
4. Nguoc lai -> tam giac thuong
*/
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

/*
TinhTien: Tinh tien tam giac theo vector (dx, dy)
Input: dx, dy (double)
Output: Cap nhat lai toa do A, B, C
Thuat toan:
1. Cong dx vao hoanh do cua A, B, C
2. Cong dy vao tung do cua A, B, C
*/
void cTamGiac::TinhTien(double dx, double dy)
{
	A.setX(A.getX() + dx);
	A.setY(A.getY() + dy);
	B.setX(B.getX() + dx);
	B.setY(B.getY() + dy);
	C.setX(C.getX() + dx);
	C.setY(C.getY() + dy);
}

/*
PhongTo: Phong to tam giac theo ti le k (so voi goc toa do)
Input: k (double)
Output: Cap nhat lai toa do A, B, C
Thuat toan:
1. Nhan hoanh do va tung do cua moi diem voi k
*/
void cTamGiac::PhongTo(double k) {
	A.setX(A.getX() * k);
	A.setY(A.getY() * k);
	B.setX(B.getX() * k);
	B.setY(B.getY() * k);
	C.setX(C.getX() * k);
	C.setY(C.getY() * k);
}

/*
ThuNho: Thu nho tam giac theo ti le k (lay trong tam lam tam)
Input: k (double, k != 0)
Output: Cap nhat lai toa do A, B, C
Thuat toan:
1. Neu k = 0 -> thong bao loi, ket thuc
2. Tinh trong tam G(xG, yG)
3. Moi diem X:
   - X' = G + (X - G) / k
4. Lam tron ket qua va cap nhat lai diem
*/
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
