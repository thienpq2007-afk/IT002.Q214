#include "cDate.h"

bool cDate::NamNhuan(int y) 
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int cDate::SoNgayTrongThang(int m, int y) 
{
    int ngayThang[] =
    {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };
    if (m == 2 && NamNhuan(y))
        return 29;

    return ngayThang[m - 1];
}

cDate::cDate(int d, int m, int y)
{
    ngay = d;
    thang = m;
    nam = y;
}

cDate cDate::operator+(int n) const
{
    cDate temp = *this;
    while (n--)
    {
        temp.ngay++;

        if (temp.ngay > temp.SoNgayTrongThang(temp.thang, temp.nam))
        {
            temp.ngay = 1;
            temp.thang++;

            if (temp.thang > 12)
            {
                temp.thang = 1;
                temp.nam++;
            }
        }
    }
    return temp;
}

cDate cDate::operator-(int n) const
{
    cDate temp = *this;
    while (n--)
    {
        temp.ngay--;
        if (temp.ngay < 1)
        {
            temp.thang--;

            if (temp.thang < 1)
            {
                temp.thang = 12;
                temp.nam--;
            }
            temp.ngay = temp.SoNgayTrongThang(temp.thang, temp.nam);
        }
    }

    return temp;
}

int cDate::operator-(const cDate& other) const
{
    cDate temp = other;
    int dem = 0;
    while (!(temp.ngay == ngay &&
        temp.thang == thang &&
        temp.nam == nam))
    {
        temp++;
        dem++;
    }
    return dem;
}

cDate& cDate::operator++()
{
    *this = *this + 1;
    return *this;
}

cDate cDate::operator++(int)
{
    cDate temp = *this;
    *this = *this + 1;
    return temp;
}

cDate& cDate::operator--()
{
    *this = *this - 1;
    return *this;
}

cDate cDate::operator--(int)
{
    cDate temp = *this;
    *this = *this - 1;
    return temp;
}

istream& operator>>(istream& in, cDate& d)
{
    cout << "Nhap ngay: ";
    in >> d.ngay;
    cout << "Nhap thang: ";
    in >> d.thang;
    cout << "Nhap nam: ";
    in >> d.nam;
    return in;
}

ostream& operator<<(ostream& out, const cDate& d)
{
    if (d.ngay < 10)
        out << "0";
    out << d.ngay << "/";
    if (d.thang < 10)
        out << "0";
    out << d.thang << "/";
    out << d.nam;
    return out;
}
