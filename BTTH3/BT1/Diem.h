#pragma once
#include<iostream>
using namespace std;

class cDiem
{
private:
	double x, y;

public:
	cDiem();
	cDiem(double x, double y);
	void Nhap();
	void Xuat() const;
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	double KhoangCach(const cDiem& d) const;
};
