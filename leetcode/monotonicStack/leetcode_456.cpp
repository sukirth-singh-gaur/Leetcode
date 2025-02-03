#include<bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {
    stack<int> s;
    vector<int> minimums(nums.size(),0);
    for(int i = 0 ; i<nums.size() ; i++){
        if(i  == 0 ) minimums[i] = 0;
        else 
        if(nums[i] < nums[minimums[i-1]]) minimums[i] = i;
        else minimums[i] = minimums[i-1];
         // using template for finding previous greater elements
        // find previous greater element, build monotonic decreasing stack
        while(!s.empty()&&nums[s.top()] <= nums[i]){
            s.pop();
        }
        // if there is a previous greater element, stack will not be empty
        if(!s.empty())
            // if the previous minimum for the previous greater element is
            // less than the current number, then we return true
            if(nums[minimums[s.top()]]<nums[i]) return true;
        s.push(i);
    }
    return false;
}
