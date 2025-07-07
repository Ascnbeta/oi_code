#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n;string s;
int d[maxn<<1],ans;
inline void manacher() {
    int id = 1,r = 1;
    for (int i = 1; i <= n; i++) {
        if (i < r) d[i] = min(r-i,d[id*2-i]);
        while (s[i+d[i]]==s[i-d[i]]) d[i]++;
        if (i+d[i] > r) {
            if (s[i] == '|') {
                for (int j = r; j <= i+d[i]-1; j++) {
                    if (s[j] == '|') continue;
                    int len = (j-i+1)/2,pre = i-len;
                    if (s[pre] == '|' &&//首先，本题中回文串均为偶长回文
                        d[pre]/2 >= len/2 &&//其次，原来那个位置得能扩展到目前回文串的中间
                        len >= 1 &&//你得有长度吧
                        len*2%4 == 0//双倍回文串长为4倍数
                    ) {
                        ans = max(ans,len*2);
                    }
                }
            }
            r = i + d[i],id = i;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    s += '|';
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        s += ch;
        s += '|';
    }
    n = s.size();
    manacher();
    cout << ans << '\n';
    return 0;
}