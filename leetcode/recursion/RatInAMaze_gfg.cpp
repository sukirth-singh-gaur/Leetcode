#include<bits/stdc++.h>
using namespace std;

void recAns(vector<vector<int>> &mat,vector<string>&ans,int row,int col,string temp,vector<vector<bool>>& visited){
    if(row==mat.size()-1&&col==mat.size()-1&&mat[row][col] == 1){
        ans.push_back(temp);
        return;
    }
    if(row==mat.size()||col==mat.size()||row<0||col<0||visited[row][col]||mat[row][col]==0)
        return;
    visited[row][col] = true;
    recAns(mat,ans,row,col+1,temp +'R',visited);
    recAns(mat,ans,row,col-1,temp +'L',visited);
    recAns(mat,ans,row+1,col,temp +'D',visited);
    recAns(mat,ans,row-1,col,temp +'U',visited);
    visited[row][col]=false;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    vector<vector<bool>> visited(mat.size(),vector<bool>(mat.size(), false));
    recAns(mat,ans,0,0,"",visited);
    return ans;
}

int main(){
    vector<vector<int>> mat =
        {{1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    for(auto it : ans){
        cout<<it<<endl;
    }
}