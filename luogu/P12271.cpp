#include <bits/stdc++.h>

using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 2e6+10;
string s;
int q;
int ans[30][maxn],sum[30][maxn];
int st[maxn],top;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s >> q;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == ')') {
            int l = st[top--];
            for (int j = 0; j < 26; j++) {
                sum[j][i] = sum[j][i-1];
                int tmp = sum[j][i] - sum[j][l-1];
                ans[j][0]++,ans[j][tmp+1]--;
            }
        }else if (s[i] == '(') {
            st[++top] = i;
            for (int j = 0; j < 26; j++) sum[j][i] = sum[j][i-1];
        }else{
            for (int j = 0; j < 26; j++) {
                if (j==s[i]-'a')sum[j][i] = sum[j][i-1]+1;
                else sum[j][i] = sum[j][i-1];
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] += ans[i][j-1];
        }
    }
    while (q--) {
        char ch;int x;
        cin >> ch >> x;
        cout << ans[ch-'a'][x] << '\n';
    }
    return 0;
}