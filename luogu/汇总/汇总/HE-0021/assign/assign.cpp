#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define file(x, y) freopen(#x".in", "r", stdin); freopen(#y".out", "w", stdout);
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const LL mod = 1e9 + 7;

template <typename T> T R(T &x) {
    x = 0; bool f = 0; char c = getchar(); while (!isdigit(c)) f = c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); return x = f ? -x : x;
}
template <typename T, typename ...Tr> void R(T &x, Tr &...y) {R(x); R(y...);}

LL Pow(LL x, LL y, LL res = 1) {
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) res = res * x % mod;
    return res;
}

int n, m, v;
struct LIM {int pos, v;} lim[N];

int main() {
    file(assign, assign);

    int T; R(T); while (T--) {
        R(n, m, v);
        LL Val = 1ll * v * v % mod;
        rep(i, 1, m) R(lim[i].pos, lim[i].v);
        sort(lim + 1, lim + m + 1, [&](LIM A, LIM B) {
            return A.pos < B.pos;
        });
        bool fl = 0;
        rep(i, 2, m) if (lim[i].pos == lim[i - 1].pos && lim[i].v != lim[i - 1].v)
            {fl = 1; break;}
        if (fl) {puts("0"); continue;}
        LL ans = 0;
        ans = Pow(Val, lim[1].pos - 1);
        rep(i, 2, m) if (lim[i].pos != lim[i - 1].pos) {
            LL tmp = Pow(Val, lim[i].pos - lim[i - 1].pos);
            tmp = (tmp - Pow(v, lim[i].pos - lim[i - 1].pos - 1) * (v - 1) % mod + mod) % mod;
            ans = ans * tmp % mod;
        }
        ans = ans * Pow(Val, n - lim[m].pos) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}