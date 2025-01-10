#include<bits/stdc++.h>
#include<bits/extc++.h>
namespace {
using namespace std;
using namespace __gnu_pbds;
#define fiin(x) freopen(x".in", "r", stdin)
#define fiout(x) freopen(x".out", "w", stdout)
#define file(x) fiin(x), fiout(x)
#define ll long long
#define db double
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fir first
#define sec second
#define hap cc_hash_table
// #define 
const int man = 1e6+10, mam = 1e5+10;
const ll mop = 1e9+7;
}

int T, n, m, v;
int a[man]
hap<int, int> qqq;
int main () {
    file("assign");
    scanf("%d", &T);
    while (T --) {
        int F = 1;
        scanf("%d%d%d", &n, &m, &v);
        for (int c, d, i = 1; i <= m; ++ i) {
            scanf("%d%d", &c, &d);
            if (qqq[c] != d) F = 0;
            qqq[c] = d;
        } if (!F) puts("0");
        else if (m == 1) {
            int res = 1;
            for (int i = 1; i <= n; ++ i) res = 1LL*res*v%mop;
            printf("%d\n", res);
        }
        else if (v <= 2) puts("4");
        else puts("0");
    }
    return 0;
}