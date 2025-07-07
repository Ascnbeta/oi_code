#include <bits/stdc++.h>
using namespace std;
int N,M,mod;
string s;
int nxt[24];
inline void get_nxt() {
    nxt[1] = 0;
    for (int i = 2,j = 0; i <= M; i++) {
        while (j > 0 && s[i] != s[j+1]) j = nxt[j];
        if (s[i] == s[j+1]) ++j;
        nxt[i] = j;
    }
}
struct matrix {
    int n,m,a[23][23];
    inline void clear(int _n,int _m) {
        n = _n,m = _m;
        memset(a,0,sizeof(a));
    }
    inline void print(int _n,int _m) {
        for (int i = 0; i <= _n; i++) {
            for (int j = 0; j <= _m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        } 
    }
    matrix operator + (const matrix &y) const{
        assert(n==y.n&&m==y.m);
        matrix c = y;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                c.a[i][j] += a[i][j];
                c.a[i][j] %= mod;
            }
        }
        return c;
    }
    matrix operator * (const matrix &y) const{
        assert(m==y.n);
        matrix c;c.clear(n,m);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++) {
                    c.a[i][j] += a[i][k] * y.a[k][j] % mod;
                    c.a[i][j] %= mod;
                }
            }
        }
        return c;
    }
}f,g;
inline matrix binpow(matrix base,int b) {
    matrix ret;ret.clear(base.n,base.m);
    for (int i = 0; i <= ret.n; i++) {
        ret.a[i][i] = 1;
    } 
    // ret.print(ret.n,ret.n);
    while (b) {
        if (b&1) ret = ret * base;
        base = base * base;
        b >>= 1;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> N >> M >> mod >> s;
    s = ' ' + s;
    get_nxt();
    // for (int i = 1; i <= M; i++) cout << nxt[i] << ' ';
    // cout << '\n';
    f.clear(0,M-1);
    f.a[0][0] = 1;
    g.clear(M-1,M-1);
    for (int i = 0; i <= M-1; i++) {
        for (int j = 0; j <= 9; j++) {
            int tmp = i;
            while (tmp > 0 && s[tmp+1] != j+'0') tmp = nxt[tmp];
            if (s[tmp+1] == j+'0') ++tmp;
            if (tmp < M) g.a[i][tmp]++;
        } 
    }
    // g.print(M-1,M-1);
    matrix ret = f*binpow(g,N);
    // ret.print(M-1,M-1);
    int ans = 0;
    for (int i = 0; i < M; i++) ans = (ans + ret.a[0][i]) % mod;
    cout << ans << '\n';
    return 0;
}