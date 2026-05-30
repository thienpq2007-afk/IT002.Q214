#include "cTime.h"

// Chuẩn hóa thời gian về dạng hợp lệ HH:MM:SS
// Input: giờ, phút, giây hiện tại
// Output: thời gian sau khi chuẩn hóa
void cTime::ChuanHoa()
{
    int tongGiay = gio * 3600 + phut * 60 + giay;
    tongGiay %= 86400;
    if (tongGiay < 0)
        tongGiay += 86400;
    gio = tongGiay / 3600;
    tongGiay %= 3600;
    phut = tongGiay / 60;
    giay = tongGiay % 60;
}

// Constructor khởi tạo thời gian
// Input: giờ h, phút p, giây s
// Output: tạo đối tượng thời gian hợp lệ
cTime::cTime(int h, int p, int s)
{
    gio = h;
    phut = p;
    giay = s;

    ChuanHoa();
}

// Cộng thêm số giây vào thời gian
// Input: s (số giây cần cộng)
// Output: thời gian mới sau khi cộng
cTime cTime::operator+(int s) const
{
    cTime temp(gio, phut, giay);

    temp.giay += s;
    temp.ChuanHoa();

    return temp;
}

// Trừ đi số giây khỏi thời gian
// Input: s (số giây cần trừ)
// Output: thời gian mới sau khi trừ
cTime cTime::operator-(int s) const
{
    cTime temp(gio, phut, giay);

    temp.giay -= s;
    temp.ChuanHoa();

    return temp;
}

// Tiền tố ++
// Input: không có
// Output: tăng thời gian thêm 1 giây
cTime& cTime::operator++()
{
    giay++;
    ChuanHoa();

    return *this;
}

// Hậu tố ++
// Input: không có
// Output: trả về giá trị cũ, sau đó tăng 1 giây
cTime cTime::operator++(int)
{
    cTime temp = *this;

    giay++;
    ChuanHoa();

    return temp;
}

// Tiền tố --
// Input: không có
// Output: giảm thời gian đi 1 giây
cTime& cTime::operator--()
{
    giay--;
    ChuanHoa();

    return *this;
}

// Hậu tố --
// Input: không có
// Output: trả về giá trị cũ, sau đó giảm 1 giây
cTime cTime::operator--(int)
{
    cTime temp = *this;

    giay--;
    ChuanHoa();

    return temp;
}

// Nhập thời gian
// Input: giờ, phút, giây từ bàn phím
// Output: cập nhật đối tượng thời gian
istream& operator>>(istream& in, cTime& t)
{
    cout << "Nhap gio: ";
    in >> t.gio;

    cout << "Nhap phut: ";
    in >> t.phut;

    cout << "Nhap giay: ";
    in >> t.giay;

    t.ChuanHoa();

    return in;
}

// Xuất thời gian theo định dạng HH:MM:SS
// Input: đối tượng thời gian
// Output: hiển thị thời gian ra màn hình
ostream& operator<<(ostream& out, const cTime& t)
{
    if (t.gio < 10)
        out << "0";
    out << t.gio << ":";

    if (t.phut < 10)
        out << "0";
    out << t.phut << ":";

    if (t.giay < 10)
        out << "0";
    out << t.giay;

    return out;
}
