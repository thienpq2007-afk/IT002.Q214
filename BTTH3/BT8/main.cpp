#include<iostream>
#include<string>
#include "CongTy.h"
using namespace std;

int main()
{
    CongTy ct;
    ct.Nhap();

    cout << "\n===== DANH SACH =====\n";
    ct.Xuat();

    ct.LuongThapNhat();

    cout << "\nTong luong: " << ct.TongLuong() << endl;

    ct.TuoiCaoNhat();

    ct.SapXepTangTheoLuong();
    cout << "\n===== SAU SAP XEP =====\n";
    ct.Xuat();

    return 0;
}