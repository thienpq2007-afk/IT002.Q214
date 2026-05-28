#include "NhanVienVanPhong.h"

void NhanVienVanPhong::nhap() 
{
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

void NhanVienVanPhong::tinhLuong()
{
    luong = soNgayLamViec * 100000;
}

void NhanVienVanPhong::xuat() 
{
    cout << "\n--- NHAN VIEN VAN PHONG ---" << endl;

    NhanVien::xuat();

    cout << "So ngay lam viec: " << soNgayLamViec << endl;
}
