#include "cMatrix.h"
using namespace std;

int main()
{
    cMatrix A, B;
    cout << "Nhap ma tran A:\n";
    cin >> A;
    cout << "\nNhap ma tran B:\n";
    cin >> B;
    cout << "\nMa tran A:\n";
    cout << A;
    cout << "\nMa tran B:\n";
    cout << B;
    cout << "\nA + B:\n";
    cout << A + B;
    cout << "\nA - B:\n";
    cout << A - B;
    cout << "\nA * B:\n";
    cout << A * B;
    int n;
    cout << "\nNhap kich thuoc vector: ";
    cin >> n;
    double* v = new double[n];
    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    double* kq = A.NhanVector(v, n);
    if (kq != nullptr)
    {
        cout << "\nA * v = (";
        for (int i = 0; i < n; i++)
        {
            cout << kq[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << ")\n";
        delete[] kq;
    }
    delete[] v;
    return 0;
}
