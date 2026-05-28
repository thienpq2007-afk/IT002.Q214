#include<iostream>
#include<fstream>
#include<vector>
#include"KhachHangA.h"
#include"KhachHangB.h"
#include"KhachHangC.h"

using namespace std;

int main()
{
    ifstream in("XYZ.INP");
    ofstream out("XYZ.OUT");
    int x, y, z;
    in >> x >> y >> z;
    vector<KhachHang*> ds;
    for (int i = 0; i < x; i++)
    {
        KhachHang* p = new KhachHangA;
        p->Nhap(in);
        ds.push_back(p);
    }
    for (int i = 0; i < y; i++)
    {
        KhachHang* p = new KhachHangB;
        p->Nhap(in);
        ds.push_back(p);
    }
    for (int i = 0; i < z; i++)
    {
        KhachHang* p = new KhachHangC;
        p->Nhap(in);
        ds.push_back(p);
    }
    double tong = 0;
    out << x << " " << y << " " << z << endl;
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Xuat(out);
        tong += ds[i]->TinhTien();
    }
    out << "TongSoTienCongTyThuDuoc" << endl;
    out << tong << endl;
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    return 0;
}