#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+30;
int n,m;
int t1[maxn],t2[maxn];
inline int lowbit(int x) {return x&(-x);}
inline void modify1(int p,int x) {
	while (p <= n) {
		t1[p] += 1;
		p += lowbit(p);
	}
}
inline void modify2(int p,int x) {
	while (p <= n) {
		t2[p] += 1;
		p += lowbit(p);
	}
}
inline int query1(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t1[p];
		p -= lowbit(p);
	}
	return ret;
}
inline int query2(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t2[p];
		p -= lowbit(p);
	}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("D:/codes/exe/a.in","r",stdin);
	freopen("D:/codes/exe/a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int q,l,r;
		cin >> q >> l >> r;
		if (q == 1) {
			modify1(l,1);
			modify2(r,1);
		}else{
			cout << query1(r) - query2(l-1) << '\n';
		}
		
	}
	return 0;
}	