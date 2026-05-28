#include "CongTy.h"

CongTy::~CongTy()
{
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
}

void CongTy::NhapDanhSach()
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int loai;
        cout << "\n1. Lap trinh vien";
        cout << "\n2. Kiem chung vien";
        cout << "\nNhap loai nhan vien: ";
        cin >> loai;
        NhanVien* nv;
        if (loai == 1)
        {
            nv = new LapTrinhVien;
        }
        else
        {
            nv = new KiemChungVien;
        }
        nv->Nhap();
        ds.push_back(nv);
    }
}

void CongTy::XuatDanhSach()
{
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Xuat();
        cout << endl;
    }
}

double CongTy::LuongTrungBinh()
{
    double tong = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        tong += ds[i]->TinhLuong();
    }
    return tong / ds.size();
}

void CongTy::NVLuongThapHonTB()
{
    double tb = LuongTrungBinh();
    cout << "\n===== NHAN VIEN LUONG THAP HON TB =====\n";
    for (int i = 0; i < ds.size(); i++)
    {
        if (ds[i]->TinhLuong() < tb)
        {
            ds[i]->Xuat();
            cout << endl;
        }
    }
}

void CongTy::NVLuongCaoNhat()
{
    int vt = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i]->TinhLuong() > ds[vt]->TinhLuong())
        {
            vt = i;
        }
    }
    cout << "\n===== NHAN VIEN LUONG CAO NHAT =====\n";
    ds[vt]->Xuat();
}

void CongTy::NVLuongThapNhat()
{
    int vt = 0;
    for (int i = 1; i < ds.size(); i++)
    {
        if (ds[i]->TinhLuong() < ds[vt]->TinhLuong())
        {
            vt = i;
        }
    }
    cout << "\n===== NHAN VIEN LUONG THAP NHAT =====\n";
    ds[vt]->Xuat();
}

void CongTy::LTVLuongCaoNhat()
{
    LapTrinhVien* max = NULL;
    for (int i = 0; i < ds.size(); i++)
    {
        LapTrinhVien* p = dynamic_cast<LapTrinhVien*>(ds[i]);
        if (p != NULL)
        {
            if (max == NULL || p->TinhLuong() > max->TinhLuong())
            {
                max = p;
            }
        }
    }
    if (max != NULL)
    {
        cout << "\n===== LAP TRINH VIEN LUONG CAO NHAT =====\n";
        max->Xuat();
    }
}

void CongTy::KCVLuongThapNhat()
{
    KiemChungVien* min = NULL;
    for (int i = 0; i < ds.size(); i++)
    {
        KiemChungVien* p = dynamic_cast<KiemChungVien*>(ds[i]);
        if (p != NULL)
        {
            if (min == NULL || p->TinhLuong() < min->TinhLuong())
            {
                min = p;
            }
        }
    }
    if (min != NULL)
    {
        cout << "\n===== KIEM CHUNG VIEN LUONG THAP NHAT =====\n";
        min->Xuat();
    }
}