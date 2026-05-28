#include "SinhVien.h"

SinhVien::~SinhVien()
{

}

void SinhVien::Nhap()
{
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong tin chi: ";
    cin >> tongTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}

void SinhVien::Xuat()
{
    cout << "MSSV: " << mssv << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Dia chi: " << diaChi << endl;
    cout << "Tong tin chi: " << tongTinChi << endl;
    cout << "Diem trung binh: " << diemTB << endl;
}

double SinhVien::GetDiemTB()
{
    return diemTB;
}