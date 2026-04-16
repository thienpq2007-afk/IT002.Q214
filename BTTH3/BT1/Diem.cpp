#include<iostream>
#include<cmath>
#include"Diem.h"

cDiem::cDiem()
{
	x = y = 0;
}

cDiem::cDiem(double x, double y)
{
	this->x = x;
	this->y = y;
}

void cDiem::Nhap()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}

void cDiem::Xuat() const
{
	cout << "(" << x << ", " << y << ")" << "; ";
}

double cDiem::getX() const
{
	return x;
}

double cDiem::getY() const
{
	return y;
}

void cDiem::setX(double x)
{
	this->x = x;
}

void cDiem::setY(double y)
{
	this->y = y;
}

double cDiem::KhoangCach(const cDiem& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
