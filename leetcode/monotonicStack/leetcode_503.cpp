#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> arr = nums;
    vector<int> nextGreaterIndexes(arr.size(),-1);
    stack<int> s ;
    for(int j = 0 ; j<2 ; j++)
    for(int i = 0 ; i  <arr.size() ; i++){
        while(!s.empty()&&arr[s.top()]<arr[i]){
            nextGreaterIndexes[s.top()] = i ;
            s.pop();
        }
        s.push(i);
    }
    vector<int> ans(nums.size(),-1);
    for(int i = 0; i<nums.size() ; i++){
        if(nextGreaterIndexes[i]>-1)
            ans[i] = arr[nextGreaterIndexes[i]];
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1};
    vector<int> ans = nextGreaterElements(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;   
}