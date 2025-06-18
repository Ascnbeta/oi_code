#include <bits/stdc++.h>
#define double long double
using namespace std;
const int maxn = 1e3+20;
const double eps = 1e-10;
int n;
int mid = 0,mid1 = 0;
struct node{
	double x,y;
	int id;
}d[maxn<<1];
double f[maxn<<1][maxn<<1][2];
int lst[maxn<<1][maxn<<1][2];
inline double dis(int i,int j) {
	return sqrt(fabs(d[i].x-d[j].x)*fabs(d[i].x-d[j].x)+fabs(d[i].y-d[j].y)*fabs(d[i].y-d[j].y));
}
inline double dis(node i,node j) {
	return sqrt(fabs(i.x-j.x)*fabs(i.x-j.x)+fabs(i.y-j.y)*fabs(i.y-j.y));
}
bool cmp1(node x,node y) {
	return x.id < y.id;
}
bool cmp2(node x,node y) {
	if (x.y == y.y) return x.id > y.id;
	return x.y < y.y;
}
stack<int> ans;
void print(int l,int r,int op) {
	if (l == r) {
		ans.push(d[l].id);
		return;
	}
	if (op == 1) {
		ans.push(d[r].id);
		print(l,r-1,lst[l][r][op]);
	}else{
		ans.push(d[l].id);
		print(l+1,r,lst[l][r][op]);
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\tree14.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].x >> d[i].y;
		d[i].id = i;
		d[i+n] = d[i];
		d[i+n].id = i+n;
	}
//	d[0].y = -1e9;
//	
	sort(d+1,d+2*n+1,cmp2);
	mid = d[2*n].id,mid1 = (mid+n)%(2*n);
	sort(d+1,d+2*n+1,cmp1);
	// for (int i = 1; i <= n; i++) cout << d[i].x << '\n';
	for (int i = 1; i <= 2*n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			f[i][j][0] = f[i][j][1] = 1e18;
		}
	}
	f[mid][mid][0] = f[mid][mid][1] = 0;
	f[mid1][mid1][0] = f[mid1][mid1][1] = 0;
	// cout << mid << '\n';
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= 2*n; i++) {
			int j = i + len - 1;
			if (f[i][j][0] - f[i+1][j][0] - dis(i+1,i) > eps) f[i][j][0] = f[i+1][j][0] + dis(i+1,i),lst[i][j][0] = 0;
			if (f[i][j][0] - f[i+1][j][1] - dis(j,i) > eps) f[i][j][0] = f[i+1][j][1] + dis(j,i),lst[i][j][0] = 1;
			if (f[i][j][1] - f[i][j-1][1] - dis(j,j-1) > eps) f[i][j][1] = f[i][j-1][1] + dis(j,j-1),lst[i][j][1] = 1;
			if (f[i][j][1] - f[i][j-1][0] - dis(i,j) > eps) f[i][j][1] = f[i][j-1][0] + dis(i,j),lst[i][j][1] = 0;
			// cout << i << ' ' << j << ' ' << 0 << ' ' << f[i][j][0] << '\n';
			// cout << i << ' ' << j << ' ' << 1 << ' ' << f[i][j][1] << '\n';
		}
	}
//	if (f[1][n][0] <= f[1][n][1]) {
//		ans.push(d[1].id);
//		print(2,n,lst[1][n][0]);
//	}else{
//		ans.push(d[n].id);
//		print(1,n-1,lst[1][n][1]);
//	}
	double ansv = 1e18;int l,r,p;
	for (int i = 1; i <= n; i++) {
		int j = i + n - 1;
		if (f[i][j][1] < ansv) {
			ansv = f[i][j][1];
			l = i,r = j,p = 1;
		}else if (f[i][j][0] < ansv) {
			ansv = f[i][j][0];
			l = i,r = j,p = 0;
		}
	}
	if (p == 1) {
		ans.push(d[r].id);
		print(l,r-1,lst[l][r][1]);
	}else{
		ans.push(d[l].id);
		print(l+1,r,lst[l][r][0]);
	}
	while (ans.size()) {
		int tmp = ans.top();
		if (tmp > n) tmp -= n;
		cout << tmp << ' ';
		ans.pop();
	}
	cout << '\n';
	return 0;
}