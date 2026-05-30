#include "LapTrinhVien.h"

// Nhập thông tin lập trình viên
// Input: thông tin nhân viên cơ bản và số giờ làm thêm
// Output: cập nhật thông tin lập trình viên
void LapTrinhVien::Nhap()
{
    NhanVien::Nhap();
    cout << "So gio overtime: ";
    cin >> soGioOvertime;
}

// Xuất thông tin lập trình viên
// Input: thông tin lập trình viên
// Output: hiển thị thông tin ra màn hình
void LapTrinhVien::Xuat()
{
    cout << "\n===== LAP TRINH VIEN =====" << endl;
    NhanVien::Xuat();
    cout << "So gio overtime: " << soGioOvertime << endl;
}

// Tính lương lập trình viên
// Input: lương cơ bản, số giờ làm thêm
// Output: tiền lương của lập trình viên
// Thuật giải:
// Lương = lương cơ bản + số giờ overtime × 200000
double LapTrinhVien::TinhLuong()
{
    return luongCoBan + soGioOvertime * 200000;
}
