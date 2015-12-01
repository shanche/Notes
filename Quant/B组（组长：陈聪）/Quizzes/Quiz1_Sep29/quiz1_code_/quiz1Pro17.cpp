#include<iostream>
using namespace std;

float maxProfit(float prices[], int size) {
    if (size <= 1) return 0.0;
    float profit = 0.0;
    for (int i = 1; i < size; i++) {
        float diff = prices[i] - prices[i-1];
        if (diff > 0.0) {
            profit += diff;
        }
    }
}

int main() {
    float prices[4] = {1.2,3.2,2.5,4.6};
    int size = 4;
    float profit = maxProfit(prices, 4);
    cout << "profit is " << profit << endl;
    return 0;
}