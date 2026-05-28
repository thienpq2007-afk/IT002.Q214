#include "GiaoDichNhaPho.h"

void GiaoDichNhaPho::Nhap()
{
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap loai nha (cao cap/thuong): ";
    getline(cin, loaiNha);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    TinhThanhTien();
}

void GiaoDichNhaPho::TinhThanhTien()
{
    if (loaiNha == "cao cap")
        thanhTien = dienTich * donGia;
    else
        thanhTien = dienTich * donGia * 0.9;
}

void GiaoDichNhaPho::Xuat()
{
    cout << "\n===== GIAO DICH NHA PHO =====\n";
    GiaoDich::Xuat();
    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi: " << diaChi << endl;
}