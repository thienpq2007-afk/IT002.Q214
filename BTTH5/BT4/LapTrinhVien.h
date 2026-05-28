#pragma once
#include "NhanVien.h"

class LapTrinhVien : public NhanVien
{
private:
    int soGioOvertime;

public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};