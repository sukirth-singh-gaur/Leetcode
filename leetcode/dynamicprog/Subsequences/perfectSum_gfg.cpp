#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int perfectSum(vector<int>& nums, int target) {
            
        }
        int f(vector<int>& nums, int target,int index){
            if(index == 0){
                return 1;
            }
        }
};


class Solution {
  public:
    int perfectSum(vector<int>& nums, int target) {
        int m = 1e9 + 7;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

        // Base case: A sum of 0 can always be formed using the empty subset
        for (int i = 0; i < nums.size(); i++) dp[i][0] = 1;

        // Initialize for the first element
        if (nums[0] <= target) dp[0][nums[0]] += 1;

        // Fill DP Table
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                int include = (nums[i] <= j) ? dp[i - 1][j - nums[i]] : 0;
                int exclude = dp[i - 1][j];
                dp[i][j] = (include + exclude) % m;
            }
        }

        return dp[nums.size() - 1][target];
    }
};
