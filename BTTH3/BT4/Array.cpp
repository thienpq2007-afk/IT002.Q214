#include "Array.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

/*
cArray(): Ham khoi tao mac dinh
Input: Khong
Output: Tao mang rong (n = 0, A = NULL)
Thuat toan:
1. Gan n = 0
2. Gan con tro A = NULL
*/
cArray::cArray()
{
    n = 0;
    A = NULL;
}

/*
~cArray(): Ham huy
Input: Khong
Output: Giai phong bo nho da cap phat
Thuat toan:
1. Giai phong mang A bang delete[]
*/
cArray::~cArray()
{
    delete[] A;
}

/*
GetN: Lay so phan tu cua mang
Input: Khong
Output: Gia tri n (int)
Thuat toan:
1. Tra ve n
*/
int cArray::GetN()
{
    return n;
}

/*
cArray(copy): Ham sao chep
Input: other (cArray)
Output: Tao ban sao cua mang
Thuat toan:
1. Gan n = other.n
2. Cap phat mang moi A co n phan tu
3. Sao chep tung phan tu
*/
cArray::cArray(const cArray& other)
{
    n = other.n;
    A = new int[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];
}

/*
TaoMangNgauNhien: Tao mang so ngau nhien
Input: n (so phan tu)
Output: Mang A gom n so ngau nhien [0, 99]
Thuat toan:
1. Nhap n
2. Giai phong mang cu
3. Cap phat mang moi
4. Khoi tao seed bang time(0)
5. Gan gia tri ngau nhien cho tung phan tu
*/
void cArray::TaoMangNgauNhien()
{
    cout << "Nhap so phan tu: ";
    cin >> n;
    delete[] A;
    A = new int[n];
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;
    }
}

/*
Xuat: Xuat mang
Input: Khong
Output: In ra cac phan tu
Thuat toan:
1. Lap qua tung phan tu
2. In gia tri
*/
void cArray::Xuat()
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

/*
DemX: Dem so lan xuat hien cua x
Input: x (int)
Output: So lan xuat hien (int)
Thuat toan:
1. Khoi tao dem = 0
2. Lap qua mang:
   - Neu A[i] == x -> tang dem
3. Tra ve dem
*/
int cArray::DemX(int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (A[i] == x) dem++;
    return dem;
}

/*
KiemTraMang: Kiem tra mang co tang dan khong
Input: Khong
Output: Thong bao ket qua
Thuat toan:
1. Lap tu 0 den n-2
2. Neu ton tai A[i] > A[i+1] -> khong tang dan
3. Neu khong co -> tang dan
*/
void cArray::KiemTraMang()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            cout << "Mang khong tang dan\n";
            return;
        }
    }
    cout << "Mang tang dan\n";
}

/*
PhanTuLeMin: Tim phan tu le nho nhat
Input: Khong
Output: Gia tri le nho nhat, -1 neu khong co
Thuat toan:
1. Gan min = INT_MAX
2. Lap qua mang:
   - Neu A[i] le va < min -> cap nhat
3. Neu khong tim thay -> tra -1
*/
int cArray::PhanTuLeMin()
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 != 0 && A[i] < min)
            min = A[i];
    }
    return (min == INT_MAX ? -1 : min);
}

/*
LaSoNguyenTo: Kiem tra so nguyen to
Input: n (int)
Output: true/false
Thuat toan:
1. Neu n < 2 -> false
2. Lap tu 2 den sqrt(n)
3. Neu chia het -> false
4. Nguoc lai -> true
*/
bool LaSoNguyenTo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/*
SoNguyenToMax: Tim so nguyen to lon nhat
Input: Khong
Output: Gia tri lon nhat, -1 neu khong co
Thuat toan:
1. Gan max = -1
2. Lap qua mang:
   - Neu la so nguyen to va > max -> cap nhat
3. Tra ve max
*/
int cArray::SoNguyenToMax()
{
    int max = -1;
    for (int i = 0; i < n; i++)
        if (LaSoNguyenTo(A[i]) && A[i] > max)
            max = A[i];
    return max;
}

/*
swap: Hoan vi 2 so
Input: a, b (int&)
Output: Hoan doi gia tri
Thuat toan:
1. Luu tam
2. Gan doi
*/
void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

/*
SelectionSort: Sap xep tang dan (chon)
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. Lap i tu 0 den n-2
2. Tim vi tri nho nhat
3. Hoan vi
*/
void cArray::SelectionSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[idx])
                idx = j;

        swap(A[i], A[idx]);
    }
}

/*
InterchangeSort: Sap xep doi cho truc tiep
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. So sanh tung cap
2. Neu sai thu tu -> doi cho
*/
void cArray::InterchangeSort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[i])
                swap(A[i], A[j]);
}

/*
BubbleSort: Sap xep noi bot
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. Lap nhieu lan
2. So sanh cap ke nhau
3. Day phan tu lon ra cuoi
*/
void cArray::BubbleSort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
}

/*
InsertionSort: Sap xep chen
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. Duyet tu phan tu thu 2
2. Chen vao vi tri dung trong doan da sap xep
*/
void cArray::InsertionSort()
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int k = i - 1;

        while (k >= 0 && A[k] > x)
        {
            A[k + 1] = A[k];
            k--;
        }
        A[k + 1] = x;
    }
}

void heapify(int* A, int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[largest]) largest = l;
    if (r < n && A[r] > A[largest]) largest = r;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, largest, n);
    }
}

void buildHeap(int* A, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, i, n);
}

/*
HeapSort: Sap xep vun dong
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. Xay dung heap
2. Dua max ve cuoi
3. Heapify lai
*/
void cArray::HeapSort()
{
    int size = n;
    buildHeap(A, size);

    for (int i = size - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, 0, i);
    }
}

void Merge(int A[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = A[l + i];
    for (int i = 0; i < n2; i++) R[i] = A[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSortRec(int A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSortRec(A, l, m);
        MergeSortRec(A, m + 1, r);
        Merge(A, l, m, r);
    }
}

/*
MergeSort: Sap xep tron
Input: Mang A
Output: Mang da sap xep
Thuat toan:
1. Chia doi mang
2. Sap xep tung phan
3. Tron lai
*/
void cArray::MergeSort()
{
    MergeSortRec(A, 0, n - 1);
}

/*
QuickSort: Sap xep nhanh
Input: l, r (chi so)
Output: Mang da sap xep
Thuat toan:
1. Chon pivot
2. Phan hoach mang
3. Goi de quy 2 ben
*/
void cArray::QuickSort(int l, int r)
{
    if (l >= r) return;

    int i = l, j = r;
    int pivot = A[(l + r) / 2];

    while (i <= j)
    {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;

        if (i <= j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    if (l < j) QuickSort(l, j);
    if (i < r) QuickSort(i, r);
}
