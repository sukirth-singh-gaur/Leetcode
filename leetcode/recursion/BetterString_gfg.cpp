#include<bits/stdc++.h>
using namespace std;

int noOfStr(string str){
    vector<int> last(256,-1);
    vector<int> dp(str.size()+1,0);
    dp[0]=1;

    for(int i = 1;i<=str.size();i++){
        dp[i] = 2 * dp[i-1];

        if(last[str[i-1]]!=-1) dp[i]=dp[i] - dp[last[str[i-1]]];

        last[str[i-1]] = (i-1);
    }

    return dp[str.size()];
}

string betterString(string str1, string str2) {
        string ans;
        int a = noOfStr(str1);
        int b = noOfStr(str2);
        return (a<b)?str2:str1;  
}

int main(){
    string str1="gfg";
    string str2="ggg";
    string ans=betterString(str1,str2);
    cout<<ans<<endl;
    return 0;
}