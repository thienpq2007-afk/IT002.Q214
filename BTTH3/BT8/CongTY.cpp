#include<string>
#include<iostream>
#include "CongTy.h"
using namespace std;

CongTy::CongTy()
{
    ds = NULL;
    n = 0;
}

CongTy::~CongTy()
{
    delete[] ds;
}

void CongTy::Nhap()
{
    cout << "Nhap so nhan vien: ";
    cin >> n;
    ds = new cNhanVienSX[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void CongTy::Xuat()
{
    for (int i = 0; i < n; i++)
        ds[i].Xuat();
}

void CongTy::LuongThapNhat()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (ds[i].getLuong() < ds[idx].getLuong())
            idx = i;
    }
    cout << "\nNhan vien luong thap nhat:\n";
    ds[idx].Xuat();
}

double CongTy::TongLuong()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += ds[i].getLuong();
    return sum;
}

void CongTy::TuoiCaoNhat()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (ds[i].getNamSinh() < ds[idx].getNamSinh())
            idx = i;
    }
    cout << "\nNhan vien lon tuoi nhat:\n";
    ds[idx].Xuat();
}

void CongTy::SapXepTangTheoLuong()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].getLuong() > ds[j].getLuong())
                swap(ds[i], ds[j]);
        }
    }
}