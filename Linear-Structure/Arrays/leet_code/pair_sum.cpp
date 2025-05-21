#include<iostream>
using namespace std;

// Function to return a pair of indices whose sum equals target
pair<int, int> pair_sum(int arr[], int size, int target) {
    int first = 0, end = size - 1;

    while (first < end) {
        int sum = arr[first] + arr[end];
        if (sum < target) {
            first++;
        } else if (sum > target) {
            end--;
        } else {
            return {first, end};  // Correct return of a pair
        }
    }
    return {-1, -1};  // In case no such pair is found
}

int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " value of the array: " << endl;
        cin >> arr[i];
    }

    cout << "The array is: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Enter the target sum: " << endl;
    cin >> target;

    // Assuming the array is sorted. If not, sort it first.
    pair<int, int> result = pair_sum(arr, size, target);

    if (result.first == -1) {
        cout << "No pair found with the given target sum." << endl;
    } else {
        cout << "Pair found at indices: " << result.first << " and " << result.second << endl;
        cout << "Values: " << arr[result.first] << " and " << arr[result.second] << endl;
    }

    delete[] arr;  // Free dynamically allocated memory
    return 0;
}
