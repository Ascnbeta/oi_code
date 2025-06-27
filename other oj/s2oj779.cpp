#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e7+30;
int n,k; ll mod;
ll a,b,c,d;
int s[maxn],s1[maxn],s2[maxn];
ll ans = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k >> mod >> a >> b >> c >> d;
    s[1] = a;
    for (int i = 2; i <= n; i++) s[i] = (1ll*s[i-1]*b+c)%d;
    for (int i = 1; i <= n; i += k) {
        s1[i] = s[i];
        for (int j = i+1; j <= i+k-1 && j <= n; j++) {
            s1[j] = 1ll*s1[j-1]*s[j]%mod;
        }
    }
    for (int i = 1; i <= n; i += k) {
        s2[min(i+k-1,n)] = s[min(i+k-1,n)];
        for (int j = min(i+k-1,n)-1; j >= i && j >= 1; j--) {
            s2[j] = 1ll*s2[j+1]*s[j]%mod;
        }
    }
    for (int i = 1; i+k-1 <= n; i++) {
        int j = i + k - 1;
        if (j % k != 0) ans ^= 1ll*s2[i]*s1[j]%mod;
        else ans ^= 1ll*s1[j];
    }   
    cout << ans << '\n';
    return 0;
}