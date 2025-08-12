#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat) {
    vector<int> ans;
    int m = mat.size(), n = mat[0].size();
    int stRow = 0, endRow = m - 1;
    int stCol = 0, endCol = n - 1;
    
    while (stRow <= endRow && stCol <= endCol) {
        // top row
        for (int j = stCol; j <= endCol; j++) {
            ans.push_back(mat[stRow][j]);
        }
        // right column
        for (int i = stRow + 1; i <= endRow; i++) {
            ans.push_back(mat[i][endCol]);
        }
        // bottom row
        if (stRow < endRow) {
            for (int j = endCol - 1; j >= stCol; j--) {
                ans.push_back(mat[endRow][j]);
            }
        }
        // left column
        if (stCol < endCol) {
            for (int i = endRow - 1; i > stRow; i--) {
                ans.push_back(mat[i][stCol]);
            }
        }
        stRow++;
        endRow--;
        stCol++;
        endCol--;
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> result = spiralMatrix(mat);
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
