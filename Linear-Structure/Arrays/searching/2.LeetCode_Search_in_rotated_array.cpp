#include<iostream>
#include<vector>
using namespace std;

int SearchInRotatedSortedArray(vector<int>& vec, int target) {
    int start = 0, end = vec.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (vec[mid] == target) return mid;

        // Left half is sorted
        if (vec[start] <= vec[mid]) {
            if (vec[start] <= target && target < vec[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (vec[mid] < target && target <= vec[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    
    return -1; // not found
}

int main() {
    vector<int> vec = {3, 4, 5, 6, 7, 0, 1, 2};
    
    cout << "The array is: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int index = SearchInRotatedSortedArray(vec, target);
    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
