#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    long long ans;
    if (n % 2 == 0) ans = (n/2+1)*(n/2+1);
    else if (n % 2 == 1) ans = (n/2+1)*(n/2+1)+n/2+1;
    cout << ans << '\n';
    return 0;
}