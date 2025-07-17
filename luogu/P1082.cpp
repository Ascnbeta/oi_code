#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void exgcd(ll a,ll b,ll &x,ll &y) {
    if (b == 0) {
        x = 1,y = 0;
        return;
    }
    exgcd(b,a%b,y,x);
    y -= a/b*x;
}
ll a,b;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> a >> b;
    ll X,Y;
    exgcd(a,b,X,Y);
    X %= b;X = (X+b)%b;
    cout << X << '\n';
    return 0;
}