#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = f(nums,target,0);
    }
private:
    int f(vector<int>& nums, int target,int ind){
        //Base Case
        if(ind == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        //Explore Possibilties
        int add =  nums[ind] + f(nums,target - nums[ind],ind + 1);
        int sub = - nums[ind] + f(nums,target + nums[ind],ind + 1);
        return add + sub;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> mpp;
        int ans = f(nums,target,0,mpp);
        return ans;
    }
private:
    int f(vector<int>& nums, int target,int ind,map<pair<int,int>,int> &mpp){
        //Base Case
        if(ind == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        //Explore Possibilties
        if(mpp.find({ind,target}) != mpp.end()) return mpp[{ind,target}];
        int add =  nums[ind] + f(nums,target - nums[ind],ind + 1,mpp);
        int sub = - nums[ind] + f(nums,target + nums[ind],ind + 1,mpp);
        return mpp[{ind,target}] = add + sub;
    }
};

