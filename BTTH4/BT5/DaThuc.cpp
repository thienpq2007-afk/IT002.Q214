#include "DaThuc.h"
#include<cmath>
#include<iomanip>

// Constructor khởi tạo đa thức
// Input: b (bậc của đa thức)
// Output: tạo đa thức có bậc b với các hệ số bằng 0
DaThuc::DaThuc(int b)
{
    if (b < 0)
        b = 0;
    bac = b;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
    {
        heSo[i] = 0;
    }
}

// Constructor sao chép
// Input: đa thức dt
// Output: tạo bản sao của đa thức dt
DaThuc::DaThuc(const DaThuc& dt)
{
    bac = dt.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++)
    {
        heSo[i] = dt.heSo[i];
    }
}

// Destructor
// Input: không có
// Output: giải phóng vùng nhớ động
DaThuc::~DaThuc()
{
    delete[] heSo;
}

// Toán tử gán
// Input: đa thức dt
// Output: gán giá trị của dt cho đối tượng hiện tại
DaThuc& DaThuc::operator=(const DaThuc& dt)
{
    if (this != &dt)
    {
        delete[] heSo;
        bac = dt.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            heSo[i] = dt.heSo[i];
        }
    }
    return *this;
}

// Tối ưu bậc đa thức
// Input: đa thức hiện tại
// Output: loại bỏ các hệ số 0 ở bậc cao nhất
void DaThuc::ToiUu()
{
    while (bac > 0 && heSo[bac] == 0)
    {
        bac--;
    }
}

// Cộng hai đa thức
// Input: đa thức dt
// Output: đa thức tổng
DaThuc DaThuc::operator+(const DaThuc& dt) const
{
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++)
    {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;
        kq.heSo[i] = a + b;
    }
    kq.ToiUu();
    return kq;
}

// Trừ hai đa thức
// Input: đa thức dt
// Output: đa thức hiệu
DaThuc DaThuc::operator-(const DaThuc& dt) const
{
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++)
    {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;
        kq.heSo[i] = a - b;
    }
    kq.ToiUu();
    return kq;
}

// Nhân hai đa thức
// Input: đa thức dt
// Output: đa thức tích
DaThuc DaThuc::operator*(const DaThuc& dt) const
{
    DaThuc kq(bac + dt.bac);
    for (int i = 0; i <= bac; i++)
    {
        for (int j = 0; j <= dt.bac; j++)
        {
            kq.heSo[i + j] += heSo[i] * dt.heSo[j];
        }
    }
    kq.ToiUu();
    return kq;
}

// Tính giá trị đa thức tại x
// Input: giá trị x
// Output: giá trị của đa thức tại x
double DaThuc::GiaTri(double x) const
{
    double tong = 0;
    for (int i = 0; i <= bac; i++)
    {
        tong += heSo[i] * pow(x, i);
    }
    return tong;
}

// Nhập đa thức
// Input: bậc đa thức và các hệ số
// Output: cập nhật đa thức
istream& operator>>(istream& in, DaThuc& dt)
{
    cout << "Nhap bac da thuc: ";
    in >> dt.bac;
    if (dt.bac < 0)
        dt.bac = 0;
    delete[] dt.heSo;
    dt.heSo = new double[dt.bac + 1];
    for (int i = dt.bac; i >= 0; i--)
    {
        cout << "He so bac " << i << ": ";
        in >> dt.heSo[i];
    }
    dt.ToiUu();
    return in;
}

// Xuất đa thức
// Input: đối tượng đa thức
// Output: biểu diễn đa thức ra màn hình
ostream& operator<<(ostream& out, const DaThuc& dt)
{
    bool first = true;
    for (int i = dt.bac; i >= 0; i--)
    {
        if (dt.heSo[i] != 0)
        {
            double hs = dt.heSo[i];
            if (!first)
            {
                if (hs > 0)
                    out << " + ";
                else
                    out << " - ";
            }
            else
            {
                if (hs < 0)
                    out << "-";
            }
            double absHS = abs(hs);
            if (!(absHS == 1 && i != 0))
            {
                if (absHS == (int)absHS)
                    out << (int)absHS;
                else
                    out << fixed << setprecision(2) << absHS;
            }
            if (i > 0)
            {
                out << "x";

                if (i > 1)
                {
                    out << "^" << i;
                }
            }
            first = false;
        }
    }
    if (first)
    {
        out << "0";
    }
    return out;
}
