#include "cDate.h"
using namespace std;

int main()
{
    cDate d1, d2;
    cout << "Nhap ngay thu nhat:\n";
    cin >> d1;
    cout << "\nNhap ngay thu hai:\n";
    cin >> d2;
    cout << "\nNgay thu nhat: " << d1 << endl;
    cout << "Ngay thu hai: " << d2 << endl;
    cout << "\nCong 10 ngay: " << d1 + 10 << endl;
    cout << "Tru 5 ngay: " << d1 - 5 << endl;
    cout << "\n++d1 = " << ++d1 << endl;
    cout << "d1++ = " << d1++ << endl;
    cout << "Sau d1++: " << d1 << endl;
    cout << "\n--d1 = " << --d1 << endl;
    cout << "d1-- = " << d1-- << endl;
    cout << "Sau d1--: " << d1 << endl;
    cout << "\nKhoang cach giua 2 ngay: "
        << (d2 - d1) << " ngay\n";
    double tienGui, laiSuat;
    cout << "\nNhap so tien gui: ";
    cin >> tienGui;
    cout << "Nhap lai suat (%/nam): ";
    cin >> laiSuat;
    int soNgay = d2 - d1;
    double tienLai =
        tienGui * (laiSuat / 100) * soNgay / 365;
    cout << "\nSo ngay gui: " << soNgay << endl;
    cout << "Tien lai nhan duoc: "
        << tienLai << endl;

    return 0;
}
