#include "PhanSo.h"

// Hàm tìm ước chung lớn nhất của hai số nguyên
// Input: a, b
// Output: UCLN của a và b
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// Rút gọn phân số về tối giản
// Input: tử số và mẫu số hiện tại
// Output: phân số đã được rút gọn
void PhanSo::RutGon()
{
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
}

// Constructor khởi tạo phân số
// Input: tử số t, mẫu số m
// Output: tạo phân số tối giản
PhanSo::PhanSo(int t, int m)
{
    tu = t;
    mau = m;

    if (mau == 0)
    {
        mau = 1;
    }

    RutGon();
}

// Lấy tử số
// Output: giá trị tử số
int PhanSo::getTu() const
{
    return tu;
}

// Lấy mẫu số
// Output: giá trị mẫu số
int PhanSo::getMau() const
{
    return mau;
}

// Cộng hai phân số
// Input: phân số ps
// Output: tổng hai phân số
PhanSo PhanSo::operator+(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau + ps.tu * mau,
        mau * ps.mau
    );
}

// Trừ hai phân số
// Input: phân số ps
// Output: hiệu hai phân số
PhanSo PhanSo::operator-(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau - ps.tu * mau,
        mau * ps.mau
    );
}

// Nhân hai phân số
// Input: phân số ps
// Output: tích hai phân số
PhanSo PhanSo::operator*(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.tu,
        mau * ps.mau
    );
}

// Chia hai phân số
// Input: phân số ps
// Output: thương hai phân số
PhanSo PhanSo::operator/(const PhanSo& ps)
{
    return PhanSo(
        tu * ps.mau,
        mau * ps.tu
    );
}

// So sánh bằng
// Output: true nếu hai phân số bằng nhau
bool PhanSo::operator==(PhanSo& ps)
{
    return tu * ps.mau == ps.tu * mau;
}

// So sánh lớn hơn
// Output: true nếu phân số hiện tại lớn hơn ps
bool PhanSo::operator>(PhanSo& ps)
{
    return tu * ps.mau > ps.tu * mau;
}

// So sánh nhỏ hơn
// Output: true nếu phân số hiện tại nhỏ hơn ps
bool PhanSo::operator<(PhanSo& ps)
{
    return tu * ps.mau < ps.tu * mau;
}

// Nhập phân số
// Input: tử số và mẫu số từ bàn phím
// Output: cập nhật giá trị phân số
istream& operator>>(istream& in, PhanSo& ps)
{
    cout << "Nhap tu so: ";
    in >> ps.tu;

    cout << "Nhap mau so: ";
    in >> ps.mau;

    while (ps.mau == 0)
    {
        cout << "Mau so phai khac 0. Nhap lai: ";
        in >> ps.mau;
    }

    ps.RutGon();

    return in;
}

// Xuất phân số
// Input: đối tượng phân số
// Output: hiển thị phân số ra màn hình
ostream& operator<<(ostream& out, const PhanSo& ps)
{
    if (ps.getMau() == 1)
        out << ps.getTu();
    else
        out << ps.getTu() << "/" << ps.getMau();

    return out;
}
