#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s,string t){
    unordered_map<char,char>tTos;
    unordered_map<char,char>sTot;
    for(int i=0;i<s.size();i++){
        if((sTot.find(s[i])!=sTot.end()&&sTot[s[i]]!=t[i])
        ||(tTos.find(t[i])!=tTos.end()&&tTos[t[i]]!=s[i])) 
            return false;
    
        sTot[s[i]]=t[i];
        tTos[t[i]]=s[i];
    }
    return true;
}

int main(){
    string s="egg";
    string t="add";
    bool ans =isIsomorphic(s,t);
    cout<<ans<<endl;
}
