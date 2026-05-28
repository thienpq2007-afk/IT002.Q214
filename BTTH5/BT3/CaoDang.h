#pragma once
#include "SinhVien.h"

class CaoDang : public SinhVien
{
private:
    double diemThiTN;

public:
    void Nhap();
    void Xuat();
    bool TotNghiep();
    string Loai();
};
