#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class cDiem
{
private:
    double x, y;

public:
    void Nhap();
    void Xuat();
    double GetX();
    double GetY();
    double KhoangCach(cDiem b);
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double goc);
};
