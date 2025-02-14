<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,m,u[maxn],v[maxn];
vector<int> e[maxn];
inline bool check(int x,int y) {
	int a = u[x],b = v[x],c = u[y], d = v[y];
	if (a != c && a != d && b != c && b != d) return true;
	return false;
}
int father[maxn],rk[maxn],cnt;
inline int find(int x) {
    int t = x;
    while(x != father[x]) x = father[x];
    int w;
    while(t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    --cnt;
    if (rk[p] <= rk[q]) {
        father[p] = q;
        rk[q] = max(rk[q],rk[p]+1);
    }else{
        father[q] = p;
        rk[p] = max(rk[p],rk[q]+1);
    }
}
int p = 0,q = 0,r = 0;
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) father[i] = i;
	cnt = n;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(i);
		e[v[i]].push_back(i);
		merge(u[i],v[i]);
	}
	for (int i = 1; i <= m; i++) {
		if (e[u[i]].size() >= 2 && e[v[i]].size() >= 2) {
			q = i;
			if (e[u[i]][0] == q) p = e[u[i]][1];
			else p = e[u[i]][0];
			if (e[v[i]][0] == q) r = e[v[i]][1];
			else r = e[v[i]][0];
		}
	}
	if (q != 0) {
		for (int i = 1; i <= m; i++) {
			int f = 0;
			if (check(i,p)) cout << p << ' ',f = 1;
			else if (check(i,q)) cout << q << ' ',f = 1;
			else if (check(i,r)) cout << r << ' ',f = 1;
			else {
				for (int j = 1; j <= m; j++) {
					if (check(i,j)) {
						cout << j << ' ';
						f = 1;
						break;
					}
				}
			}
			if (f == 0) cout << 0 << ' ';
		}
	}else{
		if (cnt == 1) {
			for (int i = 1; i <= m; i++) {
				cout << 0 << ' ';
			}
		}else{
			int q1 = 0,q2 = 0,f1 = 0,f2 = 0;
			for (int i = 1; i <= n; i++) {
				if (father[i] != i) {
					if (q1 == 0) {
						q1 = e[i][0];
						f1 = father[i];
					}else if (q2 == 0 && father[i] != f1) {
						q2 = e[i][0];
					}
				}
			}
			for (int i = 1; i <= m; i++) {
				if (check(i,q1)) cout << q1 << ' ';
				else cout << q2 << ' ';
			}
		}
	}
	return 0;
=======
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n,m,u[maxn],v[maxn];
vector<int> e[maxn];
inline bool check(int x,int y) {
	int a = u[x],b = v[x],c = u[y], d = v[y];
	if (a != c && a != d && b != c && b != d) return true;
	return false;
}
int father[maxn],rk[maxn],cnt;
inline int find(int x) {
    int t = x;
    while(x != father[x]) x = father[x];
    int w;
    while(t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    --cnt;
    if (rk[p] <= rk[q]) {
        father[p] = q;
        rk[q] = max(rk[q],rk[p]+1);
    }else{
        father[q] = p;
        rk[p] = max(rk[p],rk[q]+1);
    }
}
int p = 0,q = 0,r = 0;
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) father[i] = i;
	cnt = n;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(i);
		e[v[i]].push_back(i);
		merge(u[i],v[i]);
	}
	for (int i = 1; i <= m; i++) {
		if (e[u[i]].size() >= 2 && e[v[i]].size() >= 2) {
			q = i;
			if (e[u[i]][0] == q) p = e[u[i]][1];
			else p = e[u[i]][0];
			if (e[v[i]][0] == q) r = e[v[i]][1];
			else r = e[v[i]][0];
		}
	}
	if (q != 0) {
		for (int i = 1; i <= m; i++) {
			int f = 0;
			if (check(i,p)) cout << p << ' ',f = 1;
			else if (check(i,q)) cout << q << ' ',f = 1;
			else if (check(i,r)) cout << r << ' ',f = 1;
			else {
				for (int j = 1; j <= m; j++) {
					if (check(i,j)) {
						cout << j << ' ';
						f = 1;
						break;
					}
				}
			}
			if (f == 0) cout << 0 << ' ';
		}
	}else{
		if (cnt == 1) {
			for (int i = 1; i <= m; i++) {
				cout << 0 << ' ';
			}
		}else{
			int q1 = 0,q2 = 0,f1 = 0,f2 = 0;
			for (int i = 1; i <= n; i++) {
				if (father[i] != i) {
					if (q1 == 0) {
						q1 = e[i][0];
						f1 = father[i];
					}else if (q2 == 0 && father[i] != f1) {
						q2 = e[i][0];
					}
				}
			}
			for (int i = 1; i <= m; i++) {
				if (check(i,q1)) cout << q1 << ' ';
				else cout << q2 << ' ';
			}
		}
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}