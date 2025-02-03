#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        vector<vector<int>> dp(price.size(),vector<int>(price.size()+1,-1));
        int rodLen = price.size();
        int ans = f(price,rodLen,rodLen-1,dp);
        return ans;
    }
    int f(vector<int> &price,int rodLen,int ind,vector<vector<int>> &dp){
        //Base Case
        if(ind == 0){
            return rodLen * price[0];
        }
        //Explore Possibilities
        if(dp[ind][rodLen] != -1) return dp[ind][rodLen];
        int notTake = 0 + f(price,rodLen,ind - 1,dp);
        int Take = INT_MIN;
        if(ind + 1 <= rodLen)
            Take = price[ind] + f(price,rodLen - ind - 1,ind,dp);
        return dp[ind][rodLen] = max(notTake,Take);
    }
};