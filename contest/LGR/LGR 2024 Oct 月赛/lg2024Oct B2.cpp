#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int x1 = 1e18;
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while (T--) {
        cout << "? " << x1 << endl;
        int x;
        cin >> x;
        int l = 1, r = x1 - x;
        while (l < r) {
            int mid = ((l + r) >> 1);
            cout << "? " << mid << endl;
            cin >> x;
            if (x == mid) {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}