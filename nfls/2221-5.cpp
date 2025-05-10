#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 354;
int h,w,seed,thd,tmp,ans;
int mp[maxn][maxn];
int suml[maxn][maxn],sumr[maxn][maxn];
bool f[maxn];
vector<int> v;
signed main () {
    #ifdef LOCAL
        freopen("D:/codes/exe/a.in","r",stdin);
        freopen("D:/codes/exe/a.out","w",stdout);
    #endif
    cin >> h >> w >> seed >> thd;
    tmp = seed;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            tmp = (tmp * 25173 + 13849) % 65536;
            if (tmp >= thd) mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) sumr[i][j] = sumr[i-1][j] + mp[i][j];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = i+2; j <= h; j++) {
            int cnt = 0;
            memset(f,0,sizeof(f));
            for (int k = 1; k <= w; k++) {
                if (mp[i][k] == mp[j][k] && mp[i][k] == 1) {
                    if (sumr[j][k]-sumr[i-1][k] == j-i+1) {
                        f[k] = true;
                        ans += cnt;
                        if (f[k-1]) --ans;
                        ++cnt;
                    }
                }else{
                    cnt = 0;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}