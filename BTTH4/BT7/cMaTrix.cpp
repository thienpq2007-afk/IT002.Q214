#include "cMatrix.h"
#include<iomanip>

// Cấp phát bộ nhớ cho ma trận
// Input: số dòng r, số cột c
// Output: tạo ma trận r x c với các phần tử bằng 0
void cMatrix::CapPhat(int r, int c)
{
    dong = r;
    cot = c;

    a = new double* [dong];

    for (int i = 0; i < dong; i++)
    {
        a[i] = new double[cot];

        for (int j = 0; j < cot; j++)
        {
            a[i][j] = 0;
        }
    }
}

// Giải phóng bộ nhớ ma trận
// Input: ma trận hiện tại
// Output: thu hồi vùng nhớ đã cấp phát
void cMatrix::GiaiPhong()
{
    if (a != nullptr)
    {
        for (int i = 0; i < dong; i++)
        {
            delete[] a[i];
        }

        delete[] a;
    }

    a = nullptr;
}

// Constructor khởi tạo ma trận
// Input: số dòng r, số cột c
// Output: tạo ma trận r x c
cMatrix::cMatrix(int r, int c)
{
    a = nullptr;

    if (r < 0)
        r = 0;

    if (c < 0)
        c = 0;

    CapPhat(r, c);
}

// Constructor sao chép
// Input: ma trận m
// Output: tạo bản sao của ma trận m
cMatrix::cMatrix(const cMatrix& m)
{
    dong = m.dong;
    cot = m.cot;
    a = new double* [dong];
    for (int i = 0; i < dong; i++)
    {
        a[i] = new double[cot];
        for (int j = 0; j < cot; j++)
        {
            a[i][j] = m.a[i][j];
        }
    }
}

// Destructor
// Input: không có
// Output: giải phóng bộ nhớ động
cMatrix::~cMatrix()
{
    GiaiPhong();
}

// Toán tử gán
// Input: ma trận m
// Output: gán giá trị ma trận m cho ma trận hiện tại
cMatrix& cMatrix::operator=(const cMatrix& m)
{
    if (this != &m)
    {
        GiaiPhong();

        CapPhat(m.dong, m.cot);

        for (int i = 0; i < dong; i++)
        {
            for (int j = 0; j < cot; j++)
            {
                a[i][j] = m.a[i][j];
            }
        }
    }

    return *this;
}

// Cộng hai ma trận
// Input: ma trận m
// Output: ma trận tổng
// Thuật giải: cộng từng phần tử cùng vị trí
cMatrix cMatrix::operator+(const cMatrix& m) const
{
    if (dong != m.dong || cot != m.cot)
    {
        cout << "Khong cung kich thuoc!\n";
        return cMatrix();
    }
    cMatrix kq(dong, cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            kq.a[i][j] = a[i][j] + m.a[i][j];
        }
    }
    return kq;
}

// Trừ hai ma trận
// Input: ma trận m
// Output: ma trận hiệu
// Thuật giải: trừ từng phần tử cùng vị trí
cMatrix cMatrix::operator-(const cMatrix& m) const
{
    if (dong != m.dong || cot != m.cot)
    {
        cout << "Khong cung kich thuoc!\n";
        return cMatrix();
    }
    cMatrix kq(dong, cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            kq.a[i][j] = a[i][j] - m.a[i][j];
        }
    }
    return kq;
}

// Nhân hai ma trận
// Input: ma trận m
// Output: ma trận tích
// Thuật giải:
// Mỗi phần tử kết quả bằng tổng tích
// các phần tử hàng i và cột j
cMatrix cMatrix::operator*(const cMatrix& m) const
{
    if (cot != m.dong)
    {
        cout << "Khong the nhan ma tran!\n";
        return cMatrix();
    }
    cMatrix kq(dong, m.cot);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            for (int k = 0; k < cot; k++)
            {
                kq.a[i][j] += a[i][k] * m.a[k][j];
            }
        }
    }
    return kq;
}

// Nhân ma trận với vector
// Input: mảng v gồm n phần tử
// Output: vector kết quả sau phép nhân
// Thuật giải:
// Lấy tích vô hướng từng hàng của ma trận với vector
double* cMatrix::NhanVector(double* v, int n) const
{
    if (cot != n)
    {
        cout << "Khong the nhan!\n";
        return nullptr;
    }
    double* kq = new double[dong];
    for (int i = 0; i < dong; i++)
    {
        kq[i] = 0;

        for (int j = 0; j < cot; j++)
        {
            kq[i] += a[i][j] * v[j];
        }
    }
    return kq;
}

// Nhập ma trận
// Input: số dòng, số cột và các phần tử
// Output: cập nhật ma trận
istream& operator>>(istream& in, cMatrix& m)
{
    int r, c;

    cout << "Nhap so dong: ";
    in >> r;

    cout << "Nhap so cot: ";
    in >> c;

    m.GiaiPhong();

    m.CapPhat(r, c);

    for (int i = 0; i < m.dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            in >> m.a[i][j];
        }
    }

    return in;
}

// Xuất ma trận
// Input: đối tượng ma trận
// Output: hiển thị ma trận ra màn hình
ostream& operator<<(ostream& out, const cMatrix& m)
{
    for (int i = 0; i < m.dong; i++)
    {
        for (int j = 0; j < m.cot; j++)
        {
            out << fixed << setprecision(2)
                << setw(8)
                << m.a[i][j];
        }
        out << endl;
    }
    return out;
}
