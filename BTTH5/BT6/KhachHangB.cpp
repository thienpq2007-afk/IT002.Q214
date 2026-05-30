#include"KhachHangB.h"
#include<fstream>

// Nhập thông tin khách hàng loại B
// Input: file input chứa thông tin khách hàng
// và số năm thân thiết
// Output: cập nhật thông tin khách hàng loại B
void KhachHangB::Nhap(ifstream& in)
{
    KhachHang::Nhap(in);
    in >> soNamThanThiet;
}

// Tính số tiền khách hàng loại B phải trả
// Input: số lượng hàng, đơn giá hàng,
// số năm thân thiết
// Output: tổng số tiền phải thanh toán
// Thuật giải:
// - Tiền hàng = số lượng hàng × đơn giá hàng
// - Mỗi năm thân thiết được giảm 5%
// - Mức giảm tối đa là 50%
// - Tiền sau khuyến mãi = tiền hàng × (1 - mức giảm)
// - Tổng tiền = tiền sau khuyến mãi + VAT 10% tiền hàng
double KhachHangB::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;

    double khuyenMai = soNamThanThiet * 0.05;

    if (khuyenMai > 0.5)
        khuyenMai = 0.5;

    double tienSauKM = tienHang * (1 - khuyenMai);

    return tienSauKM + tienHang * 0.1;
}
