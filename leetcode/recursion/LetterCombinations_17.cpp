#include<bits/stdc++.h>
using namespace std;

void recLett(vector<string>&ans,map<char,string>&mpp,string digits,string temp,int i){
    string value = mpp[digits[i]];
    if(i>=digits.length()){
        ans.push_back(temp);
        return;
    }
    for(int j =0 ;j<value.length();j++){
        temp.push_back(value[j]);
        recLett(ans,mpp,digits,temp,i+1);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    map<char,string> mpp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> ans;
    string temp;
    recLett(ans,mpp,digits,temp,0);
    return ans;
}

int main(){
    vector<string> ans = letterCombinations("23");
    for(auto it:ans){
        cout<<it<<endl;
    }
    return 0;
}