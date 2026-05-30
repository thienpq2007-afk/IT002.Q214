#include "NhanVien.h"

// Nhập thông tin nhân viên
// Input: mã nhân viên, họ tên, tuổi,
// số điện thoại, email, lương cơ bản
// Output: cập nhật thông tin nhân viên
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

// Xuất thông tin nhân viên
// Input: thông tin nhân viên hiện tại
// Output: hiển thị thông tin nhân viên và lương
// Thuật giải:
// Gọi hàm TinhLuong() để lấy lương thực tế
// của đối tượng hiện tại (đa hình)
void NhanVien::Xuat()
{
    cout << "Ma NV: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << soDienThoai << endl;
    cout << "Email: " << email << endl;
    cout << "Luong: " << fixed << setprecision(0) << TinhLuong() << endl;
}
