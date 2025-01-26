#include <bits/stdc++.h>
#define int long long
using namespace std;
int k,n,e,d,m;
signed main () {
    cin >> k;
    while (k--) {
        cin >> n >> e >> d;
        m = n - e * d + 2;
        int l = 1,r = m / 2;
        bool f = false;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid * (m - mid) == n) {
                cout << mid << ' ' << m - mid << '\n';
                f = true;
                break;
            }else if (mid * (m - mid) > n){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if (!f) {
            cout << "NO" << '\n';
        }
    }
    return 0;
}