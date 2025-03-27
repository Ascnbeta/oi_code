#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,a,b,c,d;
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        if (a < b || b > d) {
            puts("No");
        }else{//a>=b b<=d
            if (b-1 <= c) {
                puts("Yes");
            }else{//b > c
                a %= b;
                int gcd = __gcd(b,d);
                int x = (b-1-a)/gcd*gcd;
                if ((a+x)%b > c) puts("No");
                else puts("Yes");
            }
        }
    }
    return 0;
}