#include <bits/stdc++.h>
using namespace std;
int n,maxx;
struct task{
    int s,t;
}t[1004];
bool cmp(task x,task y) {
    return x.s < y.s;
}
bool check(int x) {
    int tmp = x;
    for (int i = 1; i <= n; i++) {
        if (tmp + t[i].t <= t[i].s) {
            tmp += t[i].t;
        }else{
            return false;
        }
    }
    return true;
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].t >> t[i].s;
        maxx = max(maxx,t[i].s - t[i].t);
    }
    sort(t+1,t+n+1,cmp);
    int l = 0,r = maxx;
    while (l <= r ) {
        int mid = l + ((r - l) / 2);
        if (check(mid)) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    if (r == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << l - 1 << '\n';
    return 0;
}