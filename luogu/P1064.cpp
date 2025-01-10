#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int>v1[65],p1[65];
vector<int>v[65],p[65];
int f[32006],ans;
void dfs(int i,int j,int va,int pr) {
	if (j == v1[i].size()) {
		v[i].push_back(va+v1[i][0]*p1[i][0]);
		p[i].push_back(pr+p1[i][0]);
		return;
	}
	dfs(i,j+1,va,pr);
	dfs(i,j+1,va+v1[i][j]*p1[i][j],pr+p1[i][j]);
}
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x,y,z;
		cin >> x >> y >> z;
		if (z == 0) {
			v1[i].insert(v1[i].begin(),y);
			p1[i].insert(p1[i].begin(),x);
		}else{
			v1[z].push_back(y);
			p1[z].push_back(x);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (v1[i].size() == 0) continue;
		dfs(i,1,0,0);
	}
	for (int i = 1; i <= m; i++) {
		if (v[i].size() == 0) continue;
		for (int j = n; j >= 0; j--) {
			for (int k = 0; k < v[i].size(); k++) {
				if (j >= p[i][k]) f[j] = max(f[j],f[j-p[i][k]]+v[i][k]);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		ans = max(ans,f[i]);
	}
	cout << ans << '\n';
	return 0;
}