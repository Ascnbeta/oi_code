#include <bits/stdc++.h>
using namespace std;
int n;
int nxt[1000005];
string s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s;
    s = ' ' + s;
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i] == s[j+1]) ++j;
        nxt[i] = j;
    }
    cout << n - nxt[n] << '\n';
    return 0;
}