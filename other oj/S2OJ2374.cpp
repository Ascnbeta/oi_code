#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int q,cur,tot;
vector<int> a;
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        char op;int x;
        cin >> op;
        if (op == 'I') {
            cin >> x;
            if (cur == tot) a.push_back(x);
            else a.insert(a.begin()+cur,x);
            ++cur,++tot;
        }else if(op == 'D') {
            a.erase(a.begin()+cur-1);
            --cur,--tot;
        }else if(op == 'L') {
            if (cur > 0) cur--;
        }else if(op == 'R') {
            if (cur < tot) ++cur;
        }else if(op == 'Q') {
            cin >> x;
            int sum = 0,ans = LONG_LONG_MIN;
            for (int i = 0; i <= x-1; i++) {
                sum += a[i];
                ans = max(ans,sum);
            }
            cout << ans << '\n';
        }
        // for (auto v : a) {
        //     cout << v << ' ';
        // }
        // cout << '\n';
        // cout << cur << '\n';
    }
    return 0;
}