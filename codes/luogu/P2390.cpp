#include <bits/stdc++.h>
using namespace std;
int t,n,ans,now;
int a[50003];
bool check(int x) {
    for (int r = n; r >= x; r--) {
        int l = r - x + 1;
        if (a[l] >= 0) {
            if (a[r] <= t) return true;
        }else if (a[r] <= 0) {
            if (-1*a[l] <= t) return true;
        }else{
            if (min(-1*a[l]+a[r]-a[l],a[r]+a[r]-a[l]) <= t) return true;
        }
    }
    return false;
}
int main () {
    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l = -1, r = n + 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << l - 1<< endl;
    return 0;
}