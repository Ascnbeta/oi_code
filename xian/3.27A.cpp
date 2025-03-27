#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[103];
vector<int> fac;
int n,p;
inline void solve(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                fac.push_back(i);
                x /= i;
            }
        }
    }
    if (x != 1) fac.push_back(x);
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> p;
    s[0] = 0,s[1] = 1;
    for (int i = 2; i <= n; i++) s[i] = (2*s[i-1]%p+s[i-2]%p)%p;
    cout << s[n] << '=';
    solve(s[n]);
    sort(fac.begin(),fac.end());
    for (int i = 0; i < fac.size(); i++) {
        if (i == fac.size()-1) cout << fac[i] << '\n';
        else cout << fac[i] << '*';
    }
    return 0;
}