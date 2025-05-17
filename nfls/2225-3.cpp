#include <bits/stdc++.h>
using namespace std;
const int maxn = 53;
string s;
bool f[maxn][10][10][2];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') s[i] = '1';
        else if(s[i] != '?') s[i] = '0';
    }
    f[0][0][0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k <= 5; k++) {
                for (int l = 0; l <= 1; l++) {
                    if (!f[i][j][k][l]) continue;
                    if (s[i+1] == '1') {
                        f[i+1][min(j+1,3)][0][j+1>=3||l] = true;
                    }else if(s[i+1] == '0') {
                        f[i+1][0][min(k+1,5)][k+1>=5||l] = true;
                    }else{
                        f[i+1][0][min(k+1,5)][k+1>=5||l] = true;
                        f[i+1][min(j+1,3)][0][j+1>=3||l] = true;
                    }
                }
            }
        }
    }
    bool ug = false,ni = false;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 5; j++) {
            ni |= f[n][i][j][0];
            ug |= f[n][i][j][1];
        }
    }
    if (ug && ni) {
        puts("42");
    }else if (ni) {
        puts("NICE");
    }else {
        puts("UGLY");
    }
    return 0;
}