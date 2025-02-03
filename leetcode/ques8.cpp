#include<bits/stdc++.h>
using namespace std;

// int myAtoi(string s){
//     int num=0;
//     int i=0;
//     while(s[i]==' ')i++;
//     int sign=1;
//     if(s[i]=='+'||s[i]=='-'){
//         s[i]=='-'?sign=-1:sign=1;
//         i++;
//     }
//     while(isdigit(s[i])){
//         int digit=(s[i]-'0');
//         if(num>(INT_MAX-digit)/10){
//             return(sign==1)?INT_MAX:INT_MIN;
//         }
//         num=(num*10)+digit;
//         i++;
//     }
//     return num * sign;
// }
//IMPLEMENTING RECURSIVELY 
int sign =1;
int atoi(string s,int ans,int i,int sign){
    if(s[i]=='+'||s[i]=='-'){
        s[i]=='-'?sign=-1:sign=1;
        if(!isdigit(s[i+1])) return ans*sign;
        return atoi(s,ans,i+1,sign);
    }
    else if(!isdigit(s[i])) return ans * sign;
    else{
        int digit=(s[i]-'0');
        if(ans>(INT_MAX-digit)/10){
            return(sign==1)?INT_MAX:INT_MIN;
        }
        ans=(ans*10)+digit;
        return atoi(s,ans,i+1,sign);
    }

}
int myAtoi(string s) {
    int i=0;
    while(s[i]==' ')i++;
    int ans= atoi(s,0,i,sign);
    return ans;
}

int main(){
    string s="42";
    int ans=myAtoi(s);
    cout<<ans<<endl;
    return 0;
}