#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxm = 100000 + 10;
const int mod = 1000000000 + 7;

int T, n, m, v;
int c[maxm], d[maxm];

signed main(){
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> v;
		bool flaga = true;
		for(int i = 1; i <= n; i++){
			cin >> c[i] >> d[i];
			if(c[i] != i)
				flaga = false;
		}
		if(flaga)
		{
			int ans = 1;
			for(int i = 1; i <= n - 1; i++)
				ans = ans * (1 + (v - 1) * v % mod) % mod;
			cout << ans << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
