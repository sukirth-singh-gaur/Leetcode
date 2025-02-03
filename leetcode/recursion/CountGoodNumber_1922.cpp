#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;
        if (n == 1) return x;

        if (n % 2 == 0) {
            long long half_power = power((x * x) % M, n / 2);
            return half_power % M;
        } else {
            return (x * power(x, n - 1)) % M;
        }
    }

    int countGoodNumbers(long long n) {
        if (n % 2 == 0) {
            return power(20, n / 2);
        } else {
            return (5 * power(20, n / 2)) % M;
        }
    }

int main(){
    int n = countGoodNumbers(5);
    cout<<n<<endl;
    return 0;
}
};