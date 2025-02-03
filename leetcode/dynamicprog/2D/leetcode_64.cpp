#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return f(m-1,n-1,grid);
    }
    int f(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0) {
            return 1;
        }
        if(i<0 || j<0) return INT_MAX;
        int left = f(i,j-1,grid);
        int up =  f(i-1,j,grid);
        int mini = min(left,up);
        return grid[i][j] + mini;
    }
};
