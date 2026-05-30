#include "cDate.h"

// Kiểm tra năm nhuận
// Input: năm y
// Output: true nếu là năm nhuận, false nếu không
bool cDate::NamNhuan(int y) 
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Trả về số ngày của một tháng trong năm
// Input: tháng m, năm y
// Output: số ngày tương ứng của tháng
int cDate::SoNgayTrongThang(int m, int y) 
{
    int ngayThang[] =
    {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };
    if (m == 2 && NamNhuan(y))
        return 29;

    return ngayThang[m - 1];
}

// Constructor khởi tạo ngày tháng năm
// Input: ngày d, tháng m, năm y
// Output: tạo đối tượng ngày tháng năm
cDate::cDate(int d, int m, int y)
{
    ngay = d;
    thang = m;
    nam = y;
}

// Cộng thêm n ngày
// Input: n (số ngày cần cộng)
// Output: ngày mới sau khi cộng
cDate cDate::operator+(int n) const
{
    cDate temp = *this;
    while (n--)
    {
        temp.ngay++;

        if (temp.ngay > temp.SoNgayTrongThang(temp.thang, temp.nam))
        {
            temp.ngay = 1;
            temp.thang++;

            if (temp.thang > 12)
            {
                temp.thang = 1;
                temp.nam++;
            }
        }
    }
    return temp;
}

// Trừ đi n ngày
// Input: n (số ngày cần trừ)
// Output: ngày mới sau khi trừ
cDate cDate::operator-(int n) const
{
    cDate temp = *this;
    while (n--)
    {
        temp.ngay--;
        if (temp.ngay < 1)
        {
            temp.thang--;

            if (temp.thang < 1)
            {
                temp.thang = 12;
                temp.nam--;
            }
            temp.ngay = temp.SoNgayTrongThang(temp.thang, temp.nam);
        }
    }

    return temp;
}

// Tính khoảng cách giữa hai ngày
// Input: ngày hiện tại và ngày other
// Output: số ngày chênh lệch giữa hai ngày
int cDate::operator-(const cDate& other) const
{
    cDate temp = other;
    int dem = 0;
    while (!(temp.ngay == ngay &&
        temp.thang == thang &&
        temp.nam == nam))
    {
        temp++;
        dem++;
    }
    return dem;
}

// Tiền tố ++
// Input: không có
// Output: tăng ngày hiện tại lên 1 ngày
cDate& cDate::operator++()
{
    *this = *this + 1;
    return *this;
}

// Hậu tố ++
// Input: không có
// Output: trả về ngày cũ, sau đó tăng thêm 1 ngày
cDate cDate::operator++(int)
{
    cDate temp = *this;
    *this = *this + 1;
    return temp;
}

// Tiền tố --
// Input: không có
// Output: giảm ngày hiện tại đi 1 ngày
cDate& cDate::operator--()
{
    *this = *this - 1;
    return *this;
}

// Hậu tố --
// Input: không có
// Output: trả về ngày cũ, sau đó giảm đi 1 ngày
cDate cDate::operator--(int)
{
    cDate temp = *this;
    *this = *this - 1;
    return temp;
}

// Nhập ngày tháng năm
// Input: ngày, tháng, năm từ bàn phím
// Output: cập nhật đối tượng ngày tháng năm
istream& operator>>(istream& in, cDate& d)
{
    cout << "Nhap ngay: ";
    in >> d.ngay;
    cout << "Nhap thang: ";
    in >> d.thang;
    cout << "Nhap nam: ";
    in >> d.nam;
    return in;
}

// Xuất ngày tháng năm theo định dạng dd/mm/yyyy
// Input: đối tượng ngày tháng năm
// Output: hiển thị ngày tháng năm ra màn hình
ostream& operator<<(ostream& out, const cDate& d)
{
    if (d.ngay < 10)
        out << "0";
    out << d.ngay << "/";
    if (d.thang < 10)
        out << "0";
    out << d.thang << "/";
    out << d.nam;
    return out;
}
