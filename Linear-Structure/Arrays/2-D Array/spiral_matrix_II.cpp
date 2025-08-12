#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int range = n * n;
        vector<vector<int>> mat(n, vector<int>(n));

        int stRow = 0, endRow = n - 1;
        int stCol = 0, endCol = n - 1;
        int num = 1;

        while (num <= range) {
            // top
            for (int j = stCol; j <= endCol && num <= range; j++) {
                mat[stRow][j] = num++;
            }
            stRow++;

            // right
            for (int i = stRow; i <= endRow && num <= range; i++) {
                mat[i][endCol] = num++;
            }
            endCol--;

            // bottom
            for (int j = endCol; j >= stCol && num <= range; j--) {
                mat[endRow][j] = num++;
            }
            endRow--;

            // left
            for (int i = endRow; i >= stRow && num <= range; i--) {
                mat[i][stCol] = num++;
            }
            stCol++;
        }

        return mat;
    }
};

int main() {
    int n;
    cout << "Enter matrix size (n): ";
    cin >> n;

    Solution sol;
    vector<vector<int>> result = sol.generateMatrix(n);

    cout << "Spiral Matrix:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }

    return 0;
}
