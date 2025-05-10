#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 354;
int h,w,seed,thd,tmp;
int mp[maxn][maxn];
int suml[maxn][maxn],sumr[maxn][maxn];
signed main () {
    cin >> h >> w >> seed >> thd;
    tmp = seed;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            tmp = (tmp * 25173 + 13849) % 65536;
            if (tmp >= thd) mp[i][j] = 0;
            else mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) suml[i][j] = suml[i][j-1] + mp[i][j];
    }
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= h; i++) sumr[i][j] = sumr[i-1][j] + mp[i][j];
    }
    for (int i = 1; i <= h; i++) {
        
    }
    return 0;
}