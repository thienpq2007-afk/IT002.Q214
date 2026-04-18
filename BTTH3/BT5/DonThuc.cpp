#include<iostream>
#include<cmath>
#include"DonThuc.h"
using namespace std;

cDonThuc::cDonThuc(double hs, int sm)
{
	HeSo = hs;
	SoMu = sm;
}

void cDonThuc::Nhap()
{
	cout << "Nhap he so: ";
	cin >> HeSo;
	cout << "Nhap so mu: ";
	cin >> SoMu;
}

void cDonThuc::Xuat()
{
	if (HeSo == 0) return;
	if (SoMu == 0)
	{
		cout << HeSo;
	}
	else if (SoMu == 1)
	{
		if (HeSo != 1)
		{
			cout << HeSo << "x";
		}
		else
		{
			cout << "x";
		}
	}
	else
	{
		if (HeSo != 1)
		{
			cout << HeSo << "x" << SoMu;
		}
		else
		{
			cout << "x" << SoMu;
		}
	}
}

double cDonThuc::TinhGiaTri(double x)
{
	return HeSo * pow(x, SoMu);
}

int cDonThuc::getSoMu()
{
	return SoMu;
}

double cDonThuc::getHeSo()
{
	return HeSo;
}

void cDonThuc::setHeSo(double hs)
{
	HeSo = hs;
}

void cDonThuc::setSoMu(int sm)
{
	SoMu = sm;
}
