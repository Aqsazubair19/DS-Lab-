#include <iostream>
using namespace std;

int main() {
    int rows, cols;
     cout << "Enter number of rows: ";
    cin >> rows;
     cout << "Enter number of columns: ";
    cin >> cols;

    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
       matrix[i] = new int[cols];
    }

    cout << "\nEnter matrix elements:\n";
      for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix in normal form:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

  
    int nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0)
                nonZero++;
        }
    }

    //(3 columns: row, col, value)
    int** sparse = new int*[nonZero];
    for (int i = 0; i < nonZero; i++) {
        sparse[i] = new int[3]; // because 3 col ;
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
              sparse[k][0] = i;
              sparse[k][1] = j;
            sparse[k][2] = matrix[i][j];
           k++;
            }
        }
    }
 cout<<endl;
 
    cout << "Matrix in compressed form (row, col, value):"<<endl;
    for (int i = 0; i < nonZero; i++) {
     cout << "(" << sparse[i][0] << ", " << sparse[i][1]<< ", " << sparse[i][2] << ")\n";
    }

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < nonZero; i++) delete[] sparse[i];
    delete[] sparse;

    return 0;
}
