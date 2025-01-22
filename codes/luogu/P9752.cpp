#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a,b,c,d,e;
bool f[13][13][13][13][13];
int down(int x) {
    x -= 1;
    if (x < 0) x = 9;
    return x;
}
int up(int x) {
    x += 1;
    if (x > 9) x = 0;
    return x;
}
void solve(int o,int p,int q,int r,int s) {
    f[o][p][q][r][s] = false;
    f[down(o)][down(p)][q][r][s] = false;
    f[up(o)][up(p)][q][r][s] = false;
    f[o][down(p)][down(q)][r][s] = false;
    f[o][up(p)][up(q)][r][s] = false;
    f[o][p][down(q)][down(r)][s] = false;
    f[o][p][up(q)][up(r)][s] = false;
    f[o][p][q][down(r)][down(s)] = false;
    f[o][p][q][up(r)][up(s)] = false;
    //1+1
    for (int j = 0; j <= 9; j++) f[j][p][q][r][s] = false;
    for (int j = 0; j <= 9; j++) f[o][j][q][r][s] = false;
    for (int j = 0; j <= 9; j++) f[o][p][j][r][s] = false;
    for (int j = 0; j <= 9; j++) f[o][p][q][j][s] = false;
    for (int j = 0; j <= 9; j++) f[o][p][q][r][j] = false;
    //n
}
int main () {
    cin >> n;
    memset(f,1,sizeof(f));
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d >> e;
        solve(a,b,c,d,e);
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    for (int m = 0; j <= 9; m++) {
                        if (f[i][j][k][l][m]) ++ans;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}