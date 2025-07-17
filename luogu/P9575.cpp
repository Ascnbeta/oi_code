#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxv = 1e6+5;
int n,a[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0) {
        cout << 1 << '\n';
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) cout << 1;
            else cout << 0;
        }
    }else{
        int d = a[1];
        for (int i = 2; i <= n; i++) d = __gcd(d,a[i]);
        int cnt1 = 0,cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            a[i] /= d;
            if (a[i] % 2 == 0) ++cnt2;
            else ++cnt1;
        }
        if (cnt1 % 2 == 1) {
            cout << -1 << '\n';
        }else{
            cout << 2*d << '\n';
            int chs1 = 0,chs2 = 0; 
            for (int i = 1; i <= n; i++) {
                if (a[i] % 2 == 0) {
                    if (chs2 < cnt2/2) cout << 1,++chs2;
                    else cout << 0;
                }else{
                    if (chs1 < cnt1/2+1) cout << 1,++chs1;
                    else cout << 0;
                }
            }
        }
    }
    return 0;
}