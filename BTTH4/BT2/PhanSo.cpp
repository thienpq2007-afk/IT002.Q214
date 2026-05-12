#include "PhanSo.h"

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void PhanSo::RutGon()
{
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
}

PhanSo::PhanSo(int t, int m)
{
    tu = t;
    mau = m;

    if (mau == 0)
    {
        mau = 1;
    }

    RutGon();
}

int PhanSo::getTu() const
{
    return tu;
}

int PhanSo::getMau() const
{
    return mau;
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau + ps.tu * mau,
        mau * ps.mau
    );
}

PhanSo PhanSo::operator-(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau - ps.tu * mau,
        mau * ps.mau
    );
}

PhanSo PhanSo::operator*(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.tu,
        mau * ps.mau
    );
}

PhanSo PhanSo::operator/(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau,
        mau * ps.tu
    );
}

bool PhanSo::operator==(PhanSo& ps)
{
    return tu * ps.mau == ps.tu * mau;
}

bool PhanSo::operator>(PhanSo& ps)
{
    return tu * ps.mau > ps.tu * mau;
}

bool PhanSo::operator<(PhanSo& ps)
{
    return tu * ps.mau < ps.tu * mau;
}

istream& operator>>(istream& in, PhanSo& ps)
{
    cout << "Nhap tu so: ";
    in >> ps.tu;

    cout << "Nhap mau so: ";
    in >> ps.mau;

    while (ps.mau == 0)
    {
        cout << "Mau so phai khac 0. Nhap lai: ";
        in >> ps.mau;
    }

    ps.RutGon();

    return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps)
{
    if (ps.getMau() == 1)
        out << ps.getTu();
    else
        out << ps.getTu() << "/" << ps.getMau();

    return out;
}
