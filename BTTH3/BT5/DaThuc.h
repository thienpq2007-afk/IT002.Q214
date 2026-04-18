#pragma once
#include<iostream>
#include"DonThuc.h"
using namespace std;

class cDaThuc
{
private:
	cDonThuc* ds;
	int n;

public:
	cDaThuc(int size = 0);
	~cDaThuc();
	cDaThuc(const cDaThuc& other);      
	cDaThuc& operator=(const cDaThuc& other);
	void Nhap();
	void RutGon();
	void Xuat();
	double TinhGiaTri(double x);
	cDaThuc Cong(cDaThuc B);
	cDaThuc Tru(cDaThuc B);
};
