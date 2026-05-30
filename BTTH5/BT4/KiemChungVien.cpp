#include "KiemChungVien.h"

// Nhập thông tin kiểm chứng viên
// Input: thông tin nhân viên cơ bản và số lỗi phát hiện
// Output: cập nhật thông tin kiểm chứng viên
void KiemChungVien::Nhap()
{
    NhanVien::Nhap();
    cout << "So loi phat hien: ";
    cin >> soLoi;
}

// Xuất thông tin kiểm chứng viên
// Input: thông tin kiểm chứng viên
// Output: hiển thị thông tin ra màn hình
void KiemChungVien::Xuat()
{
    cout << "\n===== KIEM CHUNG VIEN =====" << endl;
    NhanVien::Xuat();
    cout << "So loi phat hien: " << soLoi << endl;
}

// Tính lương kiểm chứng viên
// Input: lương cơ bản, số lỗi phát hiện
// Output: tiền lương của kiểm chứng viên
// Thuật giải:
// Lương = lương cơ bản + số lỗi phát hiện × 50000
double KiemChungVien::TinhLuong()
{
    return luongCoBan + soLoi * 50000;
}
