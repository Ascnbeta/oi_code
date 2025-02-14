<<<<<<< HEAD
#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
int n,m1,m2,ans;
struct plane{
	int a,b;
}p[3][100004];
int cnt[3][100004],sum[3][100004];
bool cmp(plane &x,plane &y) {
	return x.a < y.a;
}
struct bridge{
	int id,t;
	bool operator < (const bridge &y) const{
		if (t == y.t) return id > y.id;
		return t > y.t;
	}
};
priority_queue<bridge> q,qw;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	// freopen("airport3.in","r",stdin);
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= n; i++) q.push({i,0});
	for (int i = 1; i <= m1; i++) {
		cin >> p[1][i].a >> p[1][i].b;
	}
	sort(p[1]+1,p[1]+m1+1,cmp);
	for (int i = 1; i <= m1; i++) {
		while (!qw.empty() && qw.top().t < p[1][i].a) {
			q.push({qw.top().id,0});
			qw.pop();
		}
		if (q.empty()) continue;
		cnt[1][q.top().id]++;
		qw.push({q.top().id,p[1][i].b});
		q.pop();
	}
	while(!q.empty()) q.pop();
	while(!qw.empty()) qw.pop();
	for (int i = 1; i <= n; i++) q.push({i,0});
	for (int i = 1; i <= m2; i++) {
		cin >> p[2][i].a >> p[2][i].b;
		//cerr << i << '\n';
	}
	sort(p[2]+1,p[2]+m2+1,cmp);
	for (int i = 1; i <= m2; i++) {
		while (!qw.empty() && qw.top().t < p[2][i].a) {
			q.push({qw.top().id,0});
			qw.pop();
		}
		if (q.empty()) continue;
		cnt[2][q.top().id]++;
		qw.push({q.top().id,p[2][i].b});
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		sum[1][i] = sum[1][i-1] + cnt[1][i];
		sum[2][i] = sum[2][i-1] + cnt[2][i];
	}
	for (int i = 0; i <= n; i++) {
		ans = max(ans,sum[1][i]+sum[2][n-i]);
	}
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
int n,m1,m2,ans;
struct plane{
	int a,b;
}p[3][100004];
int cnt[3][100004],sum[3][100004];
bool cmp(plane &x,plane &y) {
	return x.a < y.a;
}
struct bridge{
	int id,t;
	bool operator < (const bridge &y) const{
		if (t == y.t) return id > y.id;
		return t > y.t;
	}
};
priority_queue<bridge> q,qw;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	// freopen("airport3.in","r",stdin);
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= n; i++) q.push({i,0});
	for (int i = 1; i <= m1; i++) {
		cin >> p[1][i].a >> p[1][i].b;
	}
	sort(p[1]+1,p[1]+m1+1,cmp);
	for (int i = 1; i <= m1; i++) {
		while (!qw.empty() && qw.top().t < p[1][i].a) {
			q.push({qw.top().id,0});
			qw.pop();
		}
		if (q.empty()) continue;
		cnt[1][q.top().id]++;
		qw.push({q.top().id,p[1][i].b});
		q.pop();
	}
	while(!q.empty()) q.pop();
	while(!qw.empty()) qw.pop();
	for (int i = 1; i <= n; i++) q.push({i,0});
	for (int i = 1; i <= m2; i++) {
		cin >> p[2][i].a >> p[2][i].b;
		//cerr << i << '\n';
	}
	sort(p[2]+1,p[2]+m2+1,cmp);
	for (int i = 1; i <= m2; i++) {
		while (!qw.empty() && qw.top().t < p[2][i].a) {
			q.push({qw.top().id,0});
			qw.pop();
		}
		if (q.empty()) continue;
		cnt[2][q.top().id]++;
		qw.push({q.top().id,p[2][i].b});
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		sum[1][i] = sum[1][i-1] + cnt[1][i];
		sum[2][i] = sum[2][i-1] + cnt[2][i];
	}
	for (int i = 0; i <= n; i++) {
		ans = max(ans,sum[1][i]+sum[2][n-i]);
	}
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}