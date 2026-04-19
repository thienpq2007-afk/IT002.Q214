#include "DaGiac.h"
#include<iostream>
using namespace std;

int main()
{
    cDaGiac P;
    P.Nhap();
    cDaGiac A = P;
    cDaGiac B = P;
    cDaGiac C = P;

    cout << "\nDa giac: ";
    P.Xuat();

    cout << "Chu vi: " << P.ChuVi() << endl;
    cout << "Dien tich: " << P.DienTich() << endl;

    double dx, dy;
    cout << "\nNhap dx, dy de da giac tinh tien: ";
    cin >> dx >>  dy;
    P.TinhTien(dx, dy);
    cout << "Sau tinh tien: ";
    P.Xuat();

    int k1;
    cout << "\nNhap k de phong to k lan: ";
    cin >> k1;
    A.PhongTo(k1);
    cout << "Sau khi phong to: ";
    A.Xuat();

    int k2;
    cout << "\nNhap k de thu nho k lan: ";
    cin >> k2;
    B.ThuNho(k2);
    cout << "Sau khi thu nho: ";
    B.Xuat();

    double goc;
    cout << "\nNhap goc de quay: ";
    cin >> goc;
    C.Quay(goc);
    cout << "Sau quay: ";
    C.Xuat();

    return 0;
}
