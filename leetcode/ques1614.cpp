#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s){
    int count=0;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            count++;
        }
        if(s[i]==')'){
            ans=max(ans,count);
            count--;
        }
    }
    return ans;
}

int main(){
    string s="()(())((()()))";
    int ans=maxDepth(s);
    cout<<ans<<endl;
    return 0;
}