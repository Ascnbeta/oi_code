#include <bits/stdc++.h>
using namespace std;
int n,m;
struct stt{
	int l,w;
	int t;
}c[400005];
multiset<int> t;
bool cmp(stt x,stt y) {
	if (x.l == y.l && x.w == y.w) return x.t > y.t;
	if (x.l == y.l) return x.w > y.w;
	return x.l > y.l;
}

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].l;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i].w;
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[n+i].l;
		c[n+i].t = 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[n+i].w;
	}
	sort(c+1,c+n+m+1,cmp);
	for (int i = 1; i <= n+m; i++) {
		if (c[i].t == 1) {
			t.insert(c[i].w);
		}else{
			auto it = t.lower_bound(c[i].w);
			if (it == t.end()) {
				cout << "No" << endl;
				return 0;
			}
			t.erase(it);
		}
	}
	cout << "Yes" << endl;
	return 0;
}
