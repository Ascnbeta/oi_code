#include <bits/stdc++.h>
using namespace std;
int n,m;
int y[100004],r[100004];
int tot;
int f[100005],st[100005][50],sum[100005];
void init() {
	f[1] = 0;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i/2] + 1;
	}
	for (int i = 1; (1<<i) <= n; i++) {
		for (int j = 1; (j+(1<<i)-1) <= n; j++) {
			st[j][i] = max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
int query(int l,int r) {
	if (l > r) return -1;
	int j = f[r-l+1];
	return max(st[l][j],st[r-(1<<j)+1][j]);
}
map<int,int> mp;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> y[i] >> r[i];
		mp[y[i]] = i;
		st[i][0] = r[i];

	}
	init();
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int l,R,pr,pl;
		cin >> l >> R;
		auto t1 = mp.find(l),t2 = mp.find(R);
		if (t1 != mp.end() && t2 != mp.end()) {
			pl = mp[l];
			pr = mp[R];
			if (query(pl+1,pr-1) >= r[pr] || r[pr] > r[pl]) {
				cout << "false" << '\n';
			}else if(pr - pl != R - l) {
				cout << "maybe" << '\n';
			}else{
				cout << "true" << '\n';
			}
		}else if (t2 == mp.end()) {
			if (t1 == mp.end()) {
				cout << "maybe" << '\n';
			}else{
				pl = mp[l];
				pr = upper_bound(y+1,y+n+1,R)-y-1;
				if (query(pl+1,pr) >= r[pl] && pl != pr) {
					cout << "false" << '\n';
				}else{
					cout << "maybe" << '\n';
				}
			}
			
		}else{
			pr = mp[R];
			pl = upper_bound(y+1,y+n+1,l)-y;
			if (query(pl,pr-1) >= r[pr] && pr != pl) {
				cout << "false" << '\n';
			}else{
				cout << "maybe" << '\n';
			}
		}
	}
	return 0;
}