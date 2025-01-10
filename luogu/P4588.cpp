#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
int T;
int q,mod;
int t[400005];
inline void pushup(int p) {
	t[p] = (t[ls] % mod * t[rs] % mod) % mod;
}
inline void build(int p,int l,int r) {
	if (l == r) {
		t[p] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
inline void modify(int p,int pos,int v,int s,int e) {
	if (s == e && s == pos) {
		t[p] = v % mod;
		return;
	}else if (s == e){
		return;
	}
	int mid = (s + e) >> 1;
	if (pos <= mid) modify(ls,pos,v,s,mid);
	else modify(rs,pos,v,mid+1,e);
	pushup(p);
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> q >> mod;
		build(1,1,q);
		for (int i = 1; i <= q; i++) {
			int op;
			cin >> op;
			if (op == 1) {
				int m;
				cin >> m;
				modify(1,i,m,1,q);
				cout << t[1] % mod << '\n';
			}else{
				int pos;
				cin >> pos;
				modify(1,pos,1,1,q);
				cout << t[1] % mod << '\n';
			}
		} 
	}
	return 0;
}
