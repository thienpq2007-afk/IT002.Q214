#include<iostream>
#include<vector>
#include<ctime>
#include"Bo.h"
#include"Cuu.h"
#include"De.h"

using namespace std;

int main()
{
    srand(time(0));
    vector<GiaSuc*> ds;
    int bo, cuu, de;
    cout << "Nhap so bo: ";
    cin >> bo;
    cout << "Nhap so cuu: ";
    cin >> cuu;
    cout << "Nhap so de: ";
    cin >> de;
    for (int i = 0; i < bo; i++)
    {
        ds.push_back(new Bo);
    }
    for (int i = 0; i < cuu; i++)
    {
        ds.push_back(new Cuu);
    }
    for (int i = 0; i < de; i++)
    {
        ds.push_back(new De);
    }
    cout << "\n=== Gia suc doi an ===\n";
    for (int i = 0; i < ds.size(); i++)
    {
        ds[i]->Keu();
    }
    int tongSua = 0;
    int boCon = 0;
    int cuuCon = 0;
    int deCon = 0;
    for (int i = 0; i < ds.size(); i++)
    {
        tongSua += ds[i]->ChoSua();

        if (ds[i]->Loai() == "Bo")
        {
            boCon += ds[i]->SinhCon();
        }
        else if (ds[i]->Loai() == "Cuu")
        {
            cuuCon += ds[i]->SinhCon();
        }
        else
        {
            deCon += ds[i]->SinhCon();
        }
    }
    cout << "\n=== Thong ke ===\n";
    cout << "Bo ban dau: " << bo << endl;
    cout << "Cuu ban dau: " << cuu << endl;
    cout << "De ban dau: " << de << endl;
    cout << "\nSo con sinh ra:\n";
    cout << "Bo sinh: " << boCon << endl;
    cout << "Cuu sinh: " << cuuCon << endl;
    cout << "De sinh: " << deCon << endl;
    cout << "\nTong sua: " << tongSua << " lit\n";
    for (int i = 0; i < ds.size(); i++)
    {
        delete ds[i];
    }
    return 0;
}