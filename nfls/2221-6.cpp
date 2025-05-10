#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e2+30;
int n;
int a[maxn],b[maxn],g[maxn],l[maxn];
int mul[maxn][maxn],gcd[maxn][maxn],lcm[maxn][maxn];
signed main () {
    cin >> n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i],++a[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i],++b[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> g[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) {
        if (l[i] % g[i] != 0) {
            puts("Solution does not exist");
            return 0;
        }
        if (!mul[a[i]][b[i]]) {
            mul[a[i]][b[i]] = g[i]*l[i];
            gcd[a[i]][b[i]] = g[i];
            lcm[a[i]][b[i]] = l[i];
        }else if(mul[a[i]][b[i]] != g[i] * l[i] || gcd[a[i]][b[i]] != g[i] || lcm[a[i]][b[i]] != l[i]) {
            puts("Solution does not exist");
            return 0;
        }
    }
    
    puts("Solution exists");
    return 0;
}