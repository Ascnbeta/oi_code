#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,S,L,maxx;
int h[200005],a[200005],t[200005];
bool check (int x) {
    int tmp = S;
    for (int i = 1; i <= n; i++) {
        if (x >= t[i]) {
            tmp -= h[i];
            if (tmp <= 0) return true;
            for (int j = 1; j <= x; j++) {
                tmp -= a[i];
                if (tmp <= 0) return true;
            }
        }
        if (tmp <= 0) return true;
    }
    return false;
}
signed main() {
    cin >> n >> S >> L;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (L - h[i] <= 0) {
            continue;
        }
        if ((L - h[i]) % a[i] > 0) {
            t[i] = (L - h[i]) / a[i] + 1;
        }else{
            t[i] = (L - h[i]) / a[i];
        }
        maxx = max(t[i],maxx);
    }
    int l = -1,r = 1e18;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << r + 1 << endl;
    return 0;
}