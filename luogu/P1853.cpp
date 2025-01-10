#include <bits/stdc++.h>
#define int long long
using namespace std;
int s,n,d;
int w[4003],v[4003];
int f[6000006];
inline int max(int x,int y) {
	return x>y?x:y;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> s >> n >> d;
	for (int i = 1; i <= d; i++) {
		cin >> w[i] >> v[i];
	}
	for (int y = 1; y <= n; y++) {
		for (int i = 1; i <= d; i++) {
			for (int k = w[i]/1000; k <= s/1000; k++) {
				if(k >= w[i]/1000) f[k]= max(f[k],f[k-w[i]/1000]+v[i]);
				
			}
		}
		s += f[s/1000];
		memset(f,0,sizeof(f));
	}
	cout << s << '\n';
	return 0;
}
