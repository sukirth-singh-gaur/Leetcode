#include<bits/stdc++.h>
using namespace std;

double pow(double x, int n){
    if(n==1) return x;
    if(n==0) return 1;
    if(n%4==0) return pow(x*x,n/4)* pow(x*x,n/4);
    if(n%2==0) return pow(x*x,n/2);
    else return x * pow(x,n-1);
}

double myPow(double x,int n){
    if(n>=0){
        return pow(x,n);
    }
    else{
        return 1.0/pow(x,-(long)n);
    }
}

int main(){
    double x=2.0000;
    int n= 10;
    double ans = myPow(x,n);
    cout<<ans<<endl;
    return 0;
}