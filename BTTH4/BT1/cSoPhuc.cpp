#include<iostream>
#include"cSoPhuc.h"
using namespace std;

cSoPhuc::cSoPhuc(double t, double a)
{
	thuc = t;
	ao = a;
}

cSoPhuc::cSoPhuc(){}

istream& operator>>(istream& in, cSoPhuc& sp)
{
	cout << "Nhap phan thuc: ";
	in >> sp.thuc;
	cout << "Nhap phan ao: ";
	in >> sp.ao;
	return in;
}

ostream& operator<<(ostream& out, const cSoPhuc& sp)
{
	if (sp.thuc != 0)
	{
		out << sp.thuc;
		if (sp.ao > 0)
		{
			out << " + " << sp.ao << "i";
		}
		else if (sp.ao < 0)
		{
			out << " - " << -sp.ao << "i";
		}
	}
	else
	{
		if (sp.ao > 0)
		{
			out << sp.ao << "i";
		}
		else if (sp.ao < 0)
		{
			out << sp.ao << "i";
		}
		else
			out << 0;
	}
	return out;
}

cSoPhuc cSoPhuc::operator+(const cSoPhuc& sp)
{
	return cSoPhuc(thuc + sp.thuc, ao + sp.ao);
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc& sp)
{
	return cSoPhuc(thuc - sp.thuc, ao - sp.ao);
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc& sp)
{
	return cSoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc& sp)
{
	double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
	return cSoPhuc((thuc * sp.thuc + ao * sp.ao) / mau, (ao * sp.thuc - thuc * sp.ao) / mau);
}

bool cSoPhuc::operator==(const cSoPhuc& sp)
{
	return thuc == sp.thuc && ao == sp.ao;
}

bool cSoPhuc::operator!=(const cSoPhuc& sp)
{
	return !(*this == sp);
}
