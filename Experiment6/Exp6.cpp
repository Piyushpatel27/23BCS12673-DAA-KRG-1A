#include<iostream>
#include <vector>
using namespace std;

// Function to check if a subset with given sum exists
bool isSubsetSum(const vector<int> &set, int n, int sum) {
    // Create a 2D DP table
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j]; // exclude element
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]; // include or exclude
        }
    }

    // Return result
    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    cout << "Enter the required sum: ";
    cin >> sum;

    if (isSubsetSum(set, n, sum))
        cout << "Subset with given sum exists.\n";
    else
        cout << "No subset with given sum exists.\n";

    return 0;
}
