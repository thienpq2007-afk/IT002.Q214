#pragma once
#include<iostream>
using namespace std;

class cMatrix
{
private:
    int dong;
    int cot;
    double** a;

public:
    void CapPhat(int, int);
    void GiaiPhong();
    cMatrix(int = 0, int = 0);
    cMatrix(const cMatrix&);
    ~cMatrix();
    cMatrix& operator=(const cMatrix&);
    cMatrix operator+(const cMatrix&) const;
    cMatrix operator-(const cMatrix&) const;
    cMatrix operator*(const cMatrix&) const;
    double* NhanVector(double*, int) const;
    friend istream& operator>>(istream&, cMatrix&);
    friend ostream& operator<<(ostream&, const cMatrix&);
};
