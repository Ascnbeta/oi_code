#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int ed[100005],t[100005];
inline int lowbit(int x) {
	return x&-x;
}
inline void modify(int p,int x) {
	while (p <= 200000) {
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
int main () {
	cin >> n;
	while (n--) {
		char op;
		cin >> op;
		if (op == 'A') {
			int s,e,ans = 0;
			cin >> s >> e;
			while(1) {
				int l = 0,r = e;
				while (l < r) {
					int mid = (l + r) >> 1;
					if (query(mid) < query(e)) l = mid + 1;
					else r = mid;
				}
				if (ed[l] >= s) {
					--cnt;
					modify(l,-1);
					++ans;
				}else{
					break;
				}
			}
			cout << ans << '\n';
			modify(s,1);
			ed[s] = e;
			++cnt;
		}else{
			cout << cnt << '\n';
		}
	}
	return 0;
}