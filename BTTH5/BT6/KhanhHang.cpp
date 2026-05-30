#include"KhachHang.h"
#include<fstream>

// Nhập thông tin khách hàng từ file
// Input: luồng file input chứa:
// tên khách hàng, số lượng hàng, đơn giá hàng
// Output: cập nhật thông tin khách hàng
void KhachHang::Nhap(ifstream& in)
{
    in.ignore();
    getline(in, tenKhachHang);
    in >> soLuongHang;
    in >> donGiaHang;
}

// Xuất thông tin khách hàng ra file
// Input: thông tin khách hàng hiện tại
// Output: ghi tên khách hàng và số tiền phải trả vào file
// Thuật giải:
// Ghi tên khách hàng ra file,
// sau đó gọi TinhTien() để tính và ghi tổng tiền
// (sử dụng đa hình nếu TinhTien() là hàm ảo)
void KhachHang::Xuat(ofstream& out)
{
    out << tenKhachHang << endl;
    out << TinhTien() << endl;
}
