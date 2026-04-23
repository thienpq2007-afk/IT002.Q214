#include<iostream>
#include<cmath>
#include"Diem.h"

/*
cDiem(): Ham khoi tao mac dinh
Input: Khong
Output: Tao diem co toa do (0, 0)
Thuat toan:
1. Gan x = 0
2. Gan y = 0
*/
cDiem::cDiem()
{
	x = y = 0;
}

/*
cDiem(x, y): Ham khoi tao co tham so
Input: x, y (double)
Output: Tao diem co toa do (x, y)
Thuat toan:
1. Gan hoanh do x cho thuoc tinh x
2. Gan tung do y cho thuoc tinh y
*/
cDiem::cDiem(double x, double y)
{
	this->x = x;
	this->y = y;
}

/*
Nhap: Nhap toa do diem
Input: x, y (nhap tu ban phim)
Output: Gan gia tri cho x, y
Thuat toan:
1. Nhap gia tri cho x
2. Nhap gia tri cho y
*/
void cDiem::Nhap()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

/*
Xuat: Xuat toa do diem
Input: Khong
Output: In ra toa do dang (x, y)
Thuat toan:
1. In ra hoanh do x
2. In ra tung do y
3. Dinh dang theo (x, y)
*/
void cDiem::Xuat() const
{
	cout << "(" << x << ", " << y << ")" << "; ";
}

/*
getX: Lay hoanh do
Input: Khong
Output: Tra ve gia tri x
Thuat toan:
1. Tra ve x
*/
double cDiem::getX() const
{
	return x;
}

/*
getY: Lay tung do
Input: Khong
Output: Tra ve gia tri y
Thuat toan:
1. Tra ve y
*/
double cDiem::getY() const
{
	return y;
}

/*
setX: Gan hoanh do moi
Input: x (double)
Output: Cap nhat gia tri x
Thuat toan:
1. Gan gia tri moi cho x
*/
void cDiem::setX(double x)
{
	this->x = x;
}

/*
setY: Gan tung do moi
Input: y (double)
Output: Cap nhat gia tri y
Thuat toan:
1. Gan gia tri moi cho y
*/
void cDiem::setY(double y)
{
	this->y = y;
}

/*
KhoangCach: Tinh khoang cach giua 2 diem
Input: d (cDiem)
Output: Khoang cach giua diem hien tai va d (double)
Thuat toan:
1. Tinh hieu hoanh do: x - d.x
2. Tinh hieu tung do: y - d.y
3. Ap dung cong thuc:
   sqrt((x - d.x)^2 + (y - d.y)^2)
4. Tra ve ket qua
*/
double cDiem::KhoangCach(const cDiem& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
