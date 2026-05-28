#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich
{
private:
    char loaiDat;

public:
    void Nhap();
    void Xuat();
    void TinhThanhTien();
};
