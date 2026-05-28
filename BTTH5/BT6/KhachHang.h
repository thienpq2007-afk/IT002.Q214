#pragma once
#include<iostream>
#include<string>
using namespace std;

class KhachHang
{
protected:
    string tenKhachHang;
    int soLuongHang;
    double donGiaHang;

public:
    virtual ~KhachHang() {}
    virtual void Nhap(ifstream& in);
    virtual double TinhTien() = 0;
    virtual void Xuat(ofstream& out);
};