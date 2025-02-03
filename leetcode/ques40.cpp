#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

    void getCombination(int i,int target,vi &ds,vvi &ans,vi &candidates){
       
            if(target==0){
                ans.push_back(ds);
            return;
            }
        
        for(int j=i;j<candidates.size();j++){
            if(j>i&&candidates[j-1]==candidates[j]) continue;
        if(candidates[j]<=target){
            ds.push_back(candidates[j]);
            getCombination(j+1,target-candidates[j],ds,ans,candidates);
            ds.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vi ds;
        vvi ans;
        sort(candidates.begin(),candidates.end());
        getCombination(0,target,ds,ans,candidates);
        return ans;
    }

int main(){
    vi candidates={10,1,2,7,6,1,5};
    int target = 8;
    vvi ans = combinationSum2(candidates,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}