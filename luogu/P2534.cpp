#include <bits/stdc++.h>
using namespace std;
int n,r[20];
double h(string s) {
    int cnt = 0;
    for (int i = 1; i < s.size()-1; i++) {
        if (abs(s[i]-s[i+1])!=1)++cnt;
    }
    return 1.0*cnt;
}
struct node{
    string s;double v;int cnt;
    bool operator < (const node &y) const{
        if (v == y.v) return cnt > y.cnt;
        return v > y.v;
    }
};
string ans;
int maxdep = 0;
void dfs(string t,double v,int cnt) {
    if (cnt > maxdep || cnt+v > maxdep) return;
    if (t == ans) {
        cout << maxdep << '\n';
        exit(0);
    }
    for (int j = 2; j <= n; j++) {
        string tmp = t;
        for (int k = 1; k <= 1+(j-1+1)/2-1; k++) swap(tmp[k],tmp[j-(k-1)]);
        dfs(tmp,h(tmp),cnt+1);
    }
}
string t;int b[102];

int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i],b[r[i]] = i;
    int cnt = 0;
    for (int i = 1; i <= 100; i++) if (b[i]) r[b[i]] = ++cnt;
    for (int i = 1; i <= n; i++) t += r[i] + '0';
    t = ' ' + t;
    for (int i = 1; i <= n; i++) ans += '0'+i;
    ans = ' ' + ans;
    // cout << ans << '\n';
    for (; ;maxdep++) {
        dfs(t,h(t),0);
    }
    return 0;
}