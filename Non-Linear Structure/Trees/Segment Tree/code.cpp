#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;     // for sum
    vector<int> Mintree;  // for min
    int n;

    // Build sum segment tree
    void buildSumTree(vector<int>& arr, int i, int start, int end) {
        if (start == end) {
            tree[i] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildSumTree(arr, 2 * i, start, mid);
            buildSumTree(arr, 2 * i + 1, mid + 1, end);
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    // Point update in sum tree
    void updateSumTree(int idx, int value, int i, int start, int end) {
        if (start == end) {
            tree[i] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateSumTree(idx, value, 2 * i, start, mid);
            } else {
                updateSumTree(idx, value, 2 * i + 1, mid + 1, end);
            }
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    // Range sum query
    int rangeSum(int left, int right, int i, int start, int end) {
        if (right < start || end < left) {
            return 0; // No overlap
        }
        if (left <= start && end <= right) {
            return tree[i]; // Total overlap
        }
        int mid = (start + end) / 2;
        int lSum = rangeSum(left, right, 2 * i, start, mid);
        int rSum = rangeSum(left, right, 2 * i + 1, mid + 1, end);
        return lSum + rSum;
    }

    // Build min segment tree
    void buildMinTree(vector<int>& arr, int i, int start, int end) {
        if (start == end) {
            Mintree[i] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildMinTree(arr, 2 * i, start, mid);
            buildMinTree(arr, 2 * i + 1, mid + 1, end);
            Mintree[i] = min(Mintree[2 * i], Mintree[2 * i + 1]);
        }
    }

    // Range min query
    int rangeMin(int left, int right, int i, int start, int end) {
        if (right < start || end < left) {
            return INT_MAX; // No overlap
        }
        if (left <= start && end <= right) {
            return Mintree[i]; // Total overlap
        }
        int mid = (start + end) / 2;
        int lMin = rangeMin(left, right, 2 * i, start, mid);
        int rMin = rangeMin(left, right, 2 * i + 1, mid + 1, end);
        return min(lMin, rMin);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        Mintree.resize(4 * n);
        buildSumTree(arr, 1, 0, n - 1);
        buildMinTree(arr, 1, 0, n - 1);
    }

    void update(int idx, int value) {
        updateSumTree(idx, value, 1, 0, n - 1);
        // Also update min tree if needed
        updateMinTree(idx, value, 1, 0, n - 1);
    }

    int querySum(int l, int r) {
        return rangeSum(l, r, 1, 0, n - 1);
    }

    int queryMin(int l, int r) {
        return rangeMin(l, r, 1, 0, n - 1);
    }

   
    void updateMinTree(int idx, int value, int i, int start, int end) {
        if (start == end) {
            Mintree[i] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                updateMinTree(idx, value, 2 * i, start, mid);
            else
                updateMinTree(idx, value, 2 * i + 1, mid + 1, end);

            Mintree[i] = min(Mintree[2 * i], Mintree[2 * i + 1]);
        }
    }
};


int main() {
    vector<int> arr = {5, 2, 6, 3, 1, 7};
    SegmentTree st(arr);

    cout << "Initial Range Sum [1, 4]: " << st.querySum(1, 4) << endl; 
    cout << "Initial Range Min [1, 4]: " << st.queryMin(1, 4) << endl;
    
    st.update(2, 10);

    cout << "After Update (arr[2]=10), Range Sum [1, 4]: " << st.querySum(1, 4) << endl;  
    cout << "After Update, Range Min [1, 4]: " << st.queryMin(1, 4) << endl;

    return 0;
}
