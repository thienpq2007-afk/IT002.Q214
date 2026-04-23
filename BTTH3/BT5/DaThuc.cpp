#include<iostream>
#include<cmath>
#include"DaThuc.h"
using namespace std;

/*
cDaThuc: Ham khoi tao co tham so
Input: size (int)
Output: Tao da thuc gom size don thuc
Thuat toan:
1. Gan n = size
2. Neu n > 0 -> cap phat mang ds
3. Nguoc lai -> ds = NULL
*/
cDaThuc::cDaThuc(int size)
{
	n = size;
	if (n > 0)
		ds = new cDonThuc[n];
	else
		ds = NULL;
}

/*
cDaThuc(copy): Ham sao chep
Input: other (cDaThuc)
Output: Tao ban sao cua da thuc
Thuat toan:
1. Gan n = other.n
2. Cap phat mang moi
3. Sao chep tung don thuc
*/
cDaThuc::cDaThuc(const cDaThuc& other)
{
	n = other.n;
	ds = new cDonThuc[n];
	for (int i = 0; i < n; i++)
		ds[i] = other.ds[i];
}

/*
operator=: Toan tu gan
Input: other (cDaThuc)
Output: Gan da thuc other cho doi tuong hien tai
Thuat toan:
1. Neu tu gan -> return
2. Giai phong bo nho cu
3. Gan n = other.n
4. Cap phat mang moi
5. Sao chep tung phan tu
6. Tra ve *this
*/
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

/*
~cDaThuc: Ham huy
Input: Khong
Output: Giai phong bo nho
Thuat toan:
1. delete[] ds
*/
cDaThuc::~cDaThuc()
{
	delete[] ds;
}

/*
Nhap: Nhap da thuc
Input: n, danh sach don thuc
Output: Gan gia tri cho da thuc
Thuat toan:
1. Nhap so don thuc n
2. Cap phat mang ds
3. Lap qua tung phan tu:
   - Nhap don thuc
*/
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

/*
RutGon: Rut gon da thuc
Input: Khong
Output: Da thuc sau khi gop cac don thuc cung so mu
Thuat toan:
1. Lap i tu 0 den n-1
2. Lap j tu i+1 den n-1
3. Neu cung so mu:
   - Cong he so
   - Dich mang trai
   - Giam n
   - j--
*/
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

/*
Xuat: Xuat da thuc
Input: Khong
Output: In da thuc dang toan hoc
Thuat toan:
1. Duyet tung don thuc
2. Bo qua he so = 0
3. In dau + giua cac don thuc
4. Neu khong co don thuc nao -> in 0
*/
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

/*
TinhGiaTri: Tinh gia tri da thuc tai x
Input: x (double)
Output: Gia tri da thuc
Thuat toan:
1. Khoi tao sum = 0
2. Cong gia tri tung don thuc
3. Tra ve sum
*/
double cDaThuc::TinhGiaTri(double x)
{
	double sum = 0; 
	for (int i = 0; i < n; i++)
	{
		sum += ds[i].TinhGiaTri(x);
	}
	return sum;
}

/*
Cong: Cong hai da thuc
Input: B (cDaThuc)
Output: Da thuc tong
Thuat toan:
1. Tao C co kich thuoc n + B.n
2. Sao chep da thuc A vao C
3. Duyet tung don thuc cua B:
   - Neu cung so mu -> cong he so
   - Neu khong -> them vao
4. Cap nhat kich thuoc
*/
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

/*
Tru: Tru hai da thuc
Input: B (cDaThuc)
Output: Da thuc hieu
Thuat toan:
1. Sao chep da thuc hien tai sang C
2. Duyet tung don thuc cua B:
   - Neu cung so mu -> tru he so
   - Neu khong -> them don thuc doi dau
3. Tra ve C
*/
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
