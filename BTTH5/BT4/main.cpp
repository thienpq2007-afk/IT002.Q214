#include "CongTy.h"

int main()
{
    CongTy ct;
    ct.NhapDanhSach();
    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    ct.XuatDanhSach();
    ct.NVLuongThapHonTB();
    ct.NVLuongCaoNhat();
    ct.NVLuongThapNhat();
    ct.LTVLuongCaoNhat();
    ct.KCVLuongThapNhat();
    return 0;
}