#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = fMem(coins,amount,0,dp);
        return ans == INT_MAX ? -1 : ans;
    }
private:
    int f(vector<int>& coins, int amount, int ind){
        //Base Case
        if(amount == 0) return 0;
        if(ind >= coins.size()) return INT_MAX;

        //Explore Possibilities
            int notTaken = 0 + f(coins,amount,ind + 1);
            int taken = INT_MAX;
            if(coins[ind] <= amount){
                int res = f(coins, amount - coins[ind], ind);
                if (res != INT_MAX) taken = 1 + res; // Avoid overflow
            }
        return min(notTaken,taken);
    }
    int fMem(vector<int>& coins, int amount, int ind,vector<vector<int>> &dp){
        //Base Case
        if(amount == 0) return 0;
        if(ind >= coins.size()) return INT_MAX;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        //Explore Possibilities
            int notTaken = 0 + fMem(coins,amount,ind + 1,dp);
            int taken = INT_MAX;
            if(coins[ind] <= amount){
                int res = fMem(coins, amount - coins[ind], ind,dp);
                if (res != INT_MAX) taken = 1 + res; // Avoid overflow
            }
        return dp[ind][amount] = min(notTaken,taken);
    }
    
    int fTab(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], 1 + dp[j - coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};