#include <iostream>
using namespace std;

struct Date
{
    int ngay, thang, nam;
};

bool NamNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int SoNgayTrongThang(int thang, int nam)
{
    switch (thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (NamNhuan(nam)) return 29;
        return 28;
    }
    return 0;
}

void Nhap(Date& d)
{
    do
    {
        cout << "Nhap ngay: ";
        cin >> d.ngay;

        cout << "Nhap thang: ";
        cin >> d.thang;

        cout << "Nhap nam: ";
        cin >> d.nam;

        if (d.thang < 1 || d.thang > 12 ||
            d.ngay < 1 || d.ngay > SoNgayTrongThang(d.thang, d.nam))
        {
            cout << "Ngay khong hop le, nhap lai!\n";
        }

    } while (d.thang < 1 || d.thang > 12 ||
        d.ngay < 1 || d.ngay > SoNgayTrongThang(d.thang, d.nam));
}

void NgayKeTiep(Date& d)
{
    d.ngay++;

    if (d.ngay > SoNgayTrongThang(d.thang, d.nam))
    {
        d.ngay = 1;
        d.thang++;

        if (d.thang > 12)
        {
            d.thang = 1;
            d.nam++;
        }
    }
}

int main()
{
    Date d;

    Nhap(d);
    NgayKeTiep(d);

    cout << "Ngay ke tiep: "
        << d.ngay << "/" << d.thang << "/" << d.nam;

    return 0;
}
