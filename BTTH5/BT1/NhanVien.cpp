#include "NhanVien.h"

void NhanVien::nhap()
{
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}

void NhanVien::xuat()
{
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong: " << fixed << setprecision(0) << luong << endl;
}

double NhanVien::getLuong()
{
    return luong;
}

int NhanVien::getTuoi()
{
    string nam = ngaySinh.substr(6, 4);
    return 2026 - stoi(nam);
}

NhanVien::~NhanVien() 
{

}
