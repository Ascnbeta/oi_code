#include <bits/stdc++.h>
using namespace std;
int T;
int n;
string s;
int b[26];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> s;
        s = ' ' + s;
        memset(b,0,sizeof(b));
        for (int i = 1; i <= n; i++) {
            b[s[i]-'a']++;
        }
        bool f = false;
        for (int i = 2; i < n; i++) {
            if (b[s[i]-'a']>1) {
                f = true;
                break;
            }
        }
        if (f) puts("Yes");
        else puts("No");
    }
    return 0;
}