#pragma once
#include<iostream>
#include<string>
using namespace std;

class SinhVien
{
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    virtual ~SinhVien();
    virtual void Nhap();
    virtual void Xuat();
    double GetDiemTB();
    virtual bool TotNghiep() = 0;
    virtual string Loai() = 0;
};
