#include<iostream>
#include<cmath>
#include"DaThuc.h"
using namespace std;

cDaThuc::cDaThuc(int size)
{
	n = size;
	if (n > 0)
		ds = new cDonThuc[n];
	else
		ds = NULL;
}

cDaThuc::cDaThuc(const cDaThuc& other)
{
	n = other.n;
	ds = new cDonThuc[n];
	for (int i = 0; i < n; i++)
		ds[i] = other.ds[i];
}

cDaThuc& cDaThuc::operator=(const cDaThuc& other)
{
	if (this == &other) return *this;

	delete[] ds;

	n = other.n;
	ds = new cDonThuc[n];
	for (int i = 0; i < n; i++)
		ds[i] = other.ds[i];

	return *this;
}

cDaThuc::~cDaThuc()
{
	delete[] ds;
}

void cDaThuc::Nhap()
{
	cout << "Nhap so don thuc: ";
	cin >> n;
	ds = new cDonThuc[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap don thuc thu " << i + 1 << "\n";
		ds[i].Nhap();
	}
}

void cDaThuc::RutGon()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].getSoMu() == ds[j].getSoMu())
			{
				double hs = ds[i].getHeSo() + ds[j].getHeSo();
				ds[i].setHeSo(hs);
				for (int k = j; k < n - 1; k++)
					ds[k] = ds[k + 1];
				n--;
				j--; 
			}
		}
	}
}

void cDaThuc::Xuat()
{
	bool first = true; 
	for (int i = 0; i < n; i++)
	{
		if (ds[i].getHeSo() == 0) continue; 
		if (!first)
			cout << " + ";
		ds[i].Xuat();
		first = false;
	}
	if (first)
		cout << "0";
	cout << endl;
}

double cDaThuc::TinhGiaTri(double x)
{
	double sum = 0; 
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].TinhGiaTri(x);
	}
	return sum;
}

cDaThuc cDaThuc::Cong(cDaThuc B)
{
	cDaThuc C;
	C.n = n + B.n;
	C.ds = new cDonThuc[C.n];
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		C.ds[k++] = ds[i];
	}
	for (int i = 0; i < B.n; i++)
	{
		bool found = false;
		for (int j = 0; j < k; j++)
		{
			if (C.ds[j].getSoMu() == B.ds[i].getSoMu())
			{
				double hs = C.ds[i].getHeSo() + B.ds[i].getHeSo();
				C.ds[i].setHeSo(hs);
				found = true;
				break;
			}
		}
		if (!found)
		{
			C.ds[k++] = B.ds[i];
		}
	}
	C.n = k;
	return C;
}

cDaThuc cDaThuc::Tru(cDaThuc B)
{
	cDaThuc C = *this;

	for (int i = 0; i < B.n; i++)
	{
		bool found = false;
		for (int j = 0; j < C.n; j++)
		{
			if (C.ds[j].getSoMu() == B.ds[i].getSoMu())
			{
				double hs = C.ds[j].getHeSo() - B.ds[i].getHeSo();
				C.ds[j].setHeSo(hs);
				found = true;
				break;
			}
		}
		if (!found)
		{
			cDonThuc temp(-B.ds[i].getHeSo(), B.ds[i].getSoMu());
			C.ds[C.n++] = temp;
		}
	}

	return C;
}
