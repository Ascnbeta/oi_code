#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.5e5;
int n,m;
int a[maxn],b[maxn],c[maxn];
struct matrix{
	int m[6][6],l,r;
	matrix(int x,int y) {
		for (int i = 0; i <= x; i++) {
			for (int j = 0; j <= y; j++) m[i][j] = 0;
		}
		l = x,r = y;
	}
	void reset() {
		for (int i = 1; i <= l; i++) {
			m[i][i] = 1;
		}
	}
	matrix operator * (const matrix &y) const{
		matrix c(l,r);c.reset();
		assert(r==y.l);
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= r; k++) {
					c.m[i][j] += (long long)m[i][k]*y.m[k][j]
				}
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i]; 
	return 0;
}