#include "cVector.h"
#include<cmath>
#include<iomanip>

cVector::cVector(int size)
{
    if (size < 0)
        size = 0;
    n = size;
    data = new double[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = 0;
    }
}

cVector::cVector(const cVector& v)
{
    n = v.n;
    data = new double[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = v.data[i];
    }
}

cVector::~cVector()
{
    delete[] data;
}

cVector& cVector::operator=(const cVector& v)
{
    if (this != &v)
    {
        delete[] data;
        n = v.n;
        data = new double[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = v.data[i];
        }
    }
    return *this;
}

cVector cVector::operator+(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return cVector();
    }
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] + v.data[i];
    }
    return kq;
}

cVector cVector::operator-(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return cVector();
    }
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] - v.data[i];
    }
    return kq;
}

cVector cVector::operator*(double k) const
{
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] * k;
    }
    return kq;
}

double cVector::operator*(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return 0;
    }
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += data[i] * v.data[i];
    }
    return tong;
}

double cVector::DoDai() const
{
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += data[i] * data[i];
    }
    return sqrt(tong);
}

istream& operator>>(istream& in, cVector& v)
{
    cout << "Nhap so chieu: ";
    in >> v.n;
    if (v.n < 0)
        v.n = 0;
    delete[] v.data;
    v.data = new double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        cout << "Phan tu [" << i << "]: ";
        in >> v.data[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const cVector& v)
{
    out << "(";
    for (int i = 0; i < v.n; i++)
    {
        out << fixed << setprecision(2)
            << v.data[i];
        if (i != v.n - 1)
        {
            out << ", ";
        }
    }
    out << ")";
    return out;
}
