#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
string s;int n;
int f[maxn],nxt[maxn];
inline void get_nxt() {
    nxt[1] = 0;
    for (int i = 2,j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i] == s[j+1]) ++j;
        nxt[i] = j;
    }
}
int b[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    n = s.size();
    s = ' ' + s;
    get_nxt();
    f[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        if (nxt[i] != 0 && b[f[nxt[i]]] >= i-nxt[i]) f[i] = f[nxt[i]];
        b[f[i]] = i;
    }
    cout << f[n] << '\n';
    return 0;
}