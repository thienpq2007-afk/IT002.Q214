#include<iostream>
using namespace std;

//Cấu trúc phân số
struct PhanSo
{
	int tu, mau;
};

//Hàm nhập phân số x từ bàn phím, nếu mẫu số bằng 0 thì yêu cầu nhập lại
void Nhap(PhanSo& x)
{
	while (cin >> x.tu >> x.mau)
	{
		if (x.mau == 0)
		{
			continue; //Mẫu số bằng 0 thì nhập lại
		}
		else
		{
			break; //Mẫu số khác 0 thì thoát khỏi vòng lặp
		}
	}
}

//Hàm tìm ước chung lớn nhất của 2 số nguyên và trả về ước chung lớn nhất của 2 số đó
int UCLN(int tu, int mau)
{
	tu = abs(tu);   //lấy giá trị tuyệt đối
	mau = abs(mau);

	while (mau != 0)
	{
		int r = tu % mau;
		tu = mau;
		mau = r;
	}
	return tu;
}

//Hàm rút gọn phân số và chuẩn hoá dạng của phân số
void RutGon(PhanSo& x)
{
	int ucln = UCLN(x.tu, x.mau);
	x.tu /= ucln;
	x.mau /= ucln;

	//Chuẩn hoá mẫu số phải dương
	if (x.mau < 0)
	{
		x.tu = -x.tu;
		x.mau = -x.mau;
	}
}

//Hàm xuất phân số đã rút gọn theo dạng chuẩn
void Xuat(PhanSo x)
{
	RutGon(x);
	//Nếu mẫu = 1 thì in ra tử
	if (x.mau == 1)
	{
		cout << x.tu << endl;
	}
	//Nếu tử = 0 thì in ra 0
	else if (x.tu == 0)
	{
		cout << 0 << endl;
	}
	//Các trường hợp còn lại thì in ra theo dạng chuẩn của phân số
	else
	{
		cout << x.tu << "/" << x.mau << endl;
	}
}

//Hàm tính tổng 2 phân số bằng cách quy đồng và rút gọn
void Tong2PhanSo(PhanSo x, PhanSo y)
{
	PhanSo z;
	z.tu = x.tu * y.mau + y.tu * x.mau;
	z.mau = x.mau * y.mau;
	Xuat(z);
}

//Hàm tính hiệu 2 phân số bằng cách quy đồng và rút gọn
void Hieu2PhanSo(PhanSo x, PhanSo y)
{
	PhanSo z;
	z.tu = x.tu * y.mau - y.tu * x.mau;
	z.mau = x.mau * y.mau;
	Xuat(z);
}

//Hàm tính tích 2 phân số bằng cách nhân tử với tử, mẫu với mẫu và rút gọn
void Tich2PhanSo(PhanSo x, PhanSo y)
{
	PhanSo z;
	z.tu = x.tu * y.tu;
	z.mau = x.mau * y.mau;
	Xuat(z);
}

//Hàm tính thương 2 phân số bằng cách lấy tử phân số thứ 1 nhân mẫu phân số thứ 2 và mẫu phân số thứ 1 nhân tử phân số thứ 2
void Thuong2PhanSo(PhanSo x, PhanSo y)
{
	PhanSo z;
	z.tu = x.tu * y.mau;
	z.mau = x.mau * y.tu;
	Xuat(z);
}

int main()
{
	PhanSo x, y;
	Nhap(x);
	Nhap(y);
	Tong2PhanSo(x, y);
	Hieu2PhanSo(x, y);
	Tich2PhanSo(x, y);
	Thuong2PhanSo(x, y);
	return 0;
}

