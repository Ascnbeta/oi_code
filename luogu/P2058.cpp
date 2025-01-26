#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct cst{
    int t,x;
};
queue<cst> q;
int cty[100005];
int tr[300005];
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k,t;
        cin >> t >> k;
        while (!q.empty() && q.front().t <= t - 86400) {
            cty[q.front().x]--;
            if (cty[q.front().x] == 0) --ans;
            q.pop();
        }
        // << q.size() << ' ';
        for (int j = 1; j <= k; j++) {
            cin >> tr[j];
            q.push(cst{t,tr[j]});
            if (cty[tr[j]] == 0) {
                ++ans;
            }
            cty[tr[j]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}