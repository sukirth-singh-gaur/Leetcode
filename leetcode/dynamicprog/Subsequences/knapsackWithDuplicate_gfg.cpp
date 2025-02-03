#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // Initialize the DP table
        vector<vector<int>> dp(wt.size(), vector<int>(capacity + 1, -1));
        // Compute the result using recursion with memoization
        int ans = f(wt, val, capacity, wt.size() - 1, dp);
        return ans;
    }
private:
    int f(vector<int>& wt, vector<int>& val, int capacity, int ind, vector<vector<int>>& dp) {
        // Base Case
        if (ind == 0) {
            if (wt[ind] <= capacity) return int(capacity/wt[0]) * val[ind];
            return 0;
        }

        // Return the cached result if it exists
        if (dp[ind][capacity] != -1) return dp[ind][capacity];

        // Do not take the current item
        int notTake = 0 + f(wt, val, capacity, ind - 1, dp);

        // Take the current item (if it fits within the capacity)
        int take = INT_MIN;
        if (wt[ind] <= capacity) 
            take = val[ind] + f(wt, val, capacity - wt[ind], ind , dp);

        // Store the result and return the maximum of the two options
        return dp[ind][capacity] = max(take, notTake);
    }
};
