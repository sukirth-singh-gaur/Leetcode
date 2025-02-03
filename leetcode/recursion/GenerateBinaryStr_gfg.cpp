#include<bits/stdc++.h>
using namespace std;

void generate(int num,int index,vector<string>&ans,string &sub){
    ans.push_back(sub);
    for(int i=index;i<num;i++){
        if(sub[i-1]=='1') continue;
        sub[i]='1';
        generate(num,i+1,ans,sub);
        sub[i]='0';
    }
}

vector<string> generateBinaryStrings(int num){
    string sub;
    for(int i=0;i<num;i++){
        sub+="0";
    }
    //cout<<sub;
    vector<string> ans;
    generate(num,0,ans,sub);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int num=3;
    vector<string> ans=generateBinaryStrings(num);
    for(auto it : ans){
        cout<< it<< endl;
    }
    return 0;
}