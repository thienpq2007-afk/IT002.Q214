#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class cDonThuc
{
private:
	double HeSo;
	int SoMu;

public:
	cDonThuc(double hs = 0, int sm = 0);
	void Nhap();
	void Xuat();
	double TinhGiaTri(double x);
	int getSoMu();
	double getHeSo();
	void setHeSo(double hs);
	void setSoMu(int sm);
};
