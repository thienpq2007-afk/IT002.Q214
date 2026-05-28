#include "GiaoDich.h"

GiaoDich::GiaoDich()
{
    thanhTien = 0;
}

GiaoDich::~GiaoDich()
{}

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

double GiaoDich::GetThanhTien()
{
    return thanhTien;
}

Date GiaoDich::GetNgayGD()
{
    return ngayGD;
}