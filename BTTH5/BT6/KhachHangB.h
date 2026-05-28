#pragma once
#include"KhachHang.h"

class KhachHangB : public KhachHang
{
private:
    int soNamThanThiet;

public:
    void Nhap(ifstream& in);
    double TinhTien();
};
