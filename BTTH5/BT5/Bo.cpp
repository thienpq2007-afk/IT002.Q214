#include"Bo.h"

void Bo::Keu()
{
    cout << "Bo: Moo Moo\n";
}

int Bo::SinhCon()
{
    return rand() % 3 + 1;
}

int Bo::ChoSua()
{
    return rand() % 21;
}

string Bo::Loai()
{
    return "Bo";
}