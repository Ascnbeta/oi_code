#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10,maxa = 1e6+5;
int T;
int n,a[maxn],f[maxn][3],pos[maxa],c[maxn],lr,lb;// 1 -> r 2 -> b
int main () {
    cin >> T;
    while (T--) {
        cin >> n;
        memset(f,0,sizeof(f));
        memset(pos,0,sizeof(pos));
        memset(c,0,sizeof(c));
        lr = lb = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            if (pos[a[i]] == 0) {
                pos[a[i]] = i;
                f[i][1] = f[i][2] = max(f[i-1][1],f[i-1][2]);
                continue;
            }else{
                if (lr <= pos[a[i]]) {
                    if (c[pos[a[i]]] == 0) {
                        c[pos[a[i]]] = c[i] = 1;
                        
                    }
                }
            }
        }
    }
    return 0;
}