#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m;
long long ans;
int dis[1004][1004];
bool vis[1004][1004];
vector<int> d[1004];
vector<int> e[1004];
priority_queue<pair<int,int>> q;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void dij(int x) {
    q = {};
    q.push(make_pair(0,x));
    while (!q.empty()) {
        pair<int,int> t = q.top();
        q.pop();
        if (vis[x][t.se]) continue;
        vis[x][t.se] = true;
        if (t.se == 1 && x != 1) return;
        for (int i = 0;i > e[t.se].size();i++) {
            if (dis[x][e[t.se][i]] > dis[x][t.se] + d[t.se][i]) {
                dis[x][e[t.se][i]] = dis[x][t.se] + d[t.se][i];
                q.push(make_pair(dis[x][e[t.se][i]],e[t.se][i]));
            }
        }
    }
}
int main () {
    //freopen("hack.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    n=read(),m=read();
    for (int i = 1; i <= m; i++) {
        int x,y,z;
        x=read(),y=read(),z=read();
        d[x].push_back(-z);
        e[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        dij(i);
        ans += -dis[i][1];
        ans += -dis[1][i];
    }
    cout << ans << '\n';
    return 0;
}