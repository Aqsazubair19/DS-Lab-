#include <iostream>
using namespace std;

int partitionFunc(int A[], int left, int right, int pivot) {
    int leftPointer = left - 1;
    int rightPointer = right;

    while (true) {
        while (A[++leftPointer] < pivot) { }
        while (rightPointer > 0 && A[--rightPointer] > pivot) { }

        if (leftPointer >= rightPointer)
            break;
        else
            swap(A[leftPointer], A[rightPointer]);
    }

    swap(A[leftPointer], A[right]);
    return leftPointer;
}

void quickSort(int A[], int left, int right) {
    if (left >= right)
        return;

    int pivot = A[right];
    int partitionPoint = partitionFunc(A, left, right, pivot);

    quickSort(A, left, partitionPoint - 1);
    quickSort(A, partitionPoint + 1, right);
}

int main() {
    int A[] = {9, 2, 6, 4, 3, 5, 1};
    int size = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
