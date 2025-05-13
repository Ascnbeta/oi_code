#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,k,ans = 0x3f3f3f3f;
string s;
int posj[maxn],poso[maxn],posi[maxn];
int totj,toto,toti;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'J') posj[++totj] = i;
        if (s[i] == 'O') poso[++toto] = i;
        if (s[i] == 'I') posi[++toti] = i;
    }
    int po = 1,pi = 1;
    for (int i = 1; i <= totj; i++) {
        if (i+k-1 > totj) break;
        int ed = posj[i+k-1];
        while (poso[po] <= ed && po <= toto) ++po;
        if (po+k-1 > toto) break;
        ed = poso[po+k-1];
        while (posi[pi] <= ed && pi <= toti) ++pi;
        if (pi+k-1 > toti) break;
        ans = min(ans,posi[pi+k-1]-posj[i]+1-3*k);
    }
    if (ans == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}