#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5+20;
int n;
int a[maxn],b[maxn];
int cnt[maxn];
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i],b[i] = a[i];
    sort(b+1,b+n+1);
    int n1 = unique(b+1,b+n+1)-b-1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b+1,b+n1+1,a[i])-b;
        cnt[a[i]]++;
    }
    int tmp = 0,ans = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 1) {
            if (a[i] > tmp) tmp = a[i],ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}