#include<bits/stdc++.h>
using namespace std;

int minimumPushes(string word){
    unordered_map<char,int> map;
    for(char c:word){
        map[c]++;
    }
    vector<pair<int,char>> v(map.size());
    int i=0;
    for(auto it : map){
        v[i].first=it.second;
        v[i].second=it.first;
        i++;
    }
    sort(v.begin(),v.end(),greater<pair<int,char>>());
    int count=0;
    int pushes=0;
    int var=1;
    for(auto it:v){
        if(count>0&&count%8==0){
            var++;
        }
        for(int i=0;i<it.first;i++){
            pushes=pushes+var*1;
        }
        count++;
    }
    return pushes;   
}

int main(){
    string word="aabbccddeeffgghhiiiiii";
    int ans = minimumPushes(word);
    cout<<ans<<endl;
    return 0;
}