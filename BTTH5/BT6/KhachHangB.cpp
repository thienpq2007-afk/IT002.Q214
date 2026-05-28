#include"KhachHangB.h"
#include<fstream>

void KhachHangB::Nhap(ifstream& in)
{
    KhachHang::Nhap(in);
    in >> soNamThanThiet;
}

double KhachHangB::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;

    double khuyenMai = soNamThanThiet * 0.05;

    if (khuyenMai > 0.5)
        khuyenMai = 0.5;

    double tienSauKM = tienHang * (1 - khuyenMai);

    return tienSauKM + tienHang * 0.1;
}