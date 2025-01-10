#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int cnt = 0,ans = 1;
    for (int i = 2; i <= 2000000000; i++) {
        if (is_prime(i)) ++ans;
    }
    cout << ans << endl;
    return 0;
}