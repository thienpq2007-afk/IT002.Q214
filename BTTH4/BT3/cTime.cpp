#include "cTime.h"

void cTime::ChuanHoa()
{
    int tongGiay = gio * 3600 + phut * 60 + giay;
    tongGiay %= 86400;
    if (tongGiay < 0)
        tongGiay += 86400;
    gio = tongGiay / 3600;
    tongGiay %= 3600;
    phut = tongGiay / 60;
    giay = tongGiay % 60;
}

cTime::cTime(int h, int p, int s)
{
    gio = h;
    phut = p;
    giay = s;

    ChuanHoa();
}

cTime cTime::operator+(int s) const
{
    cTime temp(gio, phut, giay);

    temp.giay += s;
    temp.ChuanHoa();

    return temp;
}

cTime cTime::operator-(int s) const
{
    cTime temp(gio, phut, giay);

    temp.giay -= s;
    temp.ChuanHoa();

    return temp;
}

cTime& cTime::operator++()
{
    giay++;
    ChuanHoa();

    return *this;
}

cTime cTime::operator++(int)
{
    cTime temp = *this;

    giay++;
    ChuanHoa();

    return temp;
}

cTime& cTime::operator--()
{
    giay--;
    ChuanHoa();

    return *this;
}

cTime cTime::operator--(int)
{
    cTime temp = *this;

    giay--;
    ChuanHoa();

    return temp;
}

istream& operator>>(istream& in, cTime& t)
{
    cout << "Nhap gio: ";
    in >> t.gio;

    cout << "Nhap phut: ";
    in >> t.phut;

    cout << "Nhap giay: ";
    in >> t.giay;

    t.ChuanHoa();

    return in;
}

ostream& operator<<(ostream& out, const cTime& t)
{
    if (t.gio < 10)
        out << "0";
    out << t.gio << ":";

    if (t.phut < 10)
        out << "0";
    out << t.phut << ":";

    if (t.giay < 10)
        out << "0";
    out << t.giay;

    return out;
}
