#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+20;
int n,k,ans;
int a[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k != 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) ++ans;
        }
    }else{
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}