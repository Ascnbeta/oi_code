#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+40;
int n,k;
struct line{
    int l,r,id;
    bool operator < (const line &y) const{
        return r > y.r;
    }
}l[maxn];
bool cmp1(const line x,const line y) {
    return x.l < y.l;
}
priority_queue<line> q;
int ans = -1,aid;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> l[i].l >> l[i].r,l[i].id = i;
    sort(l+1,l+n+1,cmp1);
    for (int i = 1; i <= n; i++) {
        if (q.size() < k) q.push(l[i]);
        else if (l[i].r > q.top().r) q.pop(),q.push(l[i]);
        if (q.size() < k) continue;
        int tmp = q.top().r- l[i].l;
        tmp = max(tmp,0);
        if (tmp > ans) {
            ans = tmp;
            aid = i;
        }
    }
    cout << ans << '\n';
    q = {};
    for (int i = 1; i <= n; i++) {
        if (q.size() < k) q.push(l[i]);
        else if (l[i].r > q.top().r) q.pop(),q.push(l[i]);
        if (q.size() < k) continue;
        if (aid == i) {
            while (!q.empty()) cout << q.top().id << ' ',q.pop();
            return 0;
        }
    }
    return 0;
}