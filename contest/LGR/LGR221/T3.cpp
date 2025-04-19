#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+40;
int n,m,ans;
string s;
int tv[maxn],tn[maxn];
inline int lowbit(int x) {
    return x & (-x);
}
inline void modifyv(int p,int x) {
    assert(p);
    while (p <= n) {
        tv[p] += x;
        p += lowbit(p);
    }
}
inline void modifyn(int p,int x) {
    assert(p);
    while (p <= n) {
        tn[p] += x;
        p += lowbit(p);
    }
}
inline int queryv(int p) {
    int ret = 0;
    while (p > 0) {
        ret += tv[p];
        p -= lowbit(p);
    }
    return ret;
}
inline int queryn(int p) {
    int ret = 0;
    while (p > 0) {
        ret += tn[p];
        p -= lowbit(p);
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'v') modifyv(i,1);
        if (s[i] == 'n') modifyn(i,1);
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') ans += queryv(i-1)*(queryn(n)-queryn(i));
    }
    while (m--) {
        int x;
        cin >> x;
        if (s[x] == s[x+1]) {
            cout << ans << '\n';
            continue;
        }
        if (s[x] == 'v') {
            if (s[x+1] == 'n') {
                modifyv(x,-1);
                modifyv(x+1,1);
                modifyn(x,1);
                modifyn(x+1,-1);
            }else{
                ans -= queryn(n)-queryn(x+1);
                modifyv(x,-1);
                modifyv(x+1,1);
            }
        }
        if (s[x] == 'n') {
            if (s[x+1] == 'v') {
                modifyv(x,1);
                modifyv(x+1,-1);
                modifyn(x,-1);
                modifyn(x+1,1);
            }else{
                ans += queryv(x);
                modifyn(x,-1);
                modifyn(x+1,1);
            }
        }
        if (s[x] == 'a') {
            if (s[x+1] == 'v') {
                ans += queryn(n)-queryn(x+1);
                modifyv(x,1);
                modifyv(x+1,-1);
            }else{
                ans -= queryv(x);
                modifyn(x,1);
                modifyn(x+1,-1);
            }
        }
        swap(s[x],s[x+1]);
        cout << ans << '\n';
    }
    return 0;
}