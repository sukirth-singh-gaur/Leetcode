#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

void subsets(vi & nums,int i,vi & temp,vvi & ans){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
        if(i<j&&nums[j]==nums[j-1]) continue;
        temp.push_back(nums[j]);
        subsets(nums,j+1,temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vvi ans;
    vi temp;
    sort(nums.begin(),nums.end());
    subsets(nums,0,temp,ans);
    return ans;
}

int main(){
    vi nums ={1,2,2};
    vvi ans = subsetsWithDup(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}