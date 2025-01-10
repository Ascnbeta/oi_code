#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,maxx;
int w[500004];
bool check(int x) {
    int t = x;
    for (int i = 1; i <= n; i++) {
        if (ceil(1.0*w[i]/a) <= x) continue;
        else {
            if (t > 0) {
                int tmp = 0;
                bool f = false;
                while (t > 0) {
                    tmp += b;
                    --t;
                    if (ceil(1.0*(w[i]-tmp)/a) <= x) {
                        f = true;
                        break;
                    }
                }
                if (!f) return false;
            }else{
                return false;
            }
        }
    }
    return true;
}
signed main () {
    cin >> n >> a >> b;
    for (int i = 1; i <= n ;i++) {
        cin >> w[i];
        maxx = max(maxx,(int)ceil(1.0*w[i]/a));
    }
    int l = 1,r = maxx;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << r << '\n';
    return 0;
}