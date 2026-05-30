#include"KhachHangC.h"

// Tính số tiền khách hàng loại C phải trả
// Input: số lượng hàng, đơn giá hàng
// Output: tổng số tiền phải thanh toán
// Thuật giải:
// - Tiền hàng = số lượng hàng × đơn giá hàng
// - Khách hàng chỉ trả 50% tiền hàng
// - Cộng thêm VAT 10% trên tiền hàng gốc
// - Tổng tiền = 50% tiền hàng + 10% tiền hàng
double KhachHangC::TinhTien()
{
    double tienHang = soLuongHang * donGiaHang;

    return tienHang * 0.5 + tienHang * 0.1;
}
