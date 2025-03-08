#include <bits/stdc++.h>
#define double long double
using namespace std;
const int maxn = 1e3+20;
const double eps = 1e-10;
int n;
int mid = 1;
struct node{
	double x,y;
	int id;
}d[maxn];
double f[maxn][maxn][2];
int lst[maxn][maxn][2];
inline double dis(int i,int j) {
	return sqrt((d[i].x-d[j].x)*(d[i].x-d[j].x)+(d[i].y-d[j].y)*(d[i].y-d[j].y));
}
inline double dis(node i,node j) {
	return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}
bool cmp1(node x,node y) {
	return x.x < y.x;
}
bool cmp2(node x,node y) {
	return dis(x,d[mid]) - dis(y,d[mid]) > eps;
}
bool cmp3(node x,node y) {
	return dis(x,d[mid]) - dis(y,d[mid]) < eps;
}
stack<int> ans;
void print(int l,int r,int op) {
	if (l == r) {
		// if (l != mid) assert(0);
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
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].x >> d[i].y;
		d[i].id = i;
	}
	d[0].y = -1e9;
	
	sort(d+1,d+n+1,cmp1);
	for (int i = 1; i <= n; i++) {
		if (d[i].y > d[mid].y) {
			mid = i;
		}else if(d[i].y == d[mid].y){
			if (d[i].id < d[mid].id) mid = i;
		}
	}
	sort(d+1,d+mid,cmp2);
	sort(d+mid+1,d+n+1,cmp3);
	// for (int i = 1; i <= n; i++) cout << d[i].x << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f[i][j][0] = f[i][j][1] = 1e18;
		}
	}
	f[mid][mid][0] = f[mid][mid][1] = 0;
	// cout << mid << '\n';
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			// if (i <= mid && mid <= j) continue;
			
			if (f[i][j][0] - f[i+1][j][0] - dis(i+1,i) > eps) f[i][j][0] = f[i+1][j][0] + dis(i+1,i),lst[i][j][0] = 0;
			if (f[i][j][0] - f[i+1][j][1] - dis(i,j) > eps) f[i][j][0] = f[i+1][j][1] + dis(i,j),lst[i][j][0] = 1;
			if (f[i][j][1] - f[i][j-1][1] - dis(j,j-1) > eps) f[i][j][1] = f[i][j-1][1] + dis(j,j-1),lst[i][j][1] = 1;
			if (f[i][j][1] - f[i][j-1][0] - dis(i,j) > eps) f[i][j][1] = f[i][j-1][0] + dis(i,j),lst[i][j][1] = 0;
			// cout << i << ' ' << j << ' ' << 0 << ' ' << f[i][j][0] << '\n';
			// cout << i << ' ' << j << ' ' << 1 << ' ' << f[i][j][1] << '\n';
		}
	}
	if (f[1][n][0] <= f[1][n][1]) {
		ans.push(d[1].id);
		print(2,n,lst[1][n][0]);
	}else{
		ans.push(d[n].id);
		print(1,n-1,lst[1][n][1]);
	}
	while (ans.size()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
	return 0;
}