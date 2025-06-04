#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(ll &x) {
	x=0;int f=1;char ch = getchar();
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
char buf[30];
int top;
inline void write(int v) {
	top=0;
	while (v) {
		buf[++top]=v%10+'0';
		v/=10;
	}
	while (top) putchar(buf[top--]);
}
const ll maxn = 2e5+30;
ll n;
bool f[maxn];
ll a[maxn];
ll lft,minn=0x3f3f3f3f,ans;
priority_queue<int,vector<int>,greater<int>> q;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char tp;
		cin >> tp >> a[i];
		if (tp == 'e') f[i] = true;
	}
	lft = a[n];
	if (n == 1) {
		if (lft == 0) puts("0");
		else puts("-1");
		return 0;
	}
	for (int i = 1; i <= n-1; i++) {
        if (!f[i]) {
            q.push(a[i]);
            ans += a[i];
        }else{
            while (q.size() >= a[i]) {
                ans -= q.top();
                q.pop();
            }
        }
    }
	printf("%lld",ans);
	return 0;
}
