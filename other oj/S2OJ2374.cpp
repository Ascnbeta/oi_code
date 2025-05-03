#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int q,cur,tot;
vector<int> a;
stack<int> s1,s2;
int sum[maxn],ans[maxn];
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> q;
    ans[0] = LONG_LONG_MIN;
    for (int i = 1; i <= q; i++) {
        char op;
        cin >> op;
        if (op == 'I') {
            int val;
            cin >> val;
            s1.push(val);
            sum[s1.size()] = sum[s1.size()-1] + val;
            ans[s1.size()] = max(ans[s1.size()-1],sum[s1.size()]);
        }else if (op == 'D') {
            s1.pop();
        }else if (op == 'L') {
            if (s1.empty()) continue;
            s2.push(s1.top());
            s1.pop();
        }else if (op == 'R') {
            if (s2.empty()) continue;
            s1.push(s2.top());
            s2.pop();
            sum[s1.size()] = sum[s1.size()-1] + s1.top();
            ans[s1.size()] = max(ans[s1.size()-1],sum[s1.size()]);
        }else {
            int k;
            cin >> k;
            cout << ans[k] << '\n';
        }
    }
    return 0;
}