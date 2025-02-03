#include<bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

void rec(vi & nums,vvi & ans,vi & temp,int k,int n,int i){
    if(i==nums.size()){
        if(n==0 && temp.size()==k)
            ans.push_back(temp);
        return;
    }
    if(n>=nums[i]){
        temp.push_back(nums[i]);
        rec(nums,ans,temp,k,n-nums[i],i+1);
        temp.pop_back();
    }
    rec(nums,ans,temp,k,n,i+1);
}
vector<vector<int>> combinationSum3(int k, int n) {
    vi nums = {1,2,3,4,5,6,7,8,9};
    vvi ans;
    vi temp;
    rec(nums,ans,temp,k,n,0);
    return ans;
}

int main(){
    vvi ans = combinationSum3(3,7);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}