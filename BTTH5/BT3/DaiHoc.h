#pragma once
#include "SinhVien.h"

class DaiHoc : public SinhVien
{
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    void Nhap();
    void Xuat();
    bool TotNghiep();
    string Loai();
};
