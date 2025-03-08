#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4+50;
int n;
int minp[maxn],tot,p[maxn];
int phi[maxn];
int sum = 0;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	if (n == 1) {
		puts("0");
		return 0;
	}
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!minp[i]) {
			p[++tot] = i;
			minp[i] = tot;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= minp[i] && p[j] * i <= n; j++) {
			minp[p[j]*i] = j;
			if (i % p[j] != 0) {
				phi[p[j]*i] = (p[j]-1)*phi[i];
			}else{
				phi[p[j]*i] = p[j]*phi[i];
			}
		}
	}
	for (int i = 1; i <= n-1; i++) sum += 2*phi[i];
	cout << sum + 1 << '\n';
	return 0;
}