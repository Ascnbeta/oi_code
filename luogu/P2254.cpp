#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,x,y,K;
char mp[203][203];
struct zone{
    int s,t,d;
}z[203];
int f[203][203][203],ans;
deque<int> q;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> x >> y >> K;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> mp[i][j];
    }
    for (int i = 1; i <= K; i++) cin >> z[i].s >> z[i].t >> z[i].d;
    memset(f,0xc0,sizeof(f));
    f[0][x][y] = 0;
    for (int i = 1; i <= K; i++) {
        if (z[i].d == 1) {
            for (int j = 1; j <= m; j++) {
                q = {};
                for (int k = n; k >= 1; k--) {
                    if (mp[k][j] == 'x') {q={};continue;}
                    while (!q.empty()&&f[i-1][q.back()][j]+q.back()<=f[i-1][k][j]+k) q.pop_back();
                    while (!q.empty()&&q.front()-k>z[i].t-z[i].s+1) q.pop_front();
                    q.push_back(k);
                    f[i][k][j] = f[i-1][q.front()][j]+q.front()-k;
                    ans = max(ans,f[i][k][j]);
                }
            }
        }else if(z[i].d == 2) {
            for (int j = 1; j <= m; j++) {
                q = {};
                for (int k = 1; k <= n; k++) {
                    if (mp[k][j] == 'x') {q={};continue;}
                    while (!q.empty()&&f[i-1][q.back()][j]-q.back()<=f[i-1][k][j]-k) q.pop_back();
                    while (!q.empty()&&k-q.front()>z[i].t-z[i].s+1) q.pop_front();
                    q.push_back(k);
                    f[i][k][j] = f[i-1][q.front()][j]-q.front()+k;
                    ans = max(ans,f[i][k][j]);
                }
            }
        }else if(z[i].d == 3) {
            for (int j = 1; j <= n; j++) {
                q = {};
                for (int k = m; k >= 1; k--) {
                    if (mp[j][k] == 'x') {q={};continue;}
                    while (!q.empty()&&f[i-1][j][q.back()]+q.back()<=f[i-1][j][k]+k) q.pop_back();
                    while (!q.empty()&&q.front()-k>z[i].t-z[i].s+1) q.pop_front();
                    q.push_back(k);
                    f[i][j][k] = f[i-1][j][q.front()]+q.front()-k;
                    ans = max(ans,f[i][j][k]);
                }
            }
        }else if(z[i].d == 4) {
            for (int j = 1; j <= n; j++) {
                q = {};
                for (int k = 1; k <= m; k++) {
                    if (mp[j][k] == 'x') {q={};continue;}
                    while (!q.empty()&&f[i-1][j][q.back()]-q.back()<=f[i-1][j][k]-k) q.pop_back();
                    while (!q.empty()&&k-q.front()>z[i].t-z[i].s+1) q.pop_front();
                    q.push_back(k);
                    f[i][j][k] = f[i-1][j][q.front()]-q.front()+k;
                    ans = max(ans,f[i][j][k]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}