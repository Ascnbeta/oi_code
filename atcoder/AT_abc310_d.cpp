#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,a[104],b[104],o[15],num[15];
int ans;
void solve(int x,int cur) {
    if (n - x + 1 < t - cur) return;
    if (x == n + 1) {
        for (int i = 1; i <= m; i++) {
            if (o[a[i]] == o[b[i]]) return;
        }
        ++ans;
        return;
    }
    for (int i = 1; i <= t; i++) {
        if (num[i] > 0) {
            o[x] = i;
            num[i]++;
            solve(x+1,cur);
            num[i]--;
        }else{
            o[x] = i;
            num[i]++;
            solve(x+1,cur+1);
            num[i]--;
        }
    }
}
signed main () {
    cin >> n >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    solve(1,0);
    for (int i = 1; i <= t; i++) {
        ans /= i;
    }
    cout << ans << '\n';
    return 0;
}