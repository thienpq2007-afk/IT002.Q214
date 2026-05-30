#include"De.h"

// Phát ra tiếng kêu của dê
// Input: không có
// Output: hiển thị tiếng kêu của dê
void De::Keu()
{
    cout << "De: Mee Mee\n";
}

// Sinh số lượng con của dê
// Input: không có
// Output: số con dê sinh ra (từ 1 đến 3)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [1, 3]
int De::SinhCon()
{
    return rand() % 3 + 1;
}

// Cho lượng sữa dê thu được
// Input: không có
// Output: lượng sữa dê cho (từ 0 đến 10 lít)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [0, 10]
int De::ChoSua()
{
    return rand() % 11;
}

// Trả về loại gia súc
// Input: không có
// Output: chuỗi "De"
string De::Loai()
{
    return "De";
}
