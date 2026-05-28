#include<iostream>
#include<vector>
#include "CaoDang.h"
#include "DaiHoc.h"
using namespace std;

int main()
{
    vector<SinhVien*> ds;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "\n1. Cao dang";
        cout << "\n2. Dai hoc";
        cout << "\nChon loai sinh vien: ";
        cin >> loai;
        SinhVien* sv;
        if (loai == 1)
        {
            sv = new CaoDang;
        }
        else
        {
            sv = new DaiHoc;
        }
        sv->Nhap();
        ds.push_back(sv);
    }
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Xuat();
        cout << endl;
    }
    cout << "\n===== SINH VIEN DU DIEU KIEN TOT NGHIEP =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->TotNghiep())
        {
            ds[i]->Xuat();
            cout << endl;
        }
    }
    cout << "\n===== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (!ds[i]->TotNghiep())
        {
            ds[i]->Xuat();
            cout << endl;
        }
    }
    double maxDH = -1;
    double maxCD = -1;
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->Loai() == "DaiHoc")
        {
            if (ds[i]->GetDiemTB() > maxDH)
            {
                maxDH = ds[i]->GetDiemTB();
            }
        }
        if (ds[i]->Loai() == "CaoDang")
        {
            if (ds[i]->GetDiemTB() > maxCD)
            {
                maxCD = ds[i]->GetDiemTB();
            }
        }
    }
    cout << "\n===== SINH VIEN DAI HOC CO DTB CAO NHAT =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->Loai() == "DaiHoc" &&
            ds[i]->GetDiemTB() == maxDH)
        {
            ds[i]->Xuat();
            cout << endl;
        }
    }
    cout << "\n===== SINH VIEN CAO DANG CO DTB CAO NHAT =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->Loai() == "CaoDang" &&
            ds[i]->GetDiemTB() == maxCD)
        {
            ds[i]->Xuat();
            cout << endl;
        }
    }
    int rotCD = 0;
    int rotDH = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->Loai() == "CaoDang" &&
            !ds[i]->TotNghiep())
        {
            rotCD++;
        }

        if (ds[i]->Loai() == "DaiHoc" &&
            !ds[i]->TotNghiep())
        {
            rotDH++;
        }
    }
    cout << "\nSo SV cao dang khong tot nghiep: "
        << rotCD << endl;
    cout << "So SV dai hoc khong tot nghiep: "
        << rotDH << endl;
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    return 0;
}