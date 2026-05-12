#pragma once
#include<iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;

public:
    PhanSo(int = 0, int = 1);
    void RutGon();
    int getTu() const;
    int getMau() const;
    PhanSo operator+(const PhanSo&);
    PhanSo operator-(const PhanSo&);
    PhanSo operator*(const PhanSo&);
    PhanSo operator/(const PhanSo&);
    bool operator==(PhanSo&);
    bool operator>(PhanSo&);
    bool operator<(PhanSo&);
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&, const PhanSo&);
};
