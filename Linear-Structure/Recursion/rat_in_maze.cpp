#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &board, int row, int col, vector<string> &ans, string path, vector<vector<bool>> &vis) {
    int n = board.size();
    
    // Boundary and block check
    if (row < 0 || col < 0 || row >= n || col >= n || board[row][col] == 0 || vis[row][col])
        return;

    // Base case: reached destination
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark as visited
    vis[row][col] = true;

    // Explore all 4 directions
    helper(board, row + 1, col, ans, path + "D", vis); // Down
    helper(board, row - 1, col, ans, path + "U", vis); // Up
    helper(board, row, col + 1, ans, path + "R", vis); // Right
    helper(board, row, col - 1, ans, path + "L", vis); // Left

    // Backtrack
    vis[row][col] = false;
}

vector<string> maze(vector<vector<int>> &board) {
    int n = board.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    // If the start or end cell is blocked
    if (board[0][0] == 0 || board[n - 1][n - 1] == 0)
        return ans;

    helper(board, 0, 0, ans, path, vis);
    return ans;
}

int main() {
    vector<vector<int>> board = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = maze(board);

    if (paths.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Possible paths:" << endl;
        for (string p : paths)
            cout << p << endl;
    }

    return 0;
}
