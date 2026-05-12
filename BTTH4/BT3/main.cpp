#include "cTime.h"

using namespace std;

int main()
{
    cTime t;
    cout << "Nhap thoi gian:\n";
    cin >> t;
    cout << "\nThoi gian hien tai: " << t << endl;
    cout << "\nCong 500 giay: " << t + 500 << endl;
    cout << "Tru 100 giay: " << t - 100 << endl;
    cout << "\n++t = " << ++t << endl;
    cout << "t++ = " << t++ << endl;
    cout << "Sau t++: " << t << endl;
    cout << "\n--t = " << --t << endl;
    cout << "t-- = " << t-- << endl;
    cout << "Sau t--: " << t << endl;
    return 0;
}
