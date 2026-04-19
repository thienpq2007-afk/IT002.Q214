#include<iostream>
#include "Diem.h"
using namespace std;

double cDiem::GetX()
{
    return x;
}

double cDiem::GetY()
{
    return y;
}

void cDiem::Nhap()
{
    cin >> x >> y;
}

void cDiem::Xuat()
{
    cout << "(" << x << ", " << y << ")";
}

double cDiem::KhoangCach(cDiem b)
{
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

void cDiem::TinhTien(double dx, double dy)
{
    x += dx;
    y += dy;
}

void cDiem::PhongTo(double k)
{
    x *= k;
    y *= k;
}

void cDiem::ThuNho(double k)
{
    x /= k;
    y /= k;
}

void cDiem::Quay(double goc)
{
    const double PI = 3.141592653589793;
    double rad = goc * PI / 180;
    double xMoi = x * cos(rad) - y * sin(rad);
    double yMoi = x * sin(rad) + y * cos(rad);
    x = xMoi;
    y = yMoi;
}
