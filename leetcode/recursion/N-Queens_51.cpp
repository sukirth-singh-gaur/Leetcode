#include<bits/stdc++.h>
using namespace std;
#define vvs vector<vector<string>>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vector<int>>

bool CanPlace(vector<string> & board,int row,int col){
    for(int i=row;i>=0;i--)
        if(board[i][col]=='Q') return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]=='Q') return false;
    for(int i=row,j=col;i>=0&&j<board.size();i--,j++)
        if(board[i][j]=='Q') return false;
    return true;
}

void queens(vector<vector<string>> & result,vector<string>&board,int row){
    if(row==board.size()){
        result.push_back(board);
        return;
    }

    for(int j=0;j<board.size();j++){
        if(CanPlace(board,row,j)==1){
            board[row][j] = 'Q';
            queens(result,board,row+1);
            board[row][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    if(n<=0) return {{}};
    vector<string> board(n,string(n,'.'));
    vvs result;
    queens(result,board,0);
    return result;
}

int main(){
    vvs ans;
    ans = solveNQueens(4);
    for(int i =0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
