#include<iostream>
#include<vector>
using namespace std;

vector<int> product_ofArrayExceptSelf(vector<int>& vec) {
    int size = vec.size();
    vector<int> ans(size, 1);
    
    // Prefix
    for (int i = 1; i < size; i++) {
        ans[i] = ans[i - 1] * vec[i - 1];
    }

    // Suffix
    int suffix = 1;
    for (int i = size - 2; i >= 0; i--) {
        suffix *= vec[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> vec(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << "th element of the array: ";
        cin >> vec[i];
    }

    cout << "The array is: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vector<int> product = product_ofArrayExceptSelf(vec);

    cout << "The product array is: ";
    for (int i = 0; i < product.size(); i++) {
        cout << product[i] << " ";
    }
    cout << endl;

    return 0;
}
