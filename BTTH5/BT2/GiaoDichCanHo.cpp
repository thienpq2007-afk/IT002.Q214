#include "GiaoDichCanHo.h"

// Nhập thông tin giao dịch căn hộ
// Input: thông tin giao dịch chung,
// mã căn và vị trí tầng
// Output: cập nhật thông tin giao dịch căn hộ
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

// Tính thành tiền giao dịch căn hộ
// Input: diện tích, đơn giá, vị trí tầng
// Output: giá trị thành tiền
// Thuật giải:
// - Tầng 1: thành tiền = diện tích × đơn giá × 2
// - Tầng từ 15 trở lên: thành tiền = diện tích × đơn giá × 1.2
// - Các tầng còn lại: thành tiền = diện tích × đơn giá
void GiaoDichCanHo::TinhThanhTien()
{
    if (viTriTang == 1)
        thanhTien = dienTich * donGia * 2;
    else if (viTriTang >= 15)
        thanhTien = dienTich * donGia * 1.2;
    else
        thanhTien = dienTich * donGia;
}

// Xuất thông tin giao dịch căn hộ
// Input: thông tin giao dịch căn hộ
// Output: hiển thị thông tin ra màn hình
void GiaoDichCanHo::Xuat()
{
    cout << "\n===== GIAO DICH CAN HO =====\n";
    GiaoDich::Xuat();
    cout << "Ma can: " << maCan << endl;
    cout << "Vi tri tang: " << viTriTang << endl;
}
