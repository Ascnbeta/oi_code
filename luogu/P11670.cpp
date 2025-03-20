#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+30;
int n,ans,maxx = 0;
int a[maxn],b[maxn];
vector<int> v[maxn],sum1[maxn],sum2[maxn];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        v[b[i]].push_back(i);
        maxx = max(maxx,b[i]);
    }
    for (int i = 1; i <= maxx; i++) {
        if (v[i].size() == 0) continue;
        for (int j = 0; j < v[i].size(); j++) {
            if (j != 0) sum1[i].push_back(sum1[i][j-1]+v[i][j]);
            else sum1[i].push_back(v[i][j]);
        }
        for (int j = v[i].size() - 1; j >= 0; j--) {
            if (j != v[i].size() - 1) sum2[i].push_back(sum2[i][j+1]+(n-v[i][j]+1));
            else sum2[i].push_back(n-v[i][j]+1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[a[i]].size() == 0) continue;
        int pos = upper_bound(v[a[i]].begin(),v[a[i]].end(),i)-v[a[i]].begin()-1;
        int pos2 = lower_bound(v[a[i]].begin(),v[a[i]].end(),n+1-i)-v[a[i]].begin();
        if (v[a[i]][pos] == i) {
            ans += i*(i-1)/2 + (n-v[a[i]][pos]+1)*(n-v[a[i]][pos])/2;
        }
        if (pos < pos2) ans += sum1[a[i]][pos] + sum2[a[i]][pos2] + (pos2-pos)*i;
        else if (pos > pos2) ans += sum1[pos2] + sum2[pos] + (pos-pos2)*(n-i+1);
        else ans += sum1[pos] + sum2[pos2] - i;
        // cout << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}