#include<iostream>
#include "DaGiac.h"
using namespace std;

/*
cDaGiac(): Ham khoi tao mac dinh
Input: Khong
Output: Tao da giac rong (n = 0, A = NULL)
Thuat toan:
1. Gan n = 0
2. Gan con tro A = NULL
*/
cDaGiac::cDaGiac()
{
    n = 0;
    A = NULL;
}

/*
~cDaGiac(): Ham huy
Input: Khong
Output: Giai phong bo nho da cap phat
Thuat toan:
1. Giai phong mang dong A bang delete[]
*/
cDaGiac::~cDaGiac()
{
    delete[] A;
}

/*
cDaGiac(copy): Ham sao chep
Input: other (cDaGiac)
Output: Tao ban sao cua da giac
Thuat toan:
1. Gan n = other.n
2. Cap phat mang moi A co n phan tu
3. Sao chep tung diem tu other.A sang A
*/
cDaGiac::cDaGiac(const cDaGiac& other)
{
    n = other.n;
    A = new cDiem[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];
}

/*
operator=: Toan tu gan
Input: other (cDaGiac)
Output: Gan gia tri cua other cho doi tuong hien tai
Thuat toan:
1. Neu gan chinh no -> return
2. Giai phong bo nho cu
3. Gan n = other.n
4. Cap phat mang moi
5. Sao chep tung phan tu
6. Tra ve *this
*/
cDaGiac& cDaGiac::operator=(const cDaGiac& other)
{
    if (this == &other) return *this;

    delete[] A;

    n = other.n;
    A = new cDiem[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];

    return *this;
}

/*
Nhap: Nhap da giac
Input: n (so dinh), danh sach diem
Output: Gan gia tri cho da giac
Thuat toan:
1. Giai phong mang cu
2. Nhap so dinh n
3. Cap phat mang A gom n diem
4. Lap tu 0 den n-1:
   - Nhap tung diem A[i]
*/
void cDaGiac::Nhap()
{
    delete[] A;
    cout << "Nhap so dinh: ";
    cin >> n;

    A = new cDiem[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Dinh " << i + 1 << ": ";
        A[i].Nhap();
    }
}

/*
Xuat: Xuat da giac
Input: Khong
Output: In ra danh sach cac dinh
Thuat toan:
1. Lap qua tung diem
2. Goi Xuat() cua tung diem
*/
void cDaGiac::Xuat()
{
    for (int i = 0; i < n; i++)
    {
        A[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

/*
ChuVi: Tinh chu vi da giac
Input: Danh sach cac dinh
Output: Tong do dai cac canh
Thuat toan:
1. Khoi tao sum = 0
2. Lap i tu 0 den n-1:
   - Cong khoang cach tu A[i] den A[(i+1)%n]
3. Tra ve sum
*/
double cDaGiac::ChuVi()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i].KhoangCach(A[(i + 1) % n]);
    return sum;
}

/*
DienTich: Tinh dien tich da giac (cong thuc shoelace)
Input: Danh sach cac dinh
Output: Dien tich (double)
Thuat toan:
1. Khoi tao s = 0
2. Lap i tu 0 den n-1:
   - j = (i + 1) % n
   - Cong: x[i]*y[j] - x[j]*y[i]
3. Lay gia tri tuyet doi cua s / 2
4. Tra ve ket qua
*/
double cDaGiac::DienTich()
{
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        s += A[i].GetX() * A[j].GetY()
            - A[j].GetX() * A[i].GetY();
    }
    return abs(s) / 2;
}

/*
TinhTien: Tinh tien da giac
Input: dx, dy (double)
Output: Cap nhat tat ca dinh
Thuat toan:
1. Lap qua tung diem
2. Goi TinhTien(dx, dy) cho tung diem
*/
void cDaGiac::TinhTien(double dx, double dy)
{
    for (int i = 0; i < n; i++)
        A[i].TinhTien(dx, dy);
}

/*
PhongTo: Phong to da giac
Input: k (double)
Output: Cap nhat tat ca dinh
Thuat toan:
1. Lap qua tung diem
2. Goi PhongTo(k) cho tung diem
*/
void cDaGiac::PhongTo(double k)
{
    for (int i = 0; i < n; i++)
        A[i].PhongTo(k);
}

/*
ThuNho: Thu nho da giac
Input: k (double)
Output: Cap nhat tat ca dinh
Thuat toan:
1. Lap qua tung diem
2. Goi ThuNho(k) cho tung diem
*/
void cDaGiac::ThuNho(double k)
{
    for (int i = 0; i < n; i++)
        A[i].ThuNho(k);
}

/*
Quay: Quay da giac quanh goc toa do
Input: goc (double, do)
Output: Cap nhat tat ca dinh
Thuat toan:
1. Lap qua tung diem
2. Goi Quay(goc) cho tung diem
*/
void cDaGiac::Quay(double goc)
{
    for (int i = 0; i < n; i++)
        A[i].Quay(goc);
}
