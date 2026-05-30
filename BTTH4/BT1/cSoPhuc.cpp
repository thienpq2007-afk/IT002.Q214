#include<iostream>
#include"cSoPhuc.h"
using namespace std;

// Constructor có tham số
// Input: phần thực t, phần ảo a
// Output: khởi tạo số phức với giá trị tương ứng
cSoPhuc::cSoPhuc(double t, double a)
{
	thuc = t;
	ao = a;
}

// Constructor mặc định
// Input: không có
// Output: tạo số phức 0 + 0i
cSoPhuc::cSoPhuc()
{
	thuc = 0;
	ao = 0;
}

// Toán tử nhập số phức
// Input: phần thực và phần ảo từ bàn phím
// Output: cập nhật giá trị đối tượng số phức
istream& operator>>(istream& in, cSoPhuc& sp)
{
	cout << "Nhap phan thuc: ";
	in >> sp.thuc;
	cout << "Nhap phan ao: ";
	in >> sp.ao;
	return in;
}

// Toán tử xuất số phức
// Input: đối tượng số phức cần xuất
// Output: hiển thị số phức theo dạng a + bi
ostream& operator<<(ostream& out, const cSoPhuc& sp)
{
	if (sp.thuc != 0)
	{
		out << sp.thuc;
		if (sp.ao > 0)
		{
			out << " + " << sp.ao << "i";
		}
		else if (sp.ao < 0)
		{
			out << " - " << -sp.ao << "i";
		}
	}
	else
	{
		if (sp.ao > 0)
		{
			out << sp.ao << "i";
		}
		else if (sp.ao < 0)
		{
			out << sp.ao << "i";
		}
		else
			out << 0;
	}
	return out;
}

// Toán tử cộng
// Input: số phức hiện tại và số phức sp
// Output: số phức mới là tổng của hai số phức
// Thuật giải: cộng phần thực với phần thực,
// cộng phần ảo với phần ảo
cSoPhuc cSoPhuc::operator+(const cSoPhuc& sp)
{
	return cSoPhuc(thuc + sp.thuc, ao + sp.ao);
}

// Toán tử trừ
// Input: hai số phức
// Output: hiệu hai số phức
// Thuật giải: trừ phần thực và phần ảo tương ứng
cSoPhuc cSoPhuc::operator-(const cSoPhuc& sp)
{
	return cSoPhuc(thuc - sp.thuc, ao - sp.ao);
}

// Toán tử nhân
// Input: hai số phức
// Output: tích hai số phức
// Thuật giải:
// (a+bi)(c+di)=(ac-bd)+(ad+bc)i
cSoPhuc cSoPhuc::operator*(const cSoPhuc& sp)
{
	return cSoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
}

// Toán tử chia
// Input: hai số phức
// Output: thương hai số phức
// Thuật giải:
// Tính mẫu c²+d² rồi áp dụng công thức chia số phức
cSoPhuc cSoPhuc::operator/(const cSoPhuc& sp)
{
	double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
	return cSoPhuc((thuc * sp.thuc + ao * sp.ao) / mau, (ao * sp.thuc - thuc * sp.ao) / mau);
}

// Toán tử so sánh bằng
// Input: hai số phức
// Output: true nếu bằng nhau, false nếu ngược lại
// Thuật giải: so sánh phần thực và phần ảo
bool cSoPhuc::operator==(const cSoPhuc& sp)
{
	return thuc == sp.thuc && ao == sp.ao;
}

// Toán tử so sánh khác
// Input: hai số phức
// Output: true nếu khác nhau, false nếu bằng nhau
// Thuật giải: phủ định kết quả của toán tử ==
bool cSoPhuc::operator!=(const cSoPhuc& sp)
{
	return !(*this == sp);
}
