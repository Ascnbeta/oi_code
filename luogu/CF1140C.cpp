#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,tot,ans,tt;
struct song{
	int t,b;
}s[300005];
struct song2{
	bool operator() (song x,song y) {
		return x.t > y.t;
	}
};
priority_queue<song, vector<song>,song2> q;

bool cmp (song x,song y) {
	if (x.b == y.b) return x.t > y.t;
	return x.b > y.b;
}
signed main () {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].t >> s[i].b;
		
	}
	sort(s+1,s+n+1,cmp);
	for (int i = 1; i <= n; i++) {
		tot += s[i].t;
		q.push(s[i]);
		while (q.size() > k) {
			tot -= q.top().t;
			q.pop();
		}
		ans = max(ans,s[i].b * tot);
	}
	cout << ans << endl;
	return 0; 
}
