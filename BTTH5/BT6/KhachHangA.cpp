#include"KhachHangA.h"

double KhachHangA::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;
    return tienHang + tienHang * 0.1;
}