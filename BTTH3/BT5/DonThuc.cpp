#include<iostream>
#include<cmath>
#include"DonThuc.h"
using namespace std;

/*
cDonThuc: Ham khoi tao co tham so
Input: hs (double - he so), sm (int - so mu)
Output: Tao don thuc voi he so va so mu
Thuat toan:
1. Gan HeSo = hs
2. Gan SoMu = sm
*/
cDonThuc::cDonThuc(double hs, int sm)
{
	HeSo = hs;
	SoMu = sm;
}

/*
Nhap: Nhap don thuc
Input: HeSo, SoMu (nhap tu ban phim)
Output: Gan gia tri cho HeSo va SoMu
Thuat toan:
1. Nhap he so
2. Nhap so mu
*/
void cDonThuc::Nhap()
{
	cout << "Nhap he so: ";
	cin >> HeSo;
	cout << "Nhap so mu: ";
	cin >> SoMu;
}

/*
Xuat: Xuat don thuc
Input: Khong
Output: In ra don thuc dang toan hoc
Thuat toan:
1. Neu HeSo = 0 -> khong in gi
2. Neu SoMu = 0 -> in HeSo
3. Neu SoMu = 1:
   - Neu HeSo != 1 -> in HeSo x
   - Nguoc lai -> in x
4. Neu SoMu > 1:
   - Neu HeSo != 1 -> in HeSo x^SoMu
   - Nguoc lai -> in x^SoMu
*/
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

/*
TinhGiaTri: Tinh gia tri don thuc tai x
Input: x (double)
Output: Gia tri cua don thuc (double)
Thuat toan:
1. Tinh x^SoMu bang pow
2. Nhan voi HeSo
3. Tra ve ket qua
*/
double cDonThuc::TinhGiaTri(double x)
{
	return HeSo * pow(x, SoMu);
}

/*
getSoMu: Lay so mu
Input: Khong
Output: Gia tri SoMu (int)
Thuat toan:
1. Tra ve SoMu
*/
int cDonThuc::getSoMu()
{
	return SoMu;
}

/*
getHeSo: Lay he so
Input: Khong
Output: Gia tri HeSo (double)
Thuat toan:
1. Tra ve HeSo
*/
double cDonThuc::getHeSo()
{
	return HeSo;
}

/*
setHeSo: Gan he so moi
Input: hs (double)
Output: Cap nhat HeSo
Thuat toan:
1. Gan HeSo = hs
*/
void cDonThuc::setHeSo(double hs)
{
	HeSo = hs;
}

/*
setSoMu: Gan so mu moi
Input: sm (int)
Output: Cap nhat SoMu
Thuat toan:
1. Gan SoMu = sm
*/
void cDonThuc::setSoMu(int sm)
{
	SoMu = sm;
}
