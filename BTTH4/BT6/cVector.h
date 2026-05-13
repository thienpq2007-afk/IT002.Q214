#pragma once
#include<iostream>
using namespace std;

class cVector
{
private:
    int n;          
    double* data;  

public:
    cVector(int = 0);
    cVector(const cVector&);
    ~cVector();
    cVector& operator=(const cVector&);
    cVector operator+(const cVector&) const;
    cVector operator-(const cVector&) const;
    cVector operator*(double) const;
    double operator*(const cVector&) const;
    double DoDai() const;
    friend istream& operator>>(istream&, cVector&);
    friend ostream& operator<<(ostream&, const cVector&);
};
