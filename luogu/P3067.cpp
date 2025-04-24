#include <bits/stdc++.h>
using namespace std;
const int maxn = 22;
int n,n1,a[maxn];
unordered_map<int,int> mp;
int tot,cal[1<<maxn];
vector<int> t[1<<maxn];
inline void dfs1(int cur,int sum,int v) {
    if (cur > n1) {
        if (mp.find(sum) == mp.end()) {
            mp[sum] = ++tot;
        }
        t[mp[sum]].push_back(v);
        return;
    }
    dfs1(cur+1,sum,v);
    dfs1(cur+1,sum+a[cur],v|(1<<(cur-1)));
    dfs1(cur+1,sum-a[cur],v|(1<<(cur-1)));
}
inline void dfs2(int cur,int sum,int v) {
    if (cur > n) {
        if (mp.find(sum) != mp.end()) {
            int pt = mp[sum];
            for (auto i : t[pt]) {
                cal[i|v] = 1;
            }
        }
        return;
    }
    dfs2(cur+1,sum,v);
    dfs2(cur+1,sum+a[cur],v|(1<<(cur-1)));
    dfs2(cur+1,sum-a[cur],v|(1<<(cur-1)));
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    n1 = n/2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs1(1,0,0);
    dfs2(n1+1,0,0);
    int ans = 0;
    for (int i = 1; i < (1<<n); i++) ans += cal[i];
    cout << ans << '\n';
    return 0;
}