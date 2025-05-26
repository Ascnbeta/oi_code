#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int n,a[maxn],ans;
int sumf[maxn],sumt[maxn],s,t;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i],sumf[i]=sumf[i-1]+a[i],s+=sumf[i];
    for (int i = n; i >= 1; i--) sumt[i]=sumt[i+1]+a[i],t+=sumt[i];
    // cout << s << ' ' << t << '\n';
    if (n == 1) puts("0");
    else if (abs(s-t)%2 != 0) puts("-1");
    else{
        int tmp = abs(s-t);
        if (tmp % (2*(n-1)) == 0) cout << tmp/(2*(n-1)) << '\n';
        else cout << tmp/(2*(n-1))+1 << '\n';
    }
    return 0;
}