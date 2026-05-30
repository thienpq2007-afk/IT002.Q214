#include "CaoDang.h"

// Nhập thông tin sinh viên cao đẳng
// Input: mã số, họ tên, địa chỉ,
// tổng tín chỉ, điểm trung bình,
// điểm thi tốt nghiệp
// Output: cập nhật thông tin sinh viên cao đẳng
void CaoDang::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTN;
}

// Xuất thông tin sinh viên cao đẳng
// Input: thông tin sinh viên cao đẳng
// Output: hiển thị thông tin ra màn hình
void CaoDang::Xuat()
{
    cout << "===== SINH VIEN CAO DANG =====" << endl;
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: "
        << diemThiTN << endl;
}

// Kiểm tra điều kiện tốt nghiệp
// Input: tổng tín chỉ, điểm trung bình,
// điểm thi tốt nghiệp
// Output: true nếu đủ điều kiện tốt nghiệp,
// false nếu không đủ điều kiện
// Thuật giải:
// Sinh viên tốt nghiệp khi:
// - Tổng tín chỉ >= 120
// - Điểm trung bình >= 5
// - Điểm thi tốt nghiệp >= 5
bool CaoDang::TotNghiep()
{
    return tongTinChi >= 120 &&
        diemTB >= 5 &&
        diemThiTN >= 5;
}

// Trả về loại sinh viên
// Input: không có
// Output: chuỗi "CaoDang"
string CaoDang::Loai()
{
    return "CaoDang";
}
