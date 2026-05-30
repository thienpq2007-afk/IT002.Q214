#include "NhanVienSanXuat.h"

// Nhập thông tin nhân viên sản xuất
// Input: họ tên, ngày sinh, lương căn bản, số sản phẩm
// Output: cập nhật thông tin nhân viên sản xuất
void NhanVienSanXuat::nhap()
{
    NhanVien::nhap();

    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;

    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

// Tính lương nhân viên sản xuất
// Input: lương căn bản, số sản phẩm
// Output: giá trị lương của nhân viên
// Thuật giải:
// Lương = lương căn bản + số sản phẩm × 5000
void NhanVienSanXuat::tinhLuong()
{
    luong = luongCanBan + soSanPham * 5000;
}

// Xuất thông tin nhân viên sản xuất
// Input: thông tin nhân viên sản xuất
// Output: hiển thị thông tin và lương ra màn hình
void NhanVienSanXuat::xuat() 
{
    cout << "\n--- NHAN VIEN SAN XUAT ---" << endl;
    NhanVien::xuat();
    cout << "Luong can ban: " << luongCanBan << endl;
    cout << "So san pham: " << soSanPham << endl;
}
