#include <iostream>
using namespace std;


void combSort(int arr[], int n, int &comparisons, int &swaps) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        // shrink the gap (shrink factor = 1.3 approx)
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n=9;
    int arr[] = {23, 9, 2, 7, 5, 19, 31, 15, 29};
  

    cout << "Original array:" << endl;
    printArray(arr, n);

    int comparisons = 0, swaps = 0;
    combSort(arr, n, comparisons, swaps);

    cout << "\nSorted array using Comb Sort:" << endl;
    printArray(arr, n);

    cout << "\nTotal Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;

    return 0;
}
