#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200003],b[200004];
bool f = false;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    int lst = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    int i = 1,j = 1;
    
    for (; i <= n;) {
        if (j <= m && a[i] == b[j]) lst = i,++i,++j;
        else if (a[i] == a[lst]) f = true,++i;
        else ++i;
    }
    // cout << j << ' ' << f << '\n';
    if (j == m+1 && f) puts("Yes");
    else puts("No");
    return 0;
}