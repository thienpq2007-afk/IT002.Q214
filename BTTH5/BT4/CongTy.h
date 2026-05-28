#pragma once
#include<vector>
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

class CongTy
{
private:
    vector<NhanVien*> ds;

public:
    ~CongTy();
    void NhapDanhSach();
    void XuatDanhSach();
    double LuongTrungBinh();
    void NVLuongThapHonTB();
    void NVLuongCaoNhat();
    void NVLuongThapNhat();
    void LTVLuongCaoNhat();
    void KCVLuongThapNhat();
};