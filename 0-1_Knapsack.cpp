#include <iostream>
using namespace std;
// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int W, int weights[], int profits[], int n) {
    int dp[n + 1][W + 1]; // DP table
    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + profits[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int n, W;
    // Input number of items
    cout << "Enter the number of items: ";
    cin >> n;
    int weights[n], profits[n];
    // Input weights and profits
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }
    // Input capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    // Calculate and display the maximum profit
    cout << "Maximum value in Knapsack: " << knapsack(W, weights, profits, n) << endl;
    return 0;
}