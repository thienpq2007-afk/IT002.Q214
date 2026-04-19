#include<iostream>
#include "DaGiac.h"
using namespace std;

cDaGiac::cDaGiac()
{
    n = 0;
    A = NULL;
}

cDaGiac::~cDaGiac()
{
    delete[] A;
}

cDaGiac::cDaGiac(const cDaGiac& other)
{
    n = other.n;
    A = new cDiem[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];
}

cDaGiac& cDaGiac::operator=(const cDaGiac& other)
{
    if (this == &other) return *this;

    delete[] A;

    n = other.n;
    A = new cDiem[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];

    return *this;
}

void cDaGiac::Nhap()
{
    delete[] A;
    cout << "Nhap so dinh: ";
    cin >> n;

    A = new cDiem[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Dinh " << i + 1 << ": ";
        A[i].Nhap();
    }
}

void cDaGiac::Xuat()
{
    for (int i = 0; i < n; i++)
    {
        A[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

double cDaGiac::ChuVi()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i].KhoangCach(A[(i + 1) % n]);
    return sum;
}

double cDaGiac::DienTich()
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        s += A[i].GetX() * A[j].GetY()
            - A[j].GetX() * A[i].GetY();
    }
    return abs(s) / 2;
}

void cDaGiac::TinhTien(double dx, double dy)
{
    for (int i = 0; i < n; i++)
        A[i].TinhTien(dx, dy);
}

void cDaGiac::PhongTo(double k)
{
    for (int i = 0; i < n; i++)
        A[i].PhongTo(k);
}

void cDaGiac::ThuNho(double k)
{
    for (int i = 0; i < n; i++)
        A[i].ThuNho(k);
}

void cDaGiac::Quay(double goc)
{
    for (int i = 0; i < n; i++)
        A[i].Quay(goc);
}
