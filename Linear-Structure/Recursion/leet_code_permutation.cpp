#include <vector>
#include <iostream>
using namespace std;

void permut(vector<int>& vec, vector<vector<int>>& permu, int idx) {
    if (idx == vec.size()) {
        permu.push_back(vec); 
        return;
    }

    for (int i = idx; i < vec.size(); i++) {
        swap(vec[i], vec[idx]);
        permut(vec, permu, idx + 1);
        swap(vec[i], vec[idx]);
    }
}

vector<vector<int>> permutation(vector<int>& vec) {
    vector<vector<int>> permu;
    permut(vec, permu, 0);
    return permu;
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> result = permutation(vec);

    
    for (auto& v : result) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
