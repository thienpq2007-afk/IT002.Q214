#pragma once
#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    void nhap() override;
    void tinhLuong() override;
    void xuat() override;
};
