#pragma once
#include<iostream>
using namespace std;

class cDate
{
private:
    int ngay;
    int thang;
    int nam;

public:
    bool NamNhuan(int);
    int SoNgayTrongThang(int, int);
    cDate(int = 1, int = 1, int = 2000);
    cDate operator+(int) const;
    cDate operator-(int) const;
    int operator-(const cDate&) const;
    cDate& operator++();
    cDate operator++(int);
    cDate& operator--();
    cDate operator--(int);
    friend istream& operator>>(istream&, cDate&);
    friend ostream& operator<<(ostream&, const cDate&);
};
