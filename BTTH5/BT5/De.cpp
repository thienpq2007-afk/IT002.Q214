#include"De.h"

void De::Keu()
{
    cout << "De: Mee Mee\n";
}

int De::SinhCon()
{
    return rand() % 3 + 1;
}

int De::ChoSua()
{
    return rand() % 11;
}

string De::Loai()
{
    return "De";
}