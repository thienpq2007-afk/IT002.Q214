#pragma once
#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    void nhap() override;
    void tinhLuong() override;
    void xuat() override;
};
