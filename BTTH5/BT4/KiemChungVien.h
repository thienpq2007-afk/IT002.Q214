#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien
{
private:
    int soLoi;

public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};