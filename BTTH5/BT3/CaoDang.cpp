#include "CaoDang.h"

void CaoDang::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTN;
}

void CaoDang::Xuat()
{
    cout << "===== SINH VIEN CAO DANG =====" << endl;
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: "
        << diemThiTN << endl;
}

bool CaoDang::TotNghiep()
{
    return tongTinChi >= 120 &&
        diemTB >= 5 &&
        diemThiTN >= 5;
}

string CaoDang::Loai()
{
    return "CaoDang";
}