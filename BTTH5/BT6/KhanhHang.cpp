#include"KhachHang.h"
#include<fstream>

void KhachHang::Nhap(ifstream& in)
{
    in.ignore();
    getline(in, tenKhachHang);
    in >> soLuongHang;
    in >> donGiaHang;
}

void KhachHang::Xuat(ofstream& out)
{
    out << tenKhachHang << endl;
    out << TinhTien() << endl;
}