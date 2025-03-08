#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
void modify(int l,int r,int t) {
	for (int i = l; i <= r; i++) {
		if (t == 1) {
			a[i] = 1;
		}else if (t == 0) {
			a[i] = 0;
		}else {
			a[i] = ((a[i]==1)?0:1);
		}
	}
}
int query1(int l,int r) {
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] == 1) ++cnt;
	}
	return cnt;
}
int query2(int l,int r) {
	int cnt = 0,ret = 0;
	for (int i = l; i <= r; i++) {
		if (a[i] == 1) ++cnt;
		else {
			ret = max(ret,cnt);
			cnt = 0;
		}
	}
	ret = max(ret,cnt);
	return ret;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (m--) {
		int op,l,r;
		cin >> op >> l >> r;
		++l,++r;
		switch(op) {
			case 0:{
				modify(l,r,0);
				break;
			}
			case 1:{
				modify(l,r,1);
				break;
			}
			case 2:{
				modify(l,r,2);
				break;
			}
			case 3:{
				cout << query1(l,r) << '\n';
				break;
			}
			case 4:{
				cout << query2(l,r) << '\n';
				break;
			}
		}
	}
	return 0;
}