#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 503;
const ll mod = 1e9+7;
int n,K;
string s;
ll f[maxn][maxn][6];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> K;
    cin >> s;s = ' ' + s;
    for (int i = 1; i <= n; i++) f[i][i-1][0] = 1;
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            if (len <= K) f[i][j][0] = f[i][j-1][0]&&(s[j]=='?'||s[j]=='*');
            if (len >= 2) {
                if ((s[i]=='?'||s[i]=='(')&&(s[j]=='?'||s[j]==')')) {
                    f[i][j][1] = (f[i+1][j-1][0]+f[i+1][j-1][2]+f[i+1][j-1][3]+f[i+1][j-1][4])%mod;
                }
                for (int k = i; k < j; k++) {
                    f[i][j][2] = (f[i][j][2]+f[i][k][3]*f[k+1][j][0]%mod)%mod;
                    f[i][j][3] = (f[i][j][3]+(f[i][k][2]+f[i][k][3])*f[k+1][j][1]%mod)%mod;
                    f[i][j][4] = (f[i][j][4]+(f[i][k][4]+f[i][k][5])*f[k+1][j][1]%mod)%mod;
                    f[i][j][5] = (f[i][j][5]+f[i][k][4]*f[k+1][j][0])%mod;
                }
                
            }
            f[i][j][3] = (f[i][j][3]+f[i][j][1]) %mod;
            f[i][j][5] = (f[i][j][5]+f[i][j][0]) %mod;
        }
    }
    cout << f[1][n][3] << '\n';
    return 0;
}