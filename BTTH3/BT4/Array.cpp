#include "Array.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

cArray::cArray()
{
    n = 0;
    A = NULL;
}

cArray::~cArray()
{
    delete[] A;
}

int cArray::GetN()
{
    return n;
}

cArray::cArray(const cArray& other)
{
    n = other.n;
    A = new int[n];
    for (int i = 0; i < n; i++)
        A[i] = other.A[i];
}

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

void cArray::Xuat()
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int cArray::DemX(int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (A[i] == x) dem++;
    return dem;
}

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

bool LaSoNguyenTo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int cArray::SoNguyenToMax()
{
    int max = -1;
    for (int i = 0; i < n; i++)
        if (LaSoNguyenTo(A[i]) && A[i] > max)
            max = A[i];
    return max;
}

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

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

void cArray::InterchangeSort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[i])
                swap(A[i], A[j]);
}

void cArray::BubbleSort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
}

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

void cArray::MergeSort()
{
    MergeSortRec(A, 0, n - 1);
}

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
