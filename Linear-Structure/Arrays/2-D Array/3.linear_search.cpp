#include<iostream>
using namespace std;

// Function to perform linear search and return position as a pair
pair<int, int> linearSearch(int arr[][3], int r, int c, int target) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == target)
                return {i, j}; // Found at row i, column j
        }
    }
    return {-1, -1}; // Not found
}

int main() {
    int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int rows = 3, cols = 3;
    int target = 8;

    pair<int, int> result = linearSearch(arr, rows, cols, target);

    if (result.first != -1) {
        cout << "Target element " << target << " found at position: "
             << "(" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Target element " << target << " not found in the array." << endl;
    }

    return 0;
}
