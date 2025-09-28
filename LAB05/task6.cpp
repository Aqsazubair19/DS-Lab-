#include <iostream>
using namespace std;

#define N 5

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y, int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && 
            maze[x][y] == 1 && visited[x][y] == 0);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], int visited[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited)) {
        sol[x][y] = 1;
        visited[x][y] = 1;

        int dx[] = {1, -1, 0, 0};  // Down, Up, Right, Left
        int dy[] = {0, 0, 1, -1};

        for (int dir = 0; dir < 4; dir++) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];

            if (solveMazeUtil(maze, newX, newY, sol, visited))
                return true;
        }

        sol[x][y] = 0;
        visited[x][y] = 0;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};
    int visited[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol, visited)) {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found (4 directions):\n";
    printSolution(sol);
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
