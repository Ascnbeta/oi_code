<<<<<<< HEAD
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,m,ans;
int a[maxn],b[maxn],c[maxn],cnt[maxn],num;
struct node{
	int id,cst;
	bool operator < (const node &y) const{
		return cst > y.cst;
	}
	bool operator > (const node &y) const{
		return cst < y.cst;
	}
};
priority_queue<node> q;
priority_queue<node,vector<node>,greater<node>> q1;
priority_queue<node> q2;
int f[maxn];
signed main () {
	cin >> n >> m;
	num = n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		++cnt[i];
		ans += a[i]+b[i]+c[i];
		q.push({i,a[i]*4+b[i]*2+c[i]});
	}
	for (int i = n+1; i <= 2*m; i++) {
		ans += q.top().cst;
		cnt[q.top().id]++;
		if (cnt[q.top().id] + 1 > m) {
			q.pop();
			continue;
		}
		else {
			node t = q.top();
			q.pop();
			q.push({t.id,a[t.id]*(cnt[t.id]+1)*(cnt[t.id]+1)+b[t.id]*(cnt[t.id]+1)+c[t.id]});
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		q1.push({i,cnt[i]});
		q2.push({i,cnt[i]});
		f[i] = cnt[i];
	}
	for (int i = 1; i <= m; i++) {
		node t1 = q1.top(),t2 = q2.top();
		// cout << "debug:" << t1.id << ' ' << t2.id << '\n';
		// cout << "warning: ";
		// for (int i = 1; i <= n; i++) {
		// 	cout << f[i] << ' ';
		// }
		// cout << '\n';
		while(t1.cst != f[t1.id]) {
			q1.pop();
			if (f[t1.id] == 0) {
				t1 = q1.top();
				continue;
			}
			q1.push({t1.id,f[t1.id]});
			// cout << i << ' ' << "qwq" << '\n';
			t1 = q1.top();
		}
		while(t2.cst != f[t2.id]) {
			q2.pop();
			if (f[t2.id] == 0) {
				t2 = q2.top();
				continue;
			}
			q2.push({t2.id,f[t2.id]});
			// cout << i << ' ' << "awa" << '\n';
			t2 = q2.top();
		}
		if (t1.id == t2.id) {
			q1.pop(),q2.pop();
			node t3 = q2.top();
			while(t3.cst != f[t3.id]) {
				q2.pop();
				if (f[t3.id] == 0) {
					t3 = q2.top();
					continue;
				}
				q2.push({t3.id,f[t3.id]});
				// cout << i << ' ' << "awa" << '\n';
				t3 = q2.top();
			}
			cout << t1.id << ' ' << t3.id << '\n';
			
			q2.pop();
			f[t1.id] -= 1;
			if (f[t1.id] != 0) {
				q1.push({t1.id,f[t1.id]});
				q2.push({t2.id,f[t2.id]});
			}
			f[t3.id] -= 1;
			if (f[t3.id] != 0) {
				q2.push({t3.id,f[t3.id]});
			}
		}else{
			q1.pop(),q2.pop();
			cout << t1.id << ' ' << t2.id << '\n';
			f[t1.id] -= 1;
			if (f[t1.id] != 0) q1.push({t1.id,f[t1.id]});
			f[t2.id] -= 1;
			if (f[t2.id] != 0) q2.push({t2.id,f[t2.id]});
		}
	}
	return 0;
=======
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,m,ans;
int a[maxn],b[maxn],c[maxn],cnt[maxn],num;
struct node{
	int id,cst;
	bool operator < (const node &y) const{
		return cst > y.cst;
	}
	bool operator > (const node &y) const{
		return cst < y.cst;
	}
};
priority_queue<node> q;
priority_queue<node,vector<node>,greater<node>> q1;
priority_queue<node> q2;
int f[maxn];
signed main () {
	cin >> n >> m;
	num = n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		++cnt[i];
		ans += a[i]+b[i]+c[i];
		q.push({i,a[i]*4+b[i]*2+c[i]});
	}
	for (int i = n+1; i <= 2*m; i++) {
		ans += q.top().cst;
		cnt[q.top().id]++;
		if (cnt[q.top().id] + 1 > m) {
			q.pop();
			continue;
		}
		else {
			node t = q.top();
			q.pop();
			q.push({t.id,a[t.id]*(cnt[t.id]+1)*(cnt[t.id]+1)+b[t.id]*(cnt[t.id]+1)+c[t.id]});
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		q1.push({i,cnt[i]});
		q2.push({i,cnt[i]});
		f[i] = cnt[i];
	}
	for (int i = 1; i <= m; i++) {
		node t1 = q1.top(),t2 = q2.top();
		// cout << "debug:" << t1.id << ' ' << t2.id << '\n';
		// cout << "warning: ";
		// for (int i = 1; i <= n; i++) {
		// 	cout << f[i] << ' ';
		// }
		// cout << '\n';
		while(t1.cst != f[t1.id]) {
			q1.pop();
			if (f[t1.id] == 0) {
				t1 = q1.top();
				continue;
			}
			q1.push({t1.id,f[t1.id]});
			// cout << i << ' ' << "qwq" << '\n';
			t1 = q1.top();
		}
		while(t2.cst != f[t2.id]) {
			q2.pop();
			if (f[t2.id] == 0) {
				t2 = q2.top();
				continue;
			}
			q2.push({t2.id,f[t2.id]});
			// cout << i << ' ' << "awa" << '\n';
			t2 = q2.top();
		}
		if (t1.id == t2.id) {
			q1.pop(),q2.pop();
			node t3 = q2.top();
			while(t3.cst != f[t3.id]) {
				q2.pop();
				if (f[t3.id] == 0) {
					t3 = q2.top();
					continue;
				}
				q2.push({t3.id,f[t3.id]});
				// cout << i << ' ' << "awa" << '\n';
				t3 = q2.top();
			}
			cout << t1.id << ' ' << t3.id << '\n';
			
			q2.pop();
			f[t1.id] -= 1;
			if (f[t1.id] != 0) {
				q1.push({t1.id,f[t1.id]});
				q2.push({t2.id,f[t2.id]});
			}
			f[t3.id] -= 1;
			if (f[t3.id] != 0) {
				q2.push({t3.id,f[t3.id]});
			}
		}else{
			q1.pop(),q2.pop();
			cout << t1.id << ' ' << t2.id << '\n';
			f[t1.id] -= 1;
			if (f[t1.id] != 0) q1.push({t1.id,f[t1.id]});
			f[t2.id] -= 1;
			if (f[t2.id] != 0) q2.push({t2.id,f[t2.id]});
		}
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}