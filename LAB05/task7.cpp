#include <iostream>
using namespace std;

int board[20][20];

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;
            solve(row+1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    solve(0, n);
    return 0;
}
