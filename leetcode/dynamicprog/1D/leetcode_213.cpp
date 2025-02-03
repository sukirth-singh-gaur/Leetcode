#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0 ; i < n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1),f(temp2));
    }
    int f(vector<int>& nums){
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