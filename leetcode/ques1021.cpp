#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
        string ans;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(count!=0){
                ans=ans+'(';
                }
                count++;
            }
            else if(s[i]==')'){
                if(count!=1){
                ans=ans+')';
                }
                count--;
            }
        }
        cout<<count<<endl;
        return ans;
}
int main(){
    string s="(()())(())";
    string ans=removeOuterParentheses(s);
    cout<<ans<<endl;
}