#include<bits/stdc++.h>
using namespace std;
//MEMOIZATION
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,nums.size()-1,dp);
    }
    int f(vector<int>& nums,int ind,vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return  0 ;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(nums,ind - 2,dp);
        int notPick = 0 + f(nums,ind - 1,dp);
        return dp[ind] = max(notPick,pick);
    }
};

//TABULATION
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,dp);
    }
    int f(vector<int>& nums,vector<int> &dp){
        dp[0] = nums[0];
        int neg = 0 ;
        for(int i = 1 ; i < nums.size() ; i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[nums.size()-1];
    }
};
//SPACE OPTIMAISATION
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,dp);
    }
    int f(vector<int>& nums,vector<int> &dp){
        int curr = -1;
        int prev = nums[0];
        int prev2 = 0 ;
        for(int i = 1 ; i < nums.size() ; i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int notPick = 0 + prev;
            curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};