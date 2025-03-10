#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) cout << 0 << '\n';
        else{
            cout << (1+(2*(n-1)-1))*(n-1)/2*3+2*n-2 << '\n';
        }
    }
    return 0;
}