#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,k;
int a[maxn],b[maxn],c[maxn];
struct Pair{
	int i,j,k,sum;
	bool operator < (const Pair &y) const{
		return sum < y.sum;
	}
};
inline int ret(int i,int j,int k) {
	return a[i]*b[j]+b[j]*c[k]+c[k]*a[i];
}
priority_queue<Pair> q;
set<pair<int,pair<int,int>>> s;
signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1,greater<int>());
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(b+1,b+n+1,greater<int>());
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c+1,c+n+1,greater<int>());
	q.push({1,1,1,ret(1,1,1)});
	for (int i = 1; i <= k; i++) {
		Pair t = q.top();
		if (i == k) {
			cout << t.sum << '\n';
		}
		// cout << ret(t) << '\n';
		q.pop();
		if (t.i < n && s.find({t.i+1,{t.j,t.k}}) == s.end()) q.push({t.i+1,t.j,t.k,ret(t.i+1,t.j,t.k)}),s.insert({t.i+1,{t.j,t.k}});
		if (t.j < n && s.find({t.i,{t.j+1,t.k}}) == s.end()) q.push({t.i,t.j+1,t.k,ret(t.i,t.j+1,t.k)}),s.insert({t.i,{t.j+1,t.k}});
		if (t.k < n && s.find({t.i,{t.j,t.k+1}}) == s.end()) q.push({t.i,t.j,t.k+1,ret(t.i,t.j,t.k+1)}),s.insert({t.i,{t.j,t.k+1}});
	}
	return 0;
}