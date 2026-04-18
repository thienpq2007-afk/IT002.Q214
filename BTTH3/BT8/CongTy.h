#pragma once
#include "cNhanVienSX.h"

class CongTy
{
private:
    cNhanVienSX* ds;
    int n;

public:
    CongTy();
    ~CongTy();
    void Nhap();
    void Xuat();
    void LuongThapNhat();
    double TongLuong();
    void TuoiCaoNhat();
    void SapXepTangTheoLuong();
};
