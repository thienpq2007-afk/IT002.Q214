#include"Bo.h"

// Phát ra tiếng kêu của bò
// Input: không có
// Output: hiển thị tiếng kêu của bò
void Bo::Keu()
{
    cout << "Bo: Moo Moo\n";
}

// Sinh số lượng con của bò
// Input: không có
// Output: số con bò sinh ra (từ 1 đến 3)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [1, 3]
int Bo::SinhCon()
{
    return rand() % 3 + 1;
}

// Cho lượng sữa bò thu được
// Input: không có
// Output: lượng sữa bò cho (từ 0 đến 20 lít)
// Thuật giải:
// Sinh ngẫu nhiên một số nguyên trong đoạn [0, 20]
int Bo::ChoSua()
{
    return rand() % 21;
}

// Trả về loại gia súc
// Input: không có
// Output: chuỗi "Bo"
string Bo::Loai()
{
    return "Bo";
}
