#pragma once
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    virtual void nhap();
    virtual void tinhLuong() = 0;
    virtual void xuat();
    double getLuong();
    virtual int getTuoi();
    virtual ~NhanVien();
};
