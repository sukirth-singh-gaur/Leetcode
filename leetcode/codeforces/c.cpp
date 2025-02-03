#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
using namespace std;
//Definition for a binary tree node.
int main(){
    stack<int> s;
    vector<int> nums = {6,0,8,1,3};
    vector<int> nges;
    for(int i = nums.size()-1 ; i >= 0 ; i--){
        while(!s.empty()&&s.top()<=nums[i]){
            s.pop();
        }
        if(s.empty()) nges.push_back(-1);
        else nges.push_back(s.top());
        s.push(nums[i]); 
    }
    reverse(nges.begin(), nges.end());
    for(auto it : nges){
        cout<<it<<" ";
    }
    return 0;
}