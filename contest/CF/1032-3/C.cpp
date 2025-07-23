#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5+5;
int T;
int n,m;

int cntn[maxn],cntm[maxn];
inline bool check(int x,vector<vector<int>> &a) {
    for (int i = 1; i <= n; i++) cntn[i] = 0;
    for (int i = 1; i <= m; i++) cntm[i] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]-x>1) return false;
            else if (a[i][j]-x==1) {
                cntn[i]++,cntm[j]++,++cnt;
            }
        }
    }
    if (!cnt) return true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cntn[i]+cntm[j]-(a[i][j]-x==1)==cnt) return true;
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<vector<int>> a(n+1);
        for (int i = 1; i <= n; i++) {
            a[i].push_back(0);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x;cin >> x;
                a[i].push_back(x);
            }
        }
        int l = 0,r = 102,ans = r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid,a)) {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}