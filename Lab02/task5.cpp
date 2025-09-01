#include <iostream>
using namespace std;


int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
       for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
      }
       return matrix;
}


void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter elements of matrix (" << rows << "x" << cols << "):"<<endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int** addMatrix(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}


int** subtractMatrix(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
      cin >> rows;
    cout << "Enter number of columns: ";
      cin >> cols;
    

      int** A = createMatrix(rows, cols);
      int** B = createMatrix(rows, cols);

      cout << "\nMatrix A:\n";
     inputMatrix(A, rows, cols);

      cout << "\nMatrix B:\n";
      inputMatrix(B, rows, cols);

    int** sum = addMatrix(A, B, rows, cols);
       cout << "\nA + B = \n";
    displayMatrix(sum, rows, cols);

    int** diff = subtractMatrix(A, B, rows, cols);
       cout << "\nA - B = \n";
    displayMatrix(diff, rows, cols);

    
    deleteMatrix(A, rows);
     deleteMatrix(B, rows);
       deleteMatrix(sum, rows);
      deleteMatrix(diff, rows);

    return 0;
}

