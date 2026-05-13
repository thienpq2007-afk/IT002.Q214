#include "cVector.h"

using namespace std;

int main()
{
    cVector a, b;
    cout << "Nhap vector A:\n";
    cin >> a;
    cout << "\nNhap vector B:\n";
    cin >> b;
    cout << "\nVector A: " << a << endl;
    cout << "Vector B: " << b << endl;
    cout << "\nA + B = " << a + b << endl;
    cout << "A - B = " << a - b << endl;
    cout << "A * 2 = " << a * 2 << endl;
    cout << "Tich vo huong A * B = "
        << (a * b) << endl;
    cout << "\n|A| = " << a.DoDai() << endl;
    cout << "|B| = " << b.DoDai() << endl;
    return 0;
}
