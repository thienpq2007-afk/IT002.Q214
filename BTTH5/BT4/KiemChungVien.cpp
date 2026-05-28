#include "KiemChungVien.h"

void KiemChungVien::Nhap()
{
    NhanVien::Nhap();
    cout << "So loi phat hien: ";
    cin >> soLoi;
}

void KiemChungVien::Xuat()
{
    cout << "\n===== KIEM CHUNG VIEN =====" << endl;
    NhanVien::Xuat();
    cout << "So loi phat hien: " << soLoi << endl;
}

double KiemChungVien::TinhLuong()
{
    return luongCoBan + soLoi * 50000;
}