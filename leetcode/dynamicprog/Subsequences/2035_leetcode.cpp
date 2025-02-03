#include<bits/stdc++.h>
using namespace std;
// This solution only works for all positive arrays
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int target = 0;
        for(int num : nums){
            target += num;
        }
        vector<vector<int>> dp (nums.size(),vector<int>(target + 1,-1));
        f(nums,target,dp);
        int mini = INT_MAX;
        for(int i = 0 ; i < target/2 ; i++){
            if(dp[nums.size() - 1][i] == 1){
                int s1 = i;
                int s2 = target - s1;
                mini = min(abs(s1 - s1),mini);
            }
        }
        return mini;
    }
private:
    void f(vector<int> nums,int target,vector<vector<int>> &dp){
        for(int i = 0 ; i < nums.size() ; i++) dp[i][0] = 1;
        if(nums[0] <= target) dp[0][nums[0]] = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = 1 ; j <= target ; j++ ){
                int include = false;
                if(nums[i] <= j) include = dp[i - 1][j - nums[i]];
                int exclude = dp[i-1][j];
                dp[i][j] = include || exclude;
            }
        }
    }
};