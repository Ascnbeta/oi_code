#include <bits/stdc++.h>
#define int long long
using namespace std;

int T;
int n,m,v;
int num[114514];
int ans;
int jh;

int qp(int x,int a) {
	if (a == 1) return x;
	if (a == 0) return 1;
	if (a & 1) {
		int b = qp(x,a >> 1);
		int qwq = b * b % 1000000007;
		qwq *= x;
		return qwq % 1000000007;
	}
	else {
		int b = qp(x,a >> 1);
		int qwq = b * b;
		return qwq % 1000000007;
	}
}

signed main ( ) {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin >> T ;
	while (T--) {
		cin >> n >> m >> v ;
		for (int i = 1;i <= m;++i) {
			int c,d;cin >> c >> d ;
			if (num[c] == 0) num[c] = d;
			else if (num[c] != d) jh = 1;
		}
		if (jh) {
			cout << "0\n" ;
			continue;
		}
		ans = qp(v,n);
		if (m == 1) {
			cout << ans % 1000000007 << '\n' ;
			continue;
		}
		for (int i = 1;i < n;++i) {
			ans -= qp(v,i - 1);
		}
		cout << ans % 1000000007 << '\n' ;
	}
}
/*
1 2 3 4 5 6
1 2 3
*/
