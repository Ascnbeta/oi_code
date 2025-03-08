#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
vector<pair<int,int>> v;
int ans;
int n;
signed main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int x,y;
            cin >> x >> y;
            v.push_back(make_pair(x,y));
            ans += x;
        }
        if (op == 1) {
            int x,y;
            cin >> x >> y;                                                                                                                                                                                                                                                                                                           
            bool f = false;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].fi >= x && y - v[j].se <= 45) {
                    f = true;
                    v.erase(v.begin()+j);
                    break;
                }else if (y - v[j].se > 45) break;
            }
            if (!f) ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}