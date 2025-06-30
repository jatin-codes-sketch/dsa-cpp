#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) return false;

    if (expVal == n * n - 1) return true;

    int a1 = isSafe(grid, r - 2, c + 1, n, expVal + 1);
    int a2 = isSafe(grid, r - 1, c + 2, n, expVal + 1);
    int a3 = isSafe(grid, r + 1, c + 2, n, expVal + 1);
    int a4 = isSafe(grid, r + 2, c + 1, n, expVal + 1);
    int a5 = isSafe(grid, r - 2, c - 1, n, expVal + 1);
    int a6 = isSafe(grid, r - 1, c - 2, n, expVal + 1);
    int a7 = isSafe(grid, r + 1, c - 2, n, expVal + 1);
    int a8 = isSafe(grid, r + 2, c - 1, n, expVal + 1);

    return a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8;
}

bool knightTour(vector<vector<int>>& grid) {
    return isSafe(grid, 0, 0, grid.size(), 0);
}

int main() {
    vector<vector<int>> grid = {
        {0, 59, 38, 33, 30, 17, 8, 63},
        {37, 34, 31, 60, 9, 62, 29, 16},
        {58, 1, 36, 39, 32, 27, 18, 7},
        {35, 48, 41, 26, 61, 10, 15, 28},
        {42, 57, 2, 49, 40, 23, 6, 19},
        {47, 50, 45, 54, 25, 20, 11, 14},
        {56, 43, 52, 3, 22, 13, 24, 5},
        {51, 46, 55, 44, 53, 4, 21, 12}
    };

    if (knightTour(grid)) {
        cout << "✅ Valid Knight's Tour" << endl;
    } else {
        cout << "❌ Invalid Knight's Tour" << endl;
    }

    return 0;
}
