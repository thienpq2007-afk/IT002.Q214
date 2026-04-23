#include<string>
#include<iostream>
#include "CongTy.h"
using namespace std;

/*
CongTy: Ham khoi tao mac dinh
Input: Khong
Output: Tao cong ty rong (ds = NULL, n = 0)
Thuat toan:
1. Gan ds = NULL
2. Gan n = 0
*/
CongTy::CongTy()
{
    ds = NULL;
    n = 0;
}

/*
~CongTy: Ham huy
Input: Khong
Output: Giai phong bo nho
Thuat toan:
1. delete[] ds
*/
CongTy::~CongTy()
{
    delete[] ds;
}

/*
Nhap: Nhap danh sach nhan vien
Input: n (so nhan vien)
Output: Tao danh sach ds gom n nhan vien
Thuat toan:
1. Nhap n
2. Cap phat mang ds gom n phan tu
3. Lap tu 0 den n-1:
   - Nhap thong tin nhan vien thu i
*/
void CongTy::Nhap()
{
    cout << "Nhap so nhan vien: ";
    cin >> n;
    ds = new cNhanVienSX[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

/*
Xuat: Xuat danh sach nhan vien
Input: Khong
Output: In ra danh sach nhan vien
Thuat toan:
1. Lap qua tung nhan vien
2. Goi Xuat()
*/
void CongTy::Xuat()
{
    for (int i = 0; i < n; i++)
        ds[i].Xuat();
}

/*
LuongThapNhat: Tim nhan vien co luong thap nhat
Input: Khong
Output: In ra nhan vien co luong thap nhat
Thuat toan:
1. Gan idx = 0
2. Lap tu 1 den n-1:
   - Neu luong nhan vien i < idx -> cap nhat idx
3. In nhan vien ds[idx]
*/
void CongTy::LuongThapNhat()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (ds[i].getLuong() < ds[idx].getLuong())
            idx = i;
    }
    cout << "\nNhan vien luong thap nhat:\n";
    ds[idx].Xuat();
}

/*
TongLuong: Tinh tong luong cong ty
Input: Khong
Output: Tong luong (double)
Thuat toan:
1. Khoi tao sum = 0
2. Lap qua tung nhan vien:
   - Cong luong vao sum
3. Tra ve sum
*/
double CongTy::TongLuong()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += ds[i].getLuong();
    return sum;
}

/*
TuoiCaoNhat: Tim nhan vien lon tuoi nhat
Input: Khong
Output: In ra nhan vien co tuoi cao nhat
Thuat toan:
1. Gan idx = 0
2. Lap tu 1 den n-1:
   - Neu nam sinh nho hon -> lon tuoi hon -> cap nhat idx
3. In ds[idx]
*/
void CongTy::TuoiCaoNhat()
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (ds[i].getNamSinh() < ds[idx].getNamSinh())
            idx = i;
    }
    cout << "\nNhan vien lon tuoi nhat:\n";
    ds[idx].Xuat();
}

/*
SapXepTangTheoLuong: Sap xep tang dan theo luong
Input: Khong
Output: Danh sach nhan vien da sap xep
Thuat toan:
1. Duyet i tu 0 den n-2
2. Duyet j tu i+1 den n-1
3. Neu luong i > luong j -> hoan vi
*/
void CongTy::SapXepTangTheoLuong()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[i].getLuong() > ds[j].getLuong())
                swap(ds[i], ds[j]);
        }
    }
}
