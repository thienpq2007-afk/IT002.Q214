#pragma once
#include "Diem.h"

class cDaGiac
{
private:
    cDiem* A;
    int n;

public:
    cDaGiac();
    ~cDaGiac();
    cDaGiac(const cDaGiac& other);
    cDaGiac& operator=(const cDaGiac& other);
    void Nhap();
    void Xuat();
    double ChuVi();
    double DienTich();
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double goc);
};
