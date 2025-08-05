#include <iostream>
#include <vector>
using namespace std;

int numberOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
    int n = fruits.size();
    int m = basket.size();
    vector<bool> place(m, false);
    int unplaced = 0;

    for (int i = 0; i < n; i++) {
        bool placed = false;

        for (int j = 0; j < m; j++) {
            if (!place[j] && fruits[i] <= basket[j]) {
                place[j] = true;
                placed = true;
                break;
            }
        }

        if (!placed) {
            unplaced++;
        }
    }

    return unplaced;
}

int main() {
    vector<int> fruits = {4, 2, 5};
    vector<int> basket = {3, 4};

    int result = numberOfUnplacedFruits(fruits, basket);
    cout << "Unplaced fruits: " << result << endl;

    return 0;
}
