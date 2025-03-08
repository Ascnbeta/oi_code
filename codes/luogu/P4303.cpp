#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],ans;
vector<int> pos[20005];
int t[100005],f[100005];
inline int lowbit(int x) {
	return x&-x;
}
inline void modify(int p,int x) {
	while (p <= n) {
		t[p] = max(t[p],x);
		p += lowbit(p);
	}
}
inline int query(int p) {
	int ret = 0;
	while (p > 0) {
		ret = max(t[p],ret);
		p -= lowbit(p);
	}
	return ret;
}
int main () {
	cin >> n;
	n *= 5;
	for (int i = 1; i <= n; i++) cin >> a[i],pos[a[i]].push_back(i);
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 4; j >= 0; j--) {
			int p = pos[b[i]][j];
			f[p] = query(p-1)+1;
			modify(p,f[p]);
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans,f[i]);
	}
	cout << ans << '\n';
	return 0;
}
