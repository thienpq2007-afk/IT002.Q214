#include "cMatrix.h"
#include<iomanip>

void cMatrix::CapPhat(int r, int c)
{
    dong = r;
    cot = c;

    a = new double* [dong];

    for (int i = 0; i < dong; i++)
    {
        a[i] = new double[cot];

        for (int j = 0; j < cot; j++)
        {
            a[i][j] = 0;
        }
    }
}

void cMatrix::GiaiPhong()
{
    if (a != nullptr)
    {
        for (int i = 0; i < dong; i++)
        {
            delete[] a[i];
        }

        delete[] a;
    }

    a = nullptr;
}

cMatrix::cMatrix(int r, int c)
{
    a = nullptr;

    if (r < 0)
        r = 0;

    if (c < 0)
        c = 0;

    CapPhat(r, c);
}

cMatrix::cMatrix(const cMatrix& m)
{
    dong = m.dong;
    cot = m.cot;
    a = new double* [dong];
    for (int i = 0; i < dong; i++)
    {
        a[i] = new double[cot];
        for (int j = 0; j < cot; j++)
        {
            a[i][j] = m.a[i][j];
        }
    }
}

cMatrix::~cMatrix()
{
    GiaiPhong();
}

cMatrix& cMatrix::operator=(const cMatrix& m)
{
    if (this != &m)
    {
        GiaiPhong();

        CapPhat(m.dong, m.cot);

        for (int i = 0; i < dong; i++)
        {
            for (int j = 0; j < cot; j++)
            {
                a[i][j] = m.a[i][j];
            }
        }
    }

    return *this;
}

cMatrix cMatrix::operator+(const cMatrix& m) const
{
    if (dong != m.dong || cot != m.cot)
    {
        cout << "Khong cung kich thuoc!\n";
        return cMatrix();
    }
    cMatrix kq(dong, cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            kq.a[i][j] = a[i][j] + m.a[i][j];
        }
    }
    return kq;
}

cMatrix cMatrix::operator-(const cMatrix& m) const
{
    if (dong != m.dong || cot != m.cot)
    {
        cout << "Khong cung kich thuoc!\n";
        return cMatrix();
    }
    cMatrix kq(dong, cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            kq.a[i][j] = a[i][j] - m.a[i][j];
        }
    }
    return kq;
}

cMatrix cMatrix::operator*(const cMatrix& m) const
{
    if (cot != m.dong)
    {
        cout << "Khong the nhan ma tran!\n";
        return cMatrix();
    }
    cMatrix kq(dong, m.cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            for (int k = 0; k < cot; k++)
            {
                kq.a[i][j] += a[i][k] * m.a[k][j];
            }
        }
    }
    return kq;
}

double* cMatrix::NhanVector(double* v, int n) const
{
    if (cot != n)
    {
        cout << "Khong the nhan!\n";
        return nullptr;
    }
    double* kq = new double[dong];
    for (int i = 0; i < dong; i++)
    {
        kq[i] = 0;

        for (int j = 0; j < cot; j++)
        {
            kq[i] += a[i][j] * v[j];
        }
    }
    return kq;
}

istream& operator>>(istream& in, cMatrix& m)
{
    int r, c;

    cout << "Nhap so dong: ";
    in >> r;

    cout << "Nhap so cot: ";
    in >> c;

    m.GiaiPhong();

    m.CapPhat(r, c);

    for (int i = 0; i < m.dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            in >> m.a[i][j];
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const cMatrix& m)
{
    for (int i = 0; i < m.dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            out << fixed << setprecision(2)
                << setw(8)
                << m.a[i][j];
        }
        out << endl;
    }
    return out;
}
