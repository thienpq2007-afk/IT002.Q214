#include "SinhVien.h"

// Destructor
// Input: không có
// Output: hủy đối tượng sinh viên
SinhVien::~SinhVien()
{

}

// Nhập thông tin sinh viên
// Input: MSSV, họ tên, địa chỉ,
// tổng tín chỉ, điểm trung bình
// Output: cập nhật thông tin sinh viên
void SinhVien::Nhap()
{
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

// Xuất thông tin sinh viên
// Input: thông tin sinh viên hiện tại
// Output: hiển thị thông tin sinh viên ra màn hình
void SinhVien::Xuat()
{
    cout << "MSSV: " << mssv << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tong tin chi: " << tongTinChi << endl;
    cout << "Diem trung binh: " << diemTB << endl;
}

// Lấy điểm trung bình
// Input: không có
// Output: giá trị điểm trung bình của sinh viên
double SinhVien::GetDiemTB()
{
    return diemTB;
}
