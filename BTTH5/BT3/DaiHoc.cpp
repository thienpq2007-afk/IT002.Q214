#include "DaiHoc.h"

void DaiHoc::Nhap()
{
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

void DaiHoc::Xuat()
{
    cout << "===== SINH VIEN DAI HOC =====" << endl;
    SinhVien::Xuat();
    cout << "Ten luan van: "
        << tenLuanVan << endl;
    cout << "Diem luan van: "
        << diemLuanVan << endl;
}

bool DaiHoc::TotNghiep()
{
    return tongTinChi >= 170 &&
        diemTB >= 5 &&
        diemLuanVan >= 5;
}

string DaiHoc::Loai()
{
    return "DaiHoc";
}