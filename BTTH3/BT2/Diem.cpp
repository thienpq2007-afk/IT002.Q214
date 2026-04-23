#include<iostream>
#include "Diem.h"
using namespace std;

/*
GetX: Lay hoanh do cua diem
Input: Khong
Output: Gia tri hoanh do x (double)
Thuat toan:
1. Tra ve gia tri x
*/
double cDiem::GetX()
{
    return x;
}

/*
GetY: Lay tung do cua diem
Input: Khong
Output: Gia tri tung do y (double)
Thuat toan:
1. Tra ve gia tri y
*/
double cDiem::GetY()
{
    return y;
}

/*
Nhap: Nhap toa do diem
Input: x, y (nhap tu ban phim)
Output: Gan gia tri cho x va y
Thuat toan:
1. Nhap gia tri x
2. Nhap gia tri y
*/
void cDiem::Nhap()
{
    cin >> x >> y;
}

/*
Xuat: Xuat toa do diem
Input: Khong
Output: In ra toa do dang (x, y)
Thuat toan:
1. In hoanh do x
2. In tung do y
3. Dinh dang theo (x, y)
*/
void cDiem::Xuat()
{
    cout << "(" << x << ", " << y << ")";
}

/*
KhoangCach: Tinh khoang cach giua 2 diem
Input: b (cDiem)
Output: Khoang cach giua diem hien tai va diem b (double)
Thuat toan:
1. Tinh hieu hoanh do: x - b.x
2. Tinh hieu tung do: y - b.y
3. Ap dung cong thuc:
   sqrt((x - b.x)^2 + (y - b.y)^2)
4. Tra ve ket qua
*/
double cDiem::KhoangCach(cDiem b)
{
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

/*
TinhTien: Tinh tien diem theo vector (dx, dy)
Input: dx, dy (double)
Output: Cap nhat toa do moi cho diem
Thuat toan:
1. Cong dx vao x
2. Cong dy vao y
*/
void cDiem::TinhTien(double dx, double dy)
{
    x += dx;
    y += dy;
}

/*
PhongTo: Phong to diem theo ti le k (so voi goc toa do)
Input: k (double)
Output: Cap nhat toa do moi
Thuat toan:
1. Nhan x voi k
2. Nhan y voi k
*/
void cDiem::PhongTo(double k)
{
    x *= k;
    y *= k;
}

/*
ThuNho: Thu nho diem theo ti le k
Input: k (double, k != 0)
Output: Cap nhat toa do moi
Thuat toan:
1. Chia x cho k
2. Chia y cho k
*/
void cDiem::ThuNho(double k)
{
    x /= k;
    y /= k;
}

/*
Quay: Quay diem quanh goc toa do mot goc cho truoc
Input: goc (double, don vi do)
Output: Cap nhat toa do moi sau khi quay
Thuat toan:
1. Doi goc sang radian: rad = goc * PI / 180
2. Ap dung cong thuc quay:
   x' = x*cos(rad) - y*sin(rad)
   y' = x*sin(rad) + y*cos(rad)
3. Gan lai gia tri moi cho x, y
*/
void cDiem::Quay(double goc)
{
    const double PI = 3.141592653589793;
    double rad = goc * PI / 180;
    double xMoi = x * cos(rad) - y * sin(rad);
    double yMoi = x * sin(rad) + y * cos(rad);
    x = xMoi;
    y = yMoi;
}
