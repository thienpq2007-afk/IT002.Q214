#include "GiaoDichDat.h"

void GiaoDichDat::Nhap()
{
    GiaoDich::Nhap();
    cout << "Nhap loai dat (A/B/C): ";
    cin >> loaiDat;
    TinhThanhTien();
}

void GiaoDichDat::TinhThanhTien()
{
    if (loaiDat == 'A')
        thanhTien = dienTich * donGia * 1.5;
    else
        thanhTien = dienTich * donGia;
}

void GiaoDichDat::Xuat()
{
    cout << "\n===== GIAO DICH DAT =====\n";
    GiaoDich::Xuat();
    cout << "Loai dat: " << loaiDat << endl;
}