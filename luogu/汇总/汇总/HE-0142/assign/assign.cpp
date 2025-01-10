#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
const int maxm = 1e5+5;
const long long ll1 = 1;

int t;
int n, m, v;
bool f;
struct xian{
	int c, d;
} lin[maxm];
int nex[1000005];
long long ans;
bool dis1;

bool cmp(xian a, xian b) {
	if (a.c != b.c) return a.c < b.c;
	return a.d <= b.d;
}

int main () {
	
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n >> m >> v;
		dis1 = true;
		for (int i = 1; i <= m; i++) {
			cin >> lin[i].c >> lin[i].d;
			if (lin[i].d != 1) dis1 = false;
		}
		sort(lin + 1, lin + m + 1, cmp);
		
		if (m == 1) {
			ans = (ll1 * v * v) % mod;
			cout << ans << endl;
			continue;
		}
		
		if (dis1) {
			bool ok = true;
			for (int i = 2; i <= m; i++) {
				if (lin[i].c - lin[i-1].c == 1) {
					ok = false;
					break;
				}
			}
			if (ok) ans = (ll1 * v * v) % mod;
			else {
				ans = (ll1 * (v-1) * v) % mod;
				ans++;
				ans %= mod;
			} 
			cout << ans << endl;
			continue;
		}
		
		f = true;
		for (int i = 2; i <= m; i++) {
			if (lin[i - 1].c == lin[i].c) {
				if (lin[i-1].d != lin[i].d) {
					cout << 0 << endl;
					f = false;
					break;
				}
			}
		}
		if (!f) continue;
		
		for (int i = 1; i <= v; i++) nex[i] = 0;
		for (int i = 2; i <= m; i++) {
			if (lin[i].c - lin[i-1].c == 1) {
				if (!nex[lin[i-1].d]) nex[lin[i-1].d] = lin[i].d;
				else {
					if(nex[lin[i-1].d] != lin[i].d) {
						cout << 0 << endl;
						f = false;
						break;
					}
				}
			}
		}
		if (!f) continue;
		
		ans = 0;
		for (int i = 1; i <= v; i++) {
			if (!nex[i]) ans = (ans + v) % mod;
			else ans = (ans + 1) % mod;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

/*
3
2 1 2
1 1
2 2 2
1 1 
2 2 
2 2 2
1 1 
1 2

1
3 2 3
1 1
3 1

1
10 5 3
1 1
2 2
4 1
5 2
6 3
*/
