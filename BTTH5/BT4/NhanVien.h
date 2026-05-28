#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class NhanVien
{
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string soDienThoai;
    string email;
    double luongCoBan;

public:
    virtual ~NhanVien() {}
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
};