#include "NhanVien.h"

// Nhập thông tin nhân viên
// Input: họ tên, ngày sinh từ bàn phím
// Output: cập nhật thông tin nhân viên
void NhanVien::nhap()
{
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}

// Xuất thông tin nhân viên
// Input: thông tin nhân viên hiện tại
// Output: hiển thị họ tên, ngày sinh và lương
void NhanVien::xuat()
{
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Luong: " << fixed << setprecision(0) << luong << endl;
}

// Lấy lương nhân viên
// Input: không có
// Output: giá trị lương của nhân viên
double NhanVien::getLuong()
{
    return luong;
}

// Tính tuổi nhân viên
// Input: ngày sinh dạng dd/mm/yyyy
// Output: tuổi của nhân viên
// Thuật giải:
// Lấy 4 ký tự cuối biểu diễn năm sinh,
// chuyển sang số nguyên rồi lấy năm hiện tại trừ năm sinh
int NhanVien::getTuoi()
{
    string nam = ngaySinh.substr(6, 4);
    return 2026 - stoi(nam);
}

// Destructor
// Input: không có
// Output: hủy đối tượng nhân viên
NhanVien::~NhanVien() 
{

}
