#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e3+4,maxm = 2e2+4;
int n,m,K;
string a,b;
int f[maxm][maxm][2];
int main () {
	cin >> n >> m >> K >> a >> b;
	a = ' ' + a,b = ' ' + b;
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			for (int k = K; k >= 0; k--) {
				f[j][k][0] = (f[j][k][0]%mod+f[j][k][1]%mod)%mod;
				if (a[i]==b[j]) {
					if (k >= 1) f[j][k][1] = ((f[j-1][k][1]%mod+f[j-1][k-1][1]%mod)%mod+f[j-1][k-1][0]%mod)%mod;
					else f[j][k][1] = f[j-1][k][1]%mod;
				}else{
					f[j][k][1] = 0;
				}
				
			}
		}
	}
	cout <<(f[m][K][0]+f[m][K][1])%mod << '\n';
	return 0;
}	