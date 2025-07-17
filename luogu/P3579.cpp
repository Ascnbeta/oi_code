#include <bits/stdc++.h>
using namespace std;
int T;
int a,b,c,d,ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        int ans = 1;
        for (int l = 1,r = 1; l <= min(b,d); l = r+1) {
            r = min(b/(b/l),d/(d/l));
            if (r*(b/r)>a-1&&r*(d/r)>c-1) ans = r;
        }
        cout << ans << '\n';
    }
    return 0;
}