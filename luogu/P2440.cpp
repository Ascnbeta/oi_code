#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,maxx;
int a[100004];
int check(int x) {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += a[i] / x;
    }
    return tmp;
}
signed main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxx = max(maxx,a[i]);
    }
    int l = 1,r = maxx;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid) >= k) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << l - 1 << '\n';
    return 0;
}