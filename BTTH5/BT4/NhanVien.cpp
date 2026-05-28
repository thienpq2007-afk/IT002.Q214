#include "NhanVien.h"

void NhanVien::Nhap()
{
    cin.ignore();
    cout << "Ma nhan vien: ";
    getline(cin, maNV);
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Tuoi: ";
    cin >> tuoi;
    cin.ignore();
    cout << "So dien thoai: ";
    getline(cin, soDienThoai);
    cout << "Email: ";
    getline(cin, email);
    cout << "Luong co ban: ";
    cin >> luongCoBan;
}

void NhanVien::Xuat()
{
    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << soDienThoai << endl;
    cout << "Email: " << email << endl;
    cout << "Luong: " << fixed << setprecision(0) << TinhLuong() << endl;
}