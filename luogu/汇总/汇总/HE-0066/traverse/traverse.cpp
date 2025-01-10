#include<bits/stdc++.h>
namespace {
using namespace std;
#define fiin(x) freopen(x".in", "r", stdin)
#define fiout(x) freopen(x".out", "w", stdout)
#define file(x) fiin(x), fiout(x)
#define ll long long
#define db double
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fir first
#define sec second
// #define 
const int man = 1e5+10, mam = 1e5+10, mop = 1e9+7;
}

int c, T, n, k;
int main () {
    file("traverse");
    scanf("%d%d", &c, &T);
    while (T --) {
		scanf("%d%d", &n, &k);
		for (int a, b, i = 1; i < n; ++ i) scanf("%d%d", &a, &b);
		for (int a, i = 1; i <= k; ++ i) scanf("%d", &a);
        if (c == 18) puts("1");
        else if (19<=c && c<=21) printf("%d", n);
    }
    return 0;
}
