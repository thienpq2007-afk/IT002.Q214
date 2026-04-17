#include <iostream> 
#include "Array.h" 
using namespace std;

int main()
{
    cArray *A = new cArray;
    int x;

    cout << "===== NHAP DU LIEU =====\n";
    A->TaoMangNgauNhien();

    cout << "\n===== MANG BAN DAU =====\n";
    A->Xuat();

    cArray B = *A;
    cArray C = *A;
    cArray D = *A;
    cArray E = *A;
    cArray F = *A;
    cArray G = *A;
    cArray H = *A;

    cout << "Nhap x can dem: ";
    cin >> x;
    cout << "\n===== KET QUA =====\n";
    cout << "- So lan xuat hien cua " << x << ": " << A->DemX(x) << endl;

    cout << "- Kiem tra tang dan: ";
    A->KiemTraMang();

    cout << "- Phan tu le nho nhat: " << A->PhanTuLeMin() << endl;
    cout << "- So nguyen to lon nhat: ";
    if (A->SoNguyenToMax() != -1)
    {
        cout << A->SoNguyenToMax();
    }
    else
        cout << "Khong ton tai\n";

    cout << "\n";

    cout << "\n===== SAP XEP =====\n";

    // Selection Sort
    B.SelectionSort();
    cout << "Selection Sort: ";
    B.Xuat();

    // Bubble Sort
    C.BubbleSort();
    cout << "Bubble Sort: ";
    C.Xuat();

    // InterChange Sort
    D.InterchangeSort();
    cout << "Interchange Sort: ";
    D.Xuat();

    // Insertion Sort
    E.InsertionSort();
    cout << "Insertion Sort: ";
    E.Xuat();

    // Heap Sort
    F.HeapSort();
    cout << "Heap Sort: ";
    F.Xuat();

    // Merge Sort
    G.MergeSort();
    cout << "Merge Sort: ";
    G.Xuat();

    // Quick Sort
    H.QuickSort(0, H.GetN() - 1);
    cout << "Quick Sort: ";
    H.Xuat();

    delete A;
    return 0;
}

