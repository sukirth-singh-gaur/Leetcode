#include<bits/stdc++.h>
using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int check=0;
        string mini=strs[0];
        int ans=-1;
        for(int i=0;i<mini.size();i++){
            int j=0;
            while(j<n){
            if(mini[i]!=strs[j][i]){
                check=1;
                break;
            }
            j++;
            }
            if(check==1){
                break;
            }
            ans=i;
        }
        if(ans!=-1) return mini.substr(0,ans+1);
        return "";
    }


int main(){
    vector<string> strs={"flower","flow","flight"};
    string ans=longestCommonPrefix(strs);
    cout<<ans<<endl;
    return 0;
}