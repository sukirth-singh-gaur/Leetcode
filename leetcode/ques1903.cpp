#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num){
    int ans=-1;
    int n=num.size();
    int tonum=0;
    int digit=0;
    for(int i=0;i<n;i++){
        tonum=10*tonum+(num[i]-48);
        if(tonum%2!=0){
            ans=max(tonum,ans);
            digit=i;
        }
    }
    //cout<<ans<<endl;
    num="";
    if(ans==-1){
        return num;
    }
    for(int i=0;i<=digit;i++){
        num+=(ans%10+48);
        ans/=10;
    }
    reverse(num.begin(),num.end());
    return num;
}

int main(){
    string s="3547234";
    string ans=largestOddNumber(s);
    cout<<ans<<endl;
}