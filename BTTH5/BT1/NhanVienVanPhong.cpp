#include "NhanVienVanPhong.h"

// Nhập thông tin nhân viên văn phòng
// Input: họ tên, ngày sinh, số ngày làm việc
// Output: cập nhật thông tin nhân viên văn phòng
void NhanVienVanPhong::nhap() 
{
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

// Tính lương nhân viên văn phòng
// Input: số ngày làm việc
// Output: giá trị lương của nhân viên
// Thuật giải:
// Lương = số ngày làm việc × 100000
void NhanVienVanPhong::tinhLuong()
{
    luong = soNgayLamViec * 100000;
}

// Xuất thông tin nhân viên văn phòng
// Input: thông tin nhân viên văn phòng
// Output: hiển thị thông tin ra màn hình
void NhanVienVanPhong::xuat() 
{
    cout << "\n--- NHAN VIEN VAN PHONG ---" << endl;

    NhanVien::xuat();

    cout << "So ngay lam viec: " << soNgayLamViec << endl;
}
