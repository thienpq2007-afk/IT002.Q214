#include <iostream>
#include <vector>
#include<iomanip>
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
using namespace std;

int main() {
    vector<NhanVien*> dsNhanVien;
    int nSX, nVP;
    cout << "Nhap so nhan vien san xuat: ";
    cin >> nSX;
    for (int i = 0; i < nSX; i++)
    {
        NhanVien* nv = new NhanVienSanXuat();
        cout << "\nNhap thong tin nhan vien san xuat thu "
            << i + 1 << endl;
        nv->nhap();
        nv->tinhLuong();
        dsNhanVien.push_back(nv);
    }
    cout << "\nNhap so nhan vien van phong: ";
    cin >> nVP;
    for (int i = 0; i < nVP; i++) 
    {
        NhanVien* nv = new NhanVienVanPhong();
        cout << "\nNhap thong tin nhan vien van phong thu "
            << i + 1 << endl;
        nv->nhap();
        nv->tinhLuong();
        dsNhanVien.push_back(nv);
    }
    cout << "\n========== DANH SACH NHAN VIEN ==========\n";
    double tongLuong = 0;
    for (NhanVien* nv : dsNhanVien)
    {
        nv->xuat();
        tongLuong += nv->getLuong();
        cout << "--------------------------\n";
    }
    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(0)
        << tongLuong << endl;
    NhanVienSanXuat* nvSXMin = nullptr;
    for (NhanVien* nv : dsNhanVien)
    {
        NhanVienSanXuat* sx =
            dynamic_cast<NhanVienSanXuat*>(nv);
        if (sx != nullptr) 
        {
            if (nvSXMin == nullptr ||
                sx->getLuong() < nvSXMin->getLuong())
            {
                nvSXMin = sx;
            }
        }
    }
    if (nvSXMin != nullptr) 
    {
        cout << "\nNhan vien san xuat co luong thap nhat:\n";
        nvSXMin->xuat();
    }
    NhanVienVanPhong* nvVPGiaNhat = nullptr;
    for (NhanVien* nv : dsNhanVien) 
    {
        NhanVienVanPhong* vp =
            dynamic_cast<NhanVienVanPhong*>(nv);
        if (vp != nullptr) 
        {
            if (nvVPGiaNhat == nullptr ||
                vp->getTuoi() > nvVPGiaNhat->getTuoi())
            {
                nvVPGiaNhat = vp;
            }
        }
    }
    if (nvVPGiaNhat != nullptr) 
    {
        cout << "\nNhan vien van phong lon tuoi nhat:\n";
        nvVPGiaNhat->xuat();
    }
    for (NhanVien* nv : dsNhanVien) 
    {
        delete nv;
    }
    return 0;
}
