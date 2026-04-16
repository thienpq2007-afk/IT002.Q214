#include <iostream>
#include "TamGiac.h"
using namespace std;

int main() {
    cTamGiac tg, tg_goc1, tg_goc2, tg_goc3;
    tg.Nhap();
    if (!tg.LaTamGiac()) {
        cout << "Khong phai tam giac!\n";
        return 0;
    }

    tg_goc1 = tg_goc2 = tg_goc3 = tg;
    tg.Xuat();

    cout << "Chu vi: " << tg.ChuVi() << endl;
    cout << "Dien tich: " << tg.DienTich() << endl;

    tg.KiemTraLoai();
    
    double dx, dy;
    cout << "Nhap delta x de tinh tien: ";
    cin >> dx;
    cout << "Nhap delta y de tinh tien: ";
    cin >> dy;
    tg_goc1.TinhTien(dx, dy);
    cout << "Sau tinh tien: ";
    tg_goc1.Xuat();

    int k1;
    cout << "Nhap k de phong to k lan: ";
    cin >> k1;
    tg_goc2.PhongTo(k1);
    tg_goc2.Xuat();

    int k2;
    cout << "Nhap k de thu nho k lan: ";
    cin >> k2;
    tg_goc3.ThuNho(k2);
    tg_goc3.Xuat();

    return 0;
}
