#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& vec, int n, int maxPages, int m) {
    int person = 1, total = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] > maxPages) return false;  // A single book exceeds limit

        if (total + vec[i] <= maxPages) {
            total += vec[i];
        } else {
            person++;
            total = vec[i];
        }

        if (person > m) return false;
    }

    return true;
}

int book_allocation(vector<int>& vec, int n, int m) {
    if (m > n) return -1;  // Not enough books

    int sum = 0;
    for (int i = 0; i < n; i++) sum += vec[i];

    int start = 0, end = sum, ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isValid(vec, n, mid, m)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {1, 5, 3, 2, 6, 3, 4, 8};
    int n = vec.size();
    int m = 3;  // Number of students/persons

    int num = book_allocation(vec, n, m);

    if (num == -1)
        cout << "Not enough books for the students." << endl;
    else
        cout << "The minimum maximum pages assigned is " << num << endl;

    return 0;
}
