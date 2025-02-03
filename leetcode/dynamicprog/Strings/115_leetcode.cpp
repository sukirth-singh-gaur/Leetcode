#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return f(n-1,m-1,s,t);
    }
    int f(int i, int j, string &s, string &t){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(s[i] == t[j]){
            return f(i - 1, j - 1, s, t) + f(i - 1, j,s,t);
        }
        else{
            return f(i-1,j,s,t);
        }
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        const long long MOD = 1e9 + 7;
        //vector<vector<int>> dp (n + 1,vector<int>(m + 1,0));
        vector<int> prev (m + 1,0);
        vector<int> curr (m + 1,0);
        curr[0] = 1;
        prev[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i - 1] == t[j - 1]) curr[j] =  (prev[j-1] + prev[j]) % MOD;
                else curr[j] = prev[j] % MOD;
            }
            prev = curr;
        }
        return prev[m];
    }
};