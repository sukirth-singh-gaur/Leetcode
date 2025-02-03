#include<bits/stdc++.h>
using namespace std;

void createSubsets(vector<int> &nums,int index,vector<vector<int>> &ans,vector<int>&subset){
    ans.push_back(subset);
    for(int  i= index;i<nums.size();i++){
        subset.push_back(nums[i]);
        createSubsets(nums,i+1,ans,subset);
        subset.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> subset;
    createSubsets(nums,0,ans,subset);
    return ans;
}

int main(){
    vector<int> s ={1,2,3};
    vector<vector<int>> ans = subsets(s);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}