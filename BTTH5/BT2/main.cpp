#include<iostream>
#include<vector>
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichCanHo.h"
using namespace std;

int main()
{
    vector<GiaoDich*> ds;
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "\n1. Giao dich Dat";
        cout << "\n2. Giao dich Nha pho";
        cout << "\n3. Giao dich Can ho";
        cout << "\nChon loai: ";
        cin >> loai;
        GiaoDich* p = NULL;
        if (loai == 1)
            p = new GiaoDichDat;
        else if (loai == 2)
            p = new GiaoDichNhaPho;
        else
            p = new GiaoDichCanHo;
        p->Nhap();
        ds.push_back(p);
    }
    cout << "\n===== DANH SACH GIAO DICH =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Xuat();
    }
    int dat = 0;
    int nha = 0;
    int canho = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        if (dynamic_cast<GiaoDichDat*>(ds[i]))
            dat++;

        else if (dynamic_cast<GiaoDichNhaPho*>(ds[i]))
            nha++;

        else if (dynamic_cast<GiaoDichCanHo*>(ds[i]))
            canho++;
    }
    cout << "\nSo giao dich Dat: " << dat;
    cout << "\nSo giao dich Nha pho: " << nha;
    cout << "\nSo giao dich Can ho: " << canho;
    double tong = 0;
    int dem = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        GiaoDichCanHo* p = dynamic_cast<GiaoDichCanHo*>(ds[i]);
        if (p != NULL)
        {
            tong += p->GetThanhTien();
            dem++;
        }
    }
    if (dem != 0)
    {
        cout << "\nTrung binh thanh tien Can ho: "
            << tong / dem << endl;
    }
    GiaoDichNhaPho* maxNha = NULL;
    double maxTien = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        GiaoDichNhaPho* p = dynamic_cast<GiaoDichNhaPho*>(ds[i]);
        if (p != NULL)
        {
            if (p->GetThanhTien() > maxTien)
            {
                maxTien = p->GetThanhTien();
                maxNha = p;
            }
        }
    }
    if (maxNha != NULL)
    {
        cout << "\n===== NHA PHO CO TRI GIA CAO NHAT =====\n";
        maxNha->Xuat();
    }
    cout << "\n===== GIAO DICH THANG 12/2024 =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        Date d = ds[i]->GetNgayGD();
        if (d.month == 12 && d.year == 2024)
        {
            ds[i]->Xuat();
        }
    }
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }

    return 0;
}