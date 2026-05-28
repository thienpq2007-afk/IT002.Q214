#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Date
{
    int day, month, year;
};

class GiaoDich
{
protected:
    string maGD;
    Date ngayGD;
    double donGia;
    double dienTich;
    double thanhTien;

public:
    GiaoDich();
    virtual ~GiaoDich();
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhThanhTien() = 0;
    double GetThanhTien();
    Date GetNgayGD();
};
