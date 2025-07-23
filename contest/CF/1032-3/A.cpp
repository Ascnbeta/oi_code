#include <bits/stdc++.h>
using namespace std;
int T;
int n,s;
int x[12];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (s <= x[1]) cout << x[n]-s << '\n';
        else if (s >= x[n]) cout << s-x[1] << '\n';
        else {
            cout << min(s-x[1],x[n]-s)+x[n]-x[1] << '\n';
        }
    }
    return 0;
}