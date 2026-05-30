#include "GiaoDichDat.h"

// Nhập thông tin giao dịch đất
// Input: thông tin giao dịch chung và loại đất (A/B/C)
// Output: cập nhật thông tin giao dịch đất
void GiaoDichDat::Nhap()
{
    GiaoDich::Nhap();
    cout << "Nhap loai dat (A/B/C): ";
    cin >> loaiDat;
    TinhThanhTien();
}

// Tính thành tiền giao dịch đất
// Input: diện tích, đơn giá, loại đất
// Output: giá trị thành tiền
// Thuật giải:
// - Loại A: thành tiền = diện tích × đơn giá × 1.5
// - Loại B hoặc C: thành tiền = diện tích × đơn giá
void GiaoDichDat::TinhThanhTien()
{
    if (loaiDat == 'A')
        thanhTien = dienTich * donGia * 1.5;
    else
        thanhTien = dienTich * donGia;
}

// Xuất thông tin giao dịch đất
// Input: thông tin giao dịch đất
// Output: hiển thị thông tin ra màn hình
void GiaoDichDat::Xuat()
{
    cout << "\n===== GIAO DICH DAT =====\n";
    GiaoDich::Xuat();
    cout << "Loai dat: " << loaiDat << endl;
}
