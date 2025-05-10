#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt;
char s[203];
int c[202][102];bool f[202][102];
void dfs(int a,int b) {
    if (a > n+m || b > n) return;
    f[a][b] = true;
    if (!f[a+1][b]) c[a+1][b] = c[a][b] * (a+1) / (a-b+1) ,dfs(a+1,b);
    if (b < a && !f[a][b+1]) c[a][b+1] = c[a][b] * (a-b) / (b+1),dfs(a,b+1);
} 
signed main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) s[i] = 'a';
    for (int i = n+1; i <= n+m; i++) s[i] = 'z';
    c[1][1] = 1;
    dfs(1,1);
    int cnt = n;
    c[0][0] = 1;
    for (int i = 1; i <= n+m; i++) c[i][0] = 1,c[0][i] = 1;
    if (c[n+m][n] <= k) {
        cout << '\n';
        return 0;
    }
    for (int i = 1; i <= n+m; i++) {
        if ( cnt > 0 && c[n+m-i][cnt-1] > 0 && c[n+m-i][cnt-1] >= k) {
            s[i] = 'a';
            --cnt;
        }else{
            s[i] = 'z';
            k -= c[n+m-i][cnt-1];
        }
    }
    for (int i = 1; i <= n+m; i++) {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}