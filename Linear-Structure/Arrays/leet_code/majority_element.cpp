// A majority element is an element that appears more than n/2 times.
// If no such element exists, return -1 or indicate accordingly.


#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int n) {
    int count = 0;
    int candidate = -1;

    // Phase 1: Find a candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;  // No majority element
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int majority = findMajorityElement(arr, n);
    if (majority == -1) {
        cout << "No majority element found.\n";
    } else {
        cout << "The majority element is: " << majority << endl;
    }

    delete[] arr;
    return 0;
}
// This code uses the Boyer-Moore Voting Algorithm to find the majority element in linear time and constant space.
// The first phase finds a candidate for the majority element, and the second phase verifies if it is indeed the majority element.
// The algorithm is efficient and works well for large arrays.
// The time complexity is O(n) and the space complexity is O(1).
