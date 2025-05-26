#include <bits/stdc++.h>
using namespace std;
const int maxn = 8002;
int n,T,ans;
int a[maxn];
int cnt[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i],cnt[i]=0;
        
        for (int i = 1; i <= n; i++) {
            memset(cnt,0,sizeof(cnt));
            for (int j = i; j <= n; j++) {
                cnt[a[j]]++;int tmp = 0;bool f = true;
                for (int k = 1; k <= n; k++) {
                    if (!tmp&&cnt[k]) {
                        tmp = cnt[k];
                    }else if(tmp&&cnt[k]&&cnt[k]!=tmp) {
                        f = false;
                        break;
                    }
                }
                if (f) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}