#include "cVector.h"
#include<cmath>
#include<iomanip>

// Constructor khởi tạo vector
// Input: size (số chiều của vector)
// Output: tạo vector có size phần tử, giá trị ban đầu bằng 0
cVector::cVector(int size)
{
    if (size < 0)
        size = 0;
    n = size;
    data = new double[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = 0;
    }
}

// Constructor sao chép
// Input: vector v
// Output: tạo bản sao của vector v
cVector::cVector(const cVector& v)
{
    n = v.n;
    data = new double[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = v.data[i];
    }
}

// Destructor
// Input: không có
// Output: giải phóng vùng nhớ động
cVector::~cVector()
{
    delete[] data;
}

// Toán tử gán
// Input: vector v
// Output: gán giá trị của v cho vector hiện tại
cVector& cVector::operator=(const cVector& v)
{
    if (this != &v)
    {
        delete[] data;
        n = v.n;
        data = new double[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = v.data[i];
        }
    }
    return *this;
}

// Cộng hai vector
// Input: vector v
// Output: vector tổng
// Thuật giải: cộng từng phần tử tương ứng
cVector cVector::operator+(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return cVector();
    }
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] + v.data[i];
    }
    return kq;
}

// Trừ hai vector
// Input: vector v
// Output: vector hiệu
// Thuật giải: trừ từng phần tử tương ứng
cVector cVector::operator-(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return cVector();
    }
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] - v.data[i];
    }
    return kq;
}

// Nhân vector với một số thực
// Input: số thực k
// Output: vector mới sau khi nhân
// Thuật giải: nhân từng phần tử với k
cVector cVector::operator*(double k) const
{
    cVector kq(n);
    for (int i = 0; i < n; i++)
    {
        kq.data[i] = data[i] * k;
    }
    return kq;
}

// Tích vô hướng hai vector
// Input: vector v
// Output: giá trị tích vô hướng
// Thuật giải: nhân các phần tử tương ứng rồi cộng lại
double cVector::operator*(const cVector& v) const
{
    if (n != v.n)
    {
        cout << "Khong cung so chieu!\n";
        return 0;
    }
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += data[i] * v.data[i];
    }
    return tong;
}

// Tính độ dài vector
// Input: vector hiện tại
// Output: độ dài vector
// Thuật giải: căn bậc hai của tổng bình phương các phần tử
double cVector::DoDai() const
{
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += data[i] * data[i];
    }
    return sqrt(tong);
}

// Nhập vector
// Input: số chiều và các phần tử từ bàn phím
// Output: cập nhật giá trị vector
istream& operator>>(istream& in, cVector& v)
{
    cout << "Nhap so chieu: ";
    in >> v.n;
    if (v.n < 0)
        v.n = 0;
    delete[] v.data;
    v.data = new double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        cout << "Phan tu [" << i << "]: ";
        in >> v.data[i];
    }
    return in;
}

// Xuất vector
// Input: đối tượng vector
// Output: hiển thị vector dạng (x1, x2, ..., xn)
ostream& operator<<(ostream& out, const cVector& v)
{
    out << "(";
    for (int i = 0; i < v.n; i++)
    {
        out << fixed << setprecision(2)
            << v.data[i];
        if (i != v.n - 1)
        {
            out << ", ";
        }
    }
    out << ")";
    return out;
}
