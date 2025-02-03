#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = f(amount,coins,0);
        return ans;
    }
private:
    int f(int amount, vector<int>& coins,int ind){
        if(ind == coins.size() && amount != 0) return 0;
        if(amount == 0){
            return 1;
        }
        int pick = 0;
        if(amount>=coins[ind])
            pick = f(amount - coins[ind],coins,ind);
        int notPick = f(amount,coins,ind+1);
        return pick + notPick;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = f(amount,coins);
        return ans;
    }
private:
    int f(int amount, vector<int>& coins){
        vector<vector<long>> dp(coins.size(),vector<long>(amount+1,0));
        for(int t = 0 ; t <= amount ; t++){
            dp[0][t] = (t % coins[0]==0);
        }
        for(int ind = 1 ; ind < coins.size() ; ind ++){
            for(int t = 0 ; t <= amount ; t++){
                long pick = 0;
                if(t>=coins[ind])
                    pick = dp[ind][t - coins[ind]];
                long notPick = dp[ind+1][t];
                dp[ind][t] = (pick + notPick)%INT_MAX;
            }
        }
        return dp[coins.size()-1][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = f(amount,coins);
        return ans;
    }
private:
    int f(int amount, vector<int>& coins){
        //vector<vector<long>> dp(coins.size(),vector<long>(amount+1,0));
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int t = 0 ; t <= amount ; t++){
            prev[t] = (t % coins[0]==0);
        }
        for(int ind = 1 ; ind < coins.size() ; ind ++){
            for(int t = 0 ; t <= amount ; t++){
                long pick = 0;
                if(t>=coins[ind])
                    pick = curr[t - coins[ind]];
                long notPick = prev[t];
                curr[t] = (pick + notPick)%INT_MAX;
            }
            prev = curr;
        }
        return prev[amount];
    }
};