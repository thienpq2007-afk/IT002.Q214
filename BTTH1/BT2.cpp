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
		cout << x.tu;
	}
	//Nếu tử = 0 thì in ra 0
	else if (x.tu == 0)
	{
		cout << 0;
	}
	//Các trường hợp còn lại thì in ra theo dạng chuẩn của phân số
	else
	{
		cout << x.tu << "/" << x.mau;
	}
}

//Hàm so sánh 2 phân số bằng các quy đồng, so sánh tử số và xuất ra phân số lớn hơn
void SoSanh2PhanSo(PhanSo x, PhanSo y)
{
	//Nếu tử số của x lớn hơn 
	if (x.tu * y.mau > y.tu * x.mau)
	{
		Xuat(x);
	}
	//Nếu tử số của y lớn hơn
	else
	{
		Xuat(y);
	}
}

int main()
{
	PhanSo x, y;
	Nhap(x);
	Nhap(y);
	SoSanh2PhanSo(x, y);
	return 0;
}
