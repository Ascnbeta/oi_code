#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+30;
string s,t;
int n,m,ans;
int nxt[maxn];
inline void solve() {
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j > 0 && t[i] != t[j+1]) j = nxt[j];
        if (t[i] == t[j+1]) j++;
        nxt[i] = j;
    }
}
stack<int> st;
int pnt[maxn];
bool f[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s >> t;
    n = s.size(),m = t.size();
    s = ' ' + s,t = ' ' + t;
    solve();
    // cout << nxt[m] << '\n';
    for (int i = 1,j = 0; i <= n; i++) {
        if (st.empty()) j = 0;
        else j = pnt[st.top()];
        // if (!st.empty()) cout << st.top() << '\n';
        while (j > 0 && (j == m || s[i] != t[j+1])) j = nxt[j];
        if (s[i] == t[j+1]) ++j;
        // cout << j << ' ';
        pnt[i] = j;
        st.push(i);
        if (j == m) {
            for (int k = 1; k <= m; k++) f[st.top()] = true,st.pop();
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) cout << s[i];
    }
    cout << '\n';
    return 0;
}