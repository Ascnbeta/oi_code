#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
ll h,x,y,z;
vector<pair<int,ll>> e[maxn];
ll dis[maxn];bool f[maxn];
struct node{
    int p;ll w;
    bool operator < (const node &y) const {
        return w > y.w;
    }
};
priority_queue<node> q;
inline void dijkstra() {
    for (int i = 0; i < x; i++) dis[i] = LONG_LONG_MAX;
    memset(f,0,sizeof(f));
    dis[0] = 0;
    q.push({0,0ll});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (f[t.p]) continue;
        f[t.p] = true;
        for (auto i : e[t.p]) {
            ll v = i.first,w = i.second;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({(int)v,dis[v]});
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> h >> x >> y >> z;
    --h;
    if (x > y) swap(x,y);
    if (y > z) swap(y,z);
    if (x > y) swap(x,y);
    assert(x<=y&&y<=z);
    for (int i = 0; i < x; i++) {
        e[i].push_back({(i+y)%x,y});
        e[i].push_back({(i+z)%x,z});
    }
    dijkstra();
    ll ans = 0;
    for (int i = 0; i < x; i++) {
        if (h >= dis[i]) ans += (h-dis[i])/x+1;
    }
    cout << ans << '\n';
    return 0;
}