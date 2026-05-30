#include"KhachHangA.h"

// Tính số tiền khách hàng loại A phải trả
// Input: số lượng hàng, đơn giá hàng
// Output: tổng số tiền phải thanh toán
// Thuật giải:
// - Tính tiền hàng = số lượng hàng × đơn giá hàng
// - Thuế VAT = 10% tiền hàng
// - Tổng tiền = tiền hàng + VAT
double KhachHangA::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;
    return tienHang + tienHang * 0.1;
}
