#include<bits/stdc++.h>
using namespace std;

void generate(int opens,int closes,int n,vector<string>&ans,string &temp){
    if(opens==n&&closes==n){
        ans.push_back(temp);
        return;
    }
    if(opens<n){
        temp+='(';
        generate(opens+1,closes,n,ans,temp);
        temp.pop_back();
    }
    if(opens>closes){
        temp+=')';
        generate(opens,closes+1,n,ans,temp);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string temp;
    generate(0,0,n,ans,temp);
    return ans;
}

int main(){
    vector<string> ans = generateParenthesis(3);
    for(auto it : ans){
        cout<< it << endl;
    }
    return 0;
}