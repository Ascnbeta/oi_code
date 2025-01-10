#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x;
struct dz{
    int l,a[100005];
}d[2];
vector<int> ans;
queue<int> q;
signed main () {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> d[i&1].l;
        for (int j = 1; j <= d[i&1].l; j++) {
            cin >> d[i&1].a[j];
        }
        if (i == 1) {
            for (int j = 1; j <= d[i&1].l; j++) {
                q.push(d[i&1].a[j]);
            }
        }else{
            int s = q.size();
            for (int j = 0; j < s; j++) {
                for (int k = 1; k <= d[i&1].l; k++) {
                    if (q.front() * d[i&1].a[k] > x || q.front() * d[i&1].a[k] < 0) continue;
                    q.push(q.front() * d[i&1].a[k]);
                }
                q.pop();
            }
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        if (q.front() == x) ++cnt;
        q.pop();
    }
    cout << cnt << '\n';
    return 0;
}