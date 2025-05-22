#include <iostream>
#include <vector>
using namespace std;

int buy_and_sell(vector<int>& vec) {
    int maxProfit = 0;
    int bestBuy = vec[0];

    for (int i = 1; i < vec.size(); i++) {
        // Calculate potential profit
        int profit = vec[i] - bestBuy;
        maxProfit = max(maxProfit, profit);
        // Update bestBuy to the lowest price seen so far
        bestBuy = min(bestBuy, vec[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> vec = {2, 4, 1, 6, 4, 3, 6};

    int result = buy_and_sell(vec);
    cout << "Maximum profit from buying and selling stock: " << result << endl;

    return 0;
}
