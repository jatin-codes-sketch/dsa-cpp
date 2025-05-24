#include<iostream>
#include<vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // Target found at index mid
        else if (arr[mid] < target)
            left = mid + 1;  // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }

    return -1;  // Target not found
}

int main() {
    int size, target;
    cout << "Enter the size of the sorted array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter " << size << " sorted elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
