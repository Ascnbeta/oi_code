#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6+50;
const ll mod = 1e9+7;
int T,n;
string s;
ll nxt[maxn],num[maxn];
ll ans;
inline void getnxt() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i]==s[j+1]) ++j;
        nxt[i] = j,num[i] = num[j]+1;
    }
}
inline void getnum() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i]==s[j+1]) ++j;
        if (j*2 > i) j = nxt[j];
        ans = ans*(num[j]+1)%mod;
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        ans = 1;
        cin >> s;
        n = s.size();
        s = ' ' + s;
        memset(nxt,0,sizeof(nxt));
        memset(num,0,sizeof(num));
        num[1] = 1;
        getnxt();
        getnum();
        cout << ans << '\n';
    }
    return 0;
}