#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e3+10;
int n,m,x;
int a[maxn][maxn];
int val[maxn][maxn],sum[maxn][maxn];
struct node{
    int pt[maxn],w,cst,minn;
    bool operator < (const node &y) const{
        return w > y.w;
    }
    node() {
        memset(pt,0,sizeof(pt));
        w = cst = minn = 0;
    }
};
priority_queue<node> q;
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[j][i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        sort(a[i]+1,a[i]+n+1);
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i][j-1] + a[i][j];
            val[i][j] = sum[i][j] + (n-j)*a[i][j];
        }
        ans += val[i][n];
    }
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // } 
    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << val[i][j] << ' ';
    //     }
    //     cout << '\n';
    // } 
    node tmp;
    for (int i = 1; i <= m; i++) tmp.pt[i] = n,tmp.cst += a[i][n];
    tmp.w = ans,tmp.minn = n;
    q.push(tmp);
    ans = 0;
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (t.cst <= x) {
            cout << t.w << '\n';
            return 0;
        }
        if (t.pt[1] == 2 && t.pt[2] == 1 && t.pt[3] == 1 && t.pt[4] == 1 && t.pt[5] == 1) assert(0);
        for (int i = 1; i <= m; i++) {
            if (t.pt[i] >= 1) {
                
                node p = t;
                p.pt[i]--;
                p.minn = min(p.pt[i],p.minn);
                p.cst -= a[i][t.pt[i]];
                p.cst += a[i][p.pt[i]];
                p.w -= val[i][t.pt[i]];
                p.w += val[i][p.pt[i]];
                if (p.cst <= x) p.w += (x-p.cst)*(n-p.minn);
                assert(p.pt[i]>=0);
                q.push(p);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}