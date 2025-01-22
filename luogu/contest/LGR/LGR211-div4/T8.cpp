#include <bits/stdc++.h>
using namespace std;
int n,m,T,k,ans;
bool f[10004];
struct team{
	string name,t1,t2,t3;
	int id,r;
}t[10004];
map<string,int> mp;
bool cmp(team x,team y){
	if (x.r == y.r) return x.id < y.id;
	return x.r < y.r;
}
vector<int> ansp;
int main () {
	cin >> n >> m >> T >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].name >> t[i].t1 >> t[i].t2 >> t[i].t3 >> t[i].id >> t[i].r;
	}
	sort(t+1,t+n+1,cmp);
	while (k--) {
		bool suc = false;
		for (int i = 1; i <= n; i++) {
			if (f[i]) continue;
			if (mp.find(t[i].t1) != mp.end() || mp.find(t[i].t2) != mp.end() || mp.find(t[i].t3) != mp.end()) {f[i] = true;continue;}
			f[i] = true,suc = true;
			++ans;
			mp[t[i].t1] = 1,mp[t[i].t2] = 1,mp[t[i].t3] = 1;
			ansp.push_back(i);
			break;
		}
		if (!suc) break;
	}
	cout << ans << '\n';
	for (int i = 0; i < ansp.size(); i++) {
		int p = ansp[i];
		cout << t[p].name << ' ' << t[p].t1 << ' ' << t[p].t2 << ' ' << t[p].t3 << '\n';
	}
	return 0;
}