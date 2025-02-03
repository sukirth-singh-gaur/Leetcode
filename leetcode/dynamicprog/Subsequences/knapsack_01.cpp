#include<bits/stdc++.h>
using namespace std;

int fMem(vector<int> weight, vector<int> value, int ind, int maxWeight,vector<vector<int>> &dp){
    //Base Case
    if(ind == 0){
        if(weight[ind] <= maxWeight) return value[0];
        else return 0;
    }
    //Explore possibilities
    if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];
    int notTake = 0 + fMem(weight,value,ind-1,maxWeight,dp);
    int take = INT_MIN;
    if(weight[ind] <= maxWeight) 
        take = value[ind] + fMem(weight,value,ind-1,maxWeight - weight[ind],dp);
    return dp[ind][maxWeight] = max(take,notTake);
}

int fTab(vector<int> weight, vector<int> value, int maxWeight, vector<vector<int>> &dp) {
    // Initialize the first row
    for (int i = 0; i <= maxWeight; i++) {
        dp[0][i] = (weight[0] <= i) ? value[0] : 0;
    }

    // Fill the DP table
    for (int i = 1; i < weight.size(); i++) {
        for (int j = 0; j <= maxWeight; j++) {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (weight[i] <= j) 
                take = value[i] + dp[i - 1][j - weight[i]];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[weight.size() - 1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    // Initialize the DP table
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // Compute the result using tabulation
    int ans = fTab(weight, value, maxWeight, dp);
    return ans;
}


int main(){
    int T = 1; 
    int N = 4;
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int W = 5;
    int ans = knapsack(weight,value,N,W);
    cout<<ans;
}