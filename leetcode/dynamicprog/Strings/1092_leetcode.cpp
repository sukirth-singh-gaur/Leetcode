#include<bits/stdc++.h>
using namespace std;

    string f(string &str1, string &str2,vector<vector<int>> &dp){
        int n = str1.size();
        int m = str2.size();
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string sss = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
                if(str1[i - 1]==str2[j - 1]){
                    sss += str1[i - 1];
                    i--;
                    j--;
                }
                else if(dp[i-1][j]>dp[i][j-1]){
                    sss += str1[i-1];
                    i--;
                }
                else{
                    sss += str2[j-1];
                    j--;
                }
        }
        while(i > 0) {
            sss += str1[i - 1];
            i--;
        }
        while(j > 0){
            sss += str1[j - 1];
            j--;
        }    
        reverse(sss.begin(),sss.end());
        return sss;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1,vector<int> (m + 1,0));
        string sss = f(str1,str2,dp);
        return sss;
    }


    int main(){
        string str1 = "brute";
        string str2 = "groot";
        string ans = shortestCommonSupersequence(str1,str2);
        cout<<ans<<endl;
        return 0;
    }
