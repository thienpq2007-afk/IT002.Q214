#pragma once
#include<iostream>
using namespace std;

class cSoPhuc
{
private:
	double thuc, ao;

public:
	cSoPhuc(double t, double a);
	cSoPhuc();

	friend istream& operator>>(istream& in, cSoPhuc& sp);
	friend ostream& operator<<(ostream& out, const cSoPhuc& sp);

	cSoPhuc operator+(const cSoPhuc& sp);
	cSoPhuc operator-(const cSoPhuc& sp);
	cSoPhuc operator*(const cSoPhuc& sp);
	cSoPhuc operator/(const cSoPhuc& sp);

	bool operator==(const cSoPhuc& sp);
	bool operator!=(const cSoPhuc& sp);
};
