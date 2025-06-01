#include <iostream>
#include <algorithm>
using namespace std;

void next_permutation(int arr[], int n) {
    int pivot = -1;

    // Step 1: Find the pivot (first i from right where arr[i] < arr[i+1])
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Step 2: If no pivot, reverse entire array (last permutation)
    if (pivot == -1) {
        reverse(arr, arr + n);
        return;
    }

    // Step 3: Find next greater element from the end
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Step 4: Reverse the suffix
    reverse(arr + pivot + 1, arr + n);
}

int main() {
    int arr[] = {1, 2, 4, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    next_permutation(arr, n);

    cout << "The next permutation is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
