#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
int n,ans;
signed main () {
    cin >> n;
    // for (int j = 1; j <= 100; j++) {
    //     n = j;
        ans = 0;
        int sqt = sqrtl(n);
        const int ni = binpow(6,mod-2);
        const int ni2 = binpow(2,mod-2);
        ans = 2*sqt*(sqt+1)%mod*(2*sqt+1)%mod*ni%mod;
        ans = ((ans-(1+sqt)*sqt%mod*ni2%mod*3%mod)%mod+mod) % mod;
        ans = (ans + sqt) % mod;
        ans = (ans + (n-sqt*sqt+1)%mod*(sqt)%mod)% mod;
        cout << (ans + mod) % mod << '\n';//70pts
    // }
    
    return 0;
}