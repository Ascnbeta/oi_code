#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.2e7+30;
int n,ans;
string s,t;
int d1[maxn];
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> t;
    n = t.size();
    t = ' ' + t;
    s = ' ';
    for (int i = 1; i <= n; i++) {
        s += '#';
        s += t[i];
    }
    s += '#';
    n = s.size() - 1;
    int l = 1,r = 0;
    for (int i = 1; i <= n; i++) {
        d1[i] = 1;
        if (i > r) {
            int x = i-1,y = i+1;
            while (x>=1&&y<=n&&s[x]==s[y]) {
                ++d1[i];
                --x,++y;
            }
            if ( r < i+d1[i]-1) l = i-d1[i]+1,r = i+d1[i]-1;
            else if (r == i+d1[i]-1) l = min(l,i-d1[i]+1);
        }else{
            int j = r-i+l;
            
            if (j-d1[j]+1<=l) {
                d1[i] = r-i;
                int x = i-d1[i],y = r;
                while (x>=1&&y<=n&&s[x]==s[y]) {
                    ++d1[i];
                    --x,++y;
                }
            }else d1[i] = d1[j];
            if (r < i+d1[i]-1) l = i-d1[i]+1,r = i+d1[i]-1;
            else if (r == i+d1[i]-1) l = min(l,i-d1[i]+1);
        }
    }
    // for (int i = 1; i <= n; i++) cout << s[i];
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << d1[i];
    // cout << '\n';
    for (int i = 1; i <= n; i++) {
        ans = max(ans,(d1[i]*2-2)/2);
    }
    cout << ans << '\n';
    return 0;
}