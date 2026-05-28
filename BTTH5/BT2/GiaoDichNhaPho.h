#pragma once
#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich
{
private:
    string loaiNha;
    string diaChi;

public:
    void Nhap();
    void Xuat();
    void TinhThanhTien();
};