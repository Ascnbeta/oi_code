#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m1,m2,ans = LONG_LONG_MAX;
int s[10004];
struct num{
    int n,c;
};

vector<num> nm;
bool is_prime(int x) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void msolve() {
    int tmp = m1;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0 && is_prime(i)) {
            int cnt = 0;
            while (tmp % i == 0) {
                tmp /= i;
                ++cnt;
            }
            nm.push_back(num{i,cnt * m2});
        }
    }
    if (tmp != 1) nm.push_back(num{tmp,m2});
}
signed main () {
    
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    msolve();
    // for (int i = 0; i < nm.size(); i++) {
    //     printf("%d^%d ",nm[i].n,nm[i].c);
    // }
    // puts("");
    for (int i = 1; i <= n; i++) {
        bool f1 = false;
        int cnt = 0;
        for (int j = 0; j < nm.size(); j++) {
            if (s[i] % nm[j].n != 0) {
                f1 = true;
                break;
            }
        }
        if (f1) continue;
        int tmp = s[i];
        for (int j = 0; j < nm.size(); j++) {
            int x = 0;
            while (tmp % nm[j].n == 0 ) {
                tmp /= nm[j].n;
                ++x;
            }
            //cout << x << endl;
            int scnt = nm[j].c / x;
            if (nm[j].c % x) ++scnt;
            cnt = max(cnt,scnt);
        }
        ans = min(ans,cnt);
    }
    if (ans == LONG_LONG_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}