#include "CongTy.h"

// Destructor
// Input: không có
// Output: giải phóng bộ nhớ của danh sách nhân viên
CongTy::~CongTy()
{
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
}

// Nhập danh sách nhân viên
// Input: số lượng nhân viên và thông tin từng nhân viên
// Output: cập nhật danh sách nhân viên của công ty
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

// Xuất danh sách nhân viên
// Input: danh sách nhân viên
// Output: hiển thị toàn bộ nhân viên
void CongTy::XuatDanhSach()
{
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Xuat();
        cout << endl;
    }
}

// Tính lương trung bình của công ty
// Input: danh sách nhân viên
// Output: lương trung bình
// Thuật giải:
// Cộng tổng lương của tất cả nhân viên
// rồi chia cho số lượng nhân viên
double CongTy::LuongTrungBinh()
{
    double tong = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        tong += ds[i]->TinhLuong();
    }
    return tong / ds.size();
}

// Liệt kê nhân viên có lương thấp hơn trung bình
// Input: danh sách nhân viên
// Output: danh sách nhân viên có lương < lương trung bình
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

// Tìm nhân viên có lương cao nhất
// Input: danh sách nhân viên
// Output: thông tin nhân viên lương cao nhất
// Thuật giải:
// Duyệt danh sách và lưu vị trí có lương lớn nhất
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

// Tìm nhân viên có lương thấp nhất
// Input: danh sách nhân viên
// Output: thông tin nhân viên lương thấp nhất
// Thuật giải:
// Duyệt danh sách và lưu vị trí có lương nhỏ nhất
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

// Tìm lập trình viên có lương cao nhất
// Input: danh sách nhân viên
// Output: thông tin lập trình viên lương cao nhất
// Thuật giải:
// Dùng dynamic_cast để lọc các đối tượng LapTrinhVien,
// sau đó tìm người có lương lớn nhất
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

// Tìm kiểm chứng viên có lương thấp nhất
// Input: danh sách nhân viên
// Output: thông tin kiểm chứng viên lương thấp nhất
// Thuật giải:
// Dùng dynamic_cast để lọc các đối tượng KiemChungVien,
// sau đó tìm người có lương nhỏ nhất
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
