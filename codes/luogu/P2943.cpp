#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4+5;
const int maxs = 2e2+6;
int n,m,sq;
int p[maxn];
int b[maxn][maxs];
int pos[maxs],f[maxn],cnt[maxs];
int main () {
	cin >> n >> m;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) cin >> p[i];
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sq; j++) {
			++b[p[i]][j];
			if (b[p[i]][j] == 1) {
				++cnt[j];
				while (cnt[j] > j) {
					--b[p[pos[j]]][j];
					if (b[p[pos[j]]][j] == 0) --cnt[j];
					++pos[j];
				}
			}
			if (cnt[j] == j) {
				f[i] = min(f[i],f[pos[j]-1]+j*j);
			}
		}
	}
	cout << f[n] << '\n';
	return 0;
}