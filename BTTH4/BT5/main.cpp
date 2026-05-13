
#include "DaThuc.h"
using namespace std;

int main()
{
    DaThuc A, B;
    cout << "Nhap da thuc A:\n";
    cin >> A;
    cout << "\nNhap da thuc B:\n";
    cin >> B;
    cout << "\nDa thuc A: " << A << endl;
    cout << "Da thuc B: " << B << endl;
    cout << "\nA + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;
    cout << "A(" << x << ") = "
        << A.GiaTri(x) << endl;
    cout << "B(" << x << ") = "
        << B.GiaTri(x) << endl;
    return 0;
}
