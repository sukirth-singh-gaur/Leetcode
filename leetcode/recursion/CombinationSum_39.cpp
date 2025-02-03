#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

void dfs(int index,int remaining,vi &candidates,vvi &ans,vi &temp){
    if(remaining==0){
        ans.push_back(temp);
        return;
    }
    if(index>=candidates.size()|| remaining<candidates[index]){
        return;
    }
    dfs(index+1,remaining,candidates,ans,temp);
    temp.push_back(candidates[index]);
    dfs(index,remaining-candidates[index],candidates,ans,temp);
    temp.pop_back();
}

vvi combinationSum(vi &candidates,int target){
    //sort(candidates.begin(),candidates.end());
    vvi ans;
    vi temp;
    dfs(0,target,candidates,ans,temp);
    return ans;
}

int main(){
    vi candidates ={2,3,6,7};
    vvi ans = combinationSum(candidates,7);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
