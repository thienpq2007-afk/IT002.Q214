#include "GiaoDichCanHo.h"

void GiaoDichCanHo::Nhap()
{
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap ma can: ";
    getline(cin, maCan);
    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
    TinhThanhTien();
}

void GiaoDichCanHo::TinhThanhTien()
{
    if (viTriTang == 1)
        thanhTien = dienTich * donGia * 2;
    else if (viTriTang >= 15)
        thanhTien = dienTich * donGia * 1.2;
    else
        thanhTien = dienTich * donGia;
}

void GiaoDichCanHo::Xuat()
{
    cout << "\n===== GIAO DICH CAN HO =====\n";
    GiaoDich::Xuat();
    cout << "Ma can: " << maCan << endl;
    cout << "Vi tri tang: " << viTriTang << endl;
}