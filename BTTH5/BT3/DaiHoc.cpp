#include "DaiHoc.h"

// Nhập thông tin sinh viên đại học
// Input: mã số, họ tên, địa chỉ,
// tổng tín chỉ, điểm trung bình,
// tên luận văn, điểm luận văn
// Output: cập nhật thông tin sinh viên đại học
void DaiHoc::Nhap()
{
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

// Xuất thông tin sinh viên đại học
// Input: thông tin sinh viên đại học
// Output: hiển thị thông tin ra màn hình
void DaiHoc::Xuat()
{
    cout << "===== SINH VIEN DAI HOC =====" << endl;
    SinhVien::Xuat();
    cout << "Ten luan van: "
        << tenLuanVan << endl;
    cout << "Diem luan van: "
        << diemLuanVan << endl;
}

// Kiểm tra điều kiện tốt nghiệp
// Input: tổng tín chỉ, điểm trung bình,
// điểm luận văn
// Output: true nếu đủ điều kiện tốt nghiệp,
// false nếu không đủ điều kiện
// Thuật giải:
// Sinh viên tốt nghiệp khi:
// - Tổng tín chỉ >= 170
// - Điểm trung bình >= 5
// - Điểm luận văn >= 5
bool DaiHoc::TotNghiep()
{
    return tongTinChi >= 170 &&
        diemTB >= 5 &&
        diemLuanVan >= 5;
}

// Trả về loại sinh viên
// Input: không có
// Output: chuỗi "DaiHoc"
string DaiHoc::Loai()
{
    return "DaiHoc";
}
