#include<bits/stdc++.h>
using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights) {
    vector<int> nextGreaterIndex (heights.size(),-1);
    vector<int> ans(heights.size(),0);
    stack<int> s;
    for(int i = 0;i<heights.size();i++){
        while(!s.empty()&& heights[s.top()] < heights[i]){
            ans[s.top()]++;
            nextGreaterIndex[s.top()] = i;
            s.pop();
        }
        if(!s.empty()){
            ans[s.top()]++;
        }
        s.push(i);
    }
    for(int num : nextGreaterIndex){
        cout<<num<<" ";
    }
    cout<<endl;
    // for(int i = 0 ; i < heights.size() ; i++){
    //     if(nextGreaterIndex[i] == -1){
    //         ans[i] = heights.size() - i - 1;
    //     }
    //     else if (nextGreaterIndex[i] - i == 1){
    //         ans[i] = nextGreaterIndex[i] - i;
    //     }
    //     else{
    //         ans[i] = nextGreaterIndex[i] - i - 1;
    //     }
    // }
    return ans ;
}


int main(){
    vector<int> nums = {10,6,8,5,11,9};
    vector<int> ans = canSeePersonsCount(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    //cout<<ans;
    cout<<endl;
    return 0;   
}