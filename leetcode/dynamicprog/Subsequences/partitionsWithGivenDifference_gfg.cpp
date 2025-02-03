#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countPartitions(vector<int>& arr, int d) {
        // Code here
            int target = 0 ;
            for(int num : arr){
                target+=num;
            }
            if(target - d < 0 || (target - d)%2 != 0) return 0;
            target = (target - d) / 2;
            vector<vector<int>> dp (arr.size(),vector<int>(target+1,0));
            int ans = f(arr.size()-1,target,arr,dp);
            return ans;
        }
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0)
        return 1;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notTaken = f(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = f(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken + taken % (int)(1e9 + 7);
}
};
