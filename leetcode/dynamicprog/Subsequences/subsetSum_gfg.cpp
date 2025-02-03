#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int ansf = f(arr,target,0);
        return ansf == 1;
    }
    private:
    int f(vector<int>& arr, int target,int ind){
        if(target == 0) return 1;
        if(ind >= arr.size() || target < 0) return 0;
        int include =  f(arr,target - arr[ind],ind+1);
        int exclude =  f(arr,target,ind+1);
        return include || exclude;
    }
};

class Solution {
    public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
        int ansf = f(arr,target,0,dp);
        return ansf == 1;
    }
    private:
    int f(vector<int>& arr, int target,int ind,vector<vector<int>> &dp){
        if(target == 0)  return dp[ind][target] = 1;
        if(ind >= arr.size() || target < 0) return 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        int include =  f(arr,target - arr[ind],ind+1,dp);
        int exclude =  f(arr,target,ind+1,dp);
        return dp[ind][target] = include || exclude;
    }
};

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // Initialize DP table
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, 0));

        // Base case: If target is 0, subset always exists
        for (int i = 0; i < arr.size(); i++) {
            dp[i][0] = 1;
        }

        // Base case: For the first element, it can only form a subset if it's equal to the target
        if (arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        // Populate DP table
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 1; j <= target; j++) {
                int exclude = dp[i - 1][j];
                int include = 0;
                if (arr[i] <= j) {
                    include = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = include || exclude;
            }
        }

        // Final answer
        return dp[arr.size() - 1][target];
    }
};
