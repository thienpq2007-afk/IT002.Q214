#include"Cuu.h"

// Phát ra tiếng kêu của cừu
// Input: không có
// Output: hiển thị tiếng kêu của cừu
void Cuu::Keu()
{
    cout << "Cuu: Baa Baa\n";
}

// Sinh số lượng con của cừu
// Input: không có
// Output: số con cừu sinh ra (từ 1 đến 3)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [1, 3]
int Cuu::SinhCon()
{
    return rand() % 3 + 1;
}

// Cho lượng sữa cừu thu được
// Input: không có
// Output: lượng sữa cừu cho (từ 0 đến 5 lít)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [0, 5]
int Cuu::ChoSua()
{
    return rand() % 6;
}

// Trả về loại gia súc
// Input: không có
// Output: chuỗi "Cuu"
string Cuu::Loai()
{
    return "Cuu";
}
