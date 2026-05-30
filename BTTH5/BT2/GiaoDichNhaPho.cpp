#include "GiaoDichNhaPho.h"

// Nhập thông tin giao dịch nhà phố
// Input: thông tin giao dịch chung,
// loại nhà và địa chỉ
// Output: cập nhật thông tin giao dịch nhà phố
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

// Tính thành tiền giao dịch nhà phố
// Input: diện tích, đơn giá, loại nhà
// Output: giá trị thành tiền
// Thuật giải:
// - Nhà cao cấp: thành tiền = diện tích × đơn giá
// - Nhà thường: thành tiền = diện tích × đơn giá × 0.9
void GiaoDichNhaPho::TinhThanhTien()
{
    if (loaiNha == "cao cap")
        thanhTien = dienTich * donGia;
    else
        thanhTien = dienTich * donGia * 0.9;
}

// Xuất thông tin giao dịch nhà phố
// Input: thông tin giao dịch nhà phố
// Output: hiển thị thông tin ra màn hình
void GiaoDichNhaPho::Xuat()
{
    cout << "\n===== GIAO DICH NHA PHO =====\n";
    GiaoDich::Xuat();
    cout << "Loai nha: " << loaiNha << endl;
    cout << "Dia chi: " << diaChi << endl;
}
