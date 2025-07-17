#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,r,b;
char ch[maxn];
int st[maxn],sum[maxn],top;
int cntr,cntb;
int tot;vector<int> ans[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> r >> b;
    for (int i = 1; i <= n; i++) cin >> ch[i],cntr+=(ch[i]=='R'),cntb+=(ch[i]=='B');
	if ((r==0&&cntr!=0)||(b==0&&cntb!=0)||(r!=0&&cntr%r!=0)||(b!=0&&cntb%b!=0)||(r!=0&&b!=0&&cntr/r!=cntb/b)) {
		puts("NO");
		return 0;
	}
    for (int i = 1; i <= n; i++) {
        if (top < r+b-1) {
            st[++top] = i;
            sum[top] = sum[top-1] + (ch[i]=='R');
        }else{
            st[++top] = i;
            sum[top] = sum[top-1] + (ch[i]=='R');
            if (sum[top]-sum[top-r-b] == r) {
                ++tot;
                for (int i = top-r-b+1; i <= top; i++) ans[tot].push_back(st[i]);
                top = top-r-b;
            }
        }
    }
    puts("YES");
    cout << tot << '\n';
    for (int i = tot; i >= 1; i--) {
        for (int j : ans[i]) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}