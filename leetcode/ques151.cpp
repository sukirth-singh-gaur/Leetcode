#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    string ans;
    int n=s.size();
    int wordStart=-1;
    for(int i=n-1;i>=0;i--){
        if(isalpha(s[i])||(s[i]>=48&&s[i]<=57)){
            if(wordStart==-1)
                wordStart=i;
            if(i==0 || (s[i-1]==' ')){
                //cout<<s[wordStart]<<" "<<s[wordEnd]<<endl;
                for(int j=i;j<=wordStart;j++){
                    ans+=s[j];
                }
                wordStart=-1;
                ans+=' ';
            }
        }
    }
    ans.pop_back();
    return ans;
}
int main(){
    string s=" 3c      2zPeO dpIMVv2SG    1AM       o       VnUhxK a5YKNyuG     x9    EQ  ruJO       0Dtb8qG91w 1rT3zH F0m n G wU";
    string ans=reverseWords(s);
    cout<<s<<endl;
    cout<<ans<<endl;
}