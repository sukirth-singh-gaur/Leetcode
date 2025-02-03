#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define ll long long
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
}

int main(){
    vector<vector<char>> box = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>> ans = rotateTheBox(box);
    for(int i = 0 ; i<ans.size() ; i++){
        for(int j = 0; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}