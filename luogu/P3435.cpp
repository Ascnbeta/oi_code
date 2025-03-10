#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+30;
int n;
string s;
int nxt[maxn],st[maxn];
long long ans = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s;
    s = ' ' + s;
    nxt[1] = 0;
    for (int i = 2,j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i] == s[j+1]) ++j;
        nxt[i] = j;
    }
    for (int i = 2,j = 2; i <= n; i++,j = i) {
        while (nxt[j]) j = nxt[j];
        if (nxt[i]) nxt[i] = j;
        ans += i - j;
    }
    cout << ans << '\n';
    return 0;
}