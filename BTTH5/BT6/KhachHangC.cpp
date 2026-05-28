#include"KhachHangC.h"

double KhachHangC::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;

    return tienHang * 0.5 + tienHang * 0.1;
}