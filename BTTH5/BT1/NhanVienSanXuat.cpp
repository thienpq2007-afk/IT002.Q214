#include "NhanVienSanXuat.h"

void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();

    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;

    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NhanVienSanXuat::tinhLuong()
{
    luong = luongCanBan + soSanPham * 5000;
}

void NhanVienSanXuat::xuat() 
{
    cout << "\n--- NHAN VIEN SAN XUAT ---" << endl;
    NhanVien::xuat();
    cout << "Luong can ban: " << luongCanBan << endl;
    cout << "So san pham: " << soSanPham << endl;
}
