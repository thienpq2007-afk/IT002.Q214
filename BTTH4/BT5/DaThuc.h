#pragma once
#include<iostream>
using namespace std;

class DaThuc
{
private:
    int bac;
    double* heSo;

public:
    void ToiUu();
    DaThuc(int = 0);
    DaThuc(const DaThuc&);
    ~DaThuc();
    DaThuc& operator=(const DaThuc&);
    DaThuc operator+(const DaThuc&) const;
    DaThuc operator-(const DaThuc&) const;
    DaThuc operator*(const DaThuc&) const;
    double GiaTri(double) const;
    friend istream& operator>>(istream&, DaThuc&);
    friend ostream& operator<<(ostream&, const DaThuc&);
};
