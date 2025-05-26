#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2003;
int d,n;
ll ans;
string s;
void dfs (int u,int len,ll sum) {
    if (len == d) {
        ll t = sum;string tmp;
        while (t) { 
            tmp += t%3+'0';
            t/=3;
        }
        while (tmp.size() < s.size()) tmp+='0';
        reverse(tmp.begin(),tmp.end());
        if (s.size() == tmp.size()) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i]!='?'&&s[i]!=tmp[i]) {
                    return;
                }
            }

            ++ans;
        }
        return;
    }
    dfs(3*u,len+1,sum+3*u);
    dfs(3*u+1,len+1,sum+3*u+1);
    dfs(3*u+2,len+1,sum+3*u+2);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> d >> s;
    dfs(0,0,0);
    cout << ans << '\n';
    return 0;
}