#include<iostream>
#include"DaThuc.h"
using namespace std;

int main()
{
    cDaThuc A, B;

    cout << "Nhap da thuc A:\n";
    A.Nhap();

    cout << "\nNhap da thuc B:\n";
    B.Nhap();

    cout << "\nA = ";
    A.RutGon();
    A.Xuat();

    cout << "B = ";
    B.RutGon();
    B.Xuat();

    cDaThuc C = A.Cong(B);
    cout << "\nA + B = ";
    C.RutGon();
    C.Xuat();

    cDaThuc D = A.Tru(B);
    cout << "A - B = ";
    D.RutGon();
    D.Xuat();

    double x;
    cout << "\nNhap x = ";
    cin >> x;

    cout << "PA(" << x << ") = " << A.TinhGiaTri(x) << endl;
    cout << "PB(" << x << ") = " << B.TinhGiaTri(x) << endl;

    return 0;
}
