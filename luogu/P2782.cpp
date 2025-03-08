#include <bits/stdc++.h>
using namespace std;
int n;
struct city {
	int l,r;
}c[200005];
bool cmp(city x,city y) {
	return x.l < y.l;
}
int 
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i].l >> c[i].r;
	sort(c+1,c+n+1,cmp);
	
	return 0;
}