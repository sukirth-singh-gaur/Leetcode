#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0 ;
        for(int num : nums){
            target += num;
        }
        if(target%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(target/2 +1,-1));
        int ans = f(nums,target/2,0,dp);
        return ans == 1;
    }
    int f(vector<int> &nums, int target ,int index,vector<vector<int>>&dp){
        //base case
        if(index>=nums.size()||target < 0) return 0;
        if(target == 0) return 1;
        if(dp[index][target] != -1) return dp[index][target] ;
        //pick not pick
        int include = 0;
        if(nums[index] <= target) include = f(nums,target - nums[index],index + 1,dp);
        int exclude = f(nums,target,index + 1,dp);
        return dp[index][target] = include || exclude;
    }
};