#include <bits/stdc++.h>
using namespace std;
int n,q;
map<int,int> pre,nxt;
int a[200005],h;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			h = a[i];
		}
		pre.insert(make_pair(a[i],a[i-1]));
		nxt.insert(make_pair(a[i-1],a[i]));
	}
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x,y;
			cin >> x >> y;
			int tp1,tp2;
			tp1 = nxt[x];
			pre.erase(tp1);
			pre.insert(make_pair(tp1,y));
			pre.insert(make_pair(y,x));
			nxt.insert(make_pair(y,tp1));
			nxt.erase(x);
			nxt.insert(make_pair(x,y));
		}
		if (op == 2) {
			int x;
			cin >> x;
			int tp1 = pre[x],tp2 = nxt[x];
			if (x == h) {
				pre.erase(tp2);
				pre.insert(make_pair(tp2,tp1));
				pre.erase(x);
				nxt.erase(x);
				h = tp2;
			}else{
				pre.erase(tp2);
				pre.insert(make_pair(tp2,tp1));
				pre.erase(x);
				nxt.erase(tp1);
				nxt.insert(make_pair(tp1,tp2));
				nxt.erase(x);
			}
		}
	}
	while (nxt.find(h) != nxt.end() && nxt[h] != 0) {
		cout << h << ' ';
		h = nxt[h];
	}
	if (h == 0) return 0;
	cout << h;
	return 0;
}
