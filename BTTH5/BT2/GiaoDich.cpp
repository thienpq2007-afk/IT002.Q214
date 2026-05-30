#include "GiaoDich.h"

// Constructor mặc định
// Input: không có
// Output: khởi tạo thành tiền bằng 0
GiaoDich::GiaoDich()
{
    thanhTien = 0;
}

// Destructor
// Input: không có
// Output: hủy đối tượng giao dịch
GiaoDich::~GiaoDich()
{}

// Nhập thông tin giao dịch
// Input: mã giao dịch, ngày giao dịch,
// đơn giá và diện tích từ bàn phím
// Output: cập nhật thông tin giao dịch
void GiaoDich::Nhap()
{
    cin.ignore();
    cout << "Nhap ma giao dich: ";
    getline(cin, maGD);
    cout << "Nhap ngay thang nam: ";
    cin >> ngayGD.day >> ngayGD.month >> ngayGD.year;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

// Xuất thông tin giao dịch
// Input: thông tin giao dịch hiện tại
// Output: hiển thị thông tin giao dịch
void GiaoDich::Xuat()
{
    cout << "Ma GD: " << maGD << endl;
    cout << "Ngay GD: "
        << ngayGD.day << "/"
        << ngayGD.month << "/"
        << ngayGD.year << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Dien tich: " << dienTich << endl;
    cout << "Thanh tien: " << thanhTien << endl;
}

// Lấy thành tiền giao dịch
// Input: không có
// Output: giá trị thành tiền
double GiaoDich::GetThanhTien()
{
    return thanhTien;
}

// Lấy ngày giao dịch
// Input: không có
// Output: ngày giao dịch
Date GiaoDich::GetNgayGD()
{
    return ngayGD;
}
