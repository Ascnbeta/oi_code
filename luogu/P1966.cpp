#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e8-3;
int n,a[100004],b[100004],c[100004],d[100004],ans;
map<int,int> m;
int t[100004];
inline int lowbit(int x) {
	return x&(-x);
}
inline void modify(int p,int x) {
	while (p <= n) {
		t[p] += x;
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while (p > 0) {
		ret += t[p];
		p -= lowbit(p);
	}
	return ret;
}
signed main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		d[i] = b[i];
	}
	sort(c+1,c+n+1);
	for (int i = 1; i <= n; i++) {
		m.insert(make_pair(c[i],i));
	}
	for (int i = 1; i <= n; i++) {
		a[i] = (*(m.find(a[i]))).second;
	}
	//~ for (int i = 1; i <= n; i++) {
		//~ cout << a[i] << ' ';
	//~ }
	m.clear();
	sort(d+1,d+n+1);
	for (int i = 1; i <= n; i++) {
		m.insert(make_pair(d[i],i));
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (*(m.find(b[i]))).second;
	}
	m.clear();
	for (int i = 1; i <= n; i++) {
		m.insert(make_pair(a[i],i));
	}

	//~ for (int i = 1; i <= n; i++) {
		//~ cout << b[i] << ' ';
	//~ }
	for (int i = n; i >= 1; i--) {
	 	b[i] = (*(m.find(b[i]))).second;
	 	ans = (ans % mod + query(b[i]-1) % mod) % mod;
		modify(b[i],1);
	}
	cout << ans % mod << '\n';
	return 0;
}
