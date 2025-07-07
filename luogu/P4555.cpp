#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
string s;int n;
int d[maxn<<1];
int maxl[maxn<<1],maxr[maxn<<1];
inline void manacher() {
    int id = 1,r = 0;
    for (int i = 1; i <= n; i++) {
        if (i < r) d[i] = min(r-i,d[id*2-i]);
        else d[i] = 1;
        while (s[i+d[i]]==s[i-d[i]]) ++d[i];
        if (i+d[i]>r) {
            r = d[i]+i;
            id = i;
        }
        maxl[i-d[i]+1] = max(maxl[i-d[i]+1],d[i]-1);
        maxr[i+d[i]-1] = max(maxr[i+d[i]-1],d[i]-1);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    s += '|';
    char ch;
    while (cin >> ch) {
        s += ch;
        s += '|';
    }
    n = s.size();
    s = ' ' + s;
    manacher();
    for (int i = 3; i <= n; i += 2) maxl[i] = max(maxl[i],maxl[i-2]-2);
    for (int i = n-2; i >= 1; i -= 2) maxr[i] = max(maxr[i],maxr[i+2]-2);
    int ans = 0;
    for (int i = 3; i <= n; i += 2) if (maxl[i]&&maxr[i]) ans = max(ans,maxl[i]+maxr[i]);
    cout << ans << '\n';
    return 0;
}