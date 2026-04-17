#pragma once
#include <iostream>
using namespace std;

class cArray
{
private:
    int* A;
    int n;

public:
    cArray();
    ~cArray();
    cArray(const cArray& other);

    int GetN();

    void TaoMangNgauNhien();
    void Xuat();
    int DemX(int x);
    void KiemTraMang();
    int PhanTuLeMin();
    int SoNguyenToMax();

    void SelectionSort();
    void InterchangeSort();
    void BubbleSort();
    void InsertionSort();
    void HeapSort();
    void MergeSort();
    void QuickSort(int l, int r);
};
