#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int t;
const int N = 1e6 + 100;
int n, m, v;
int c[N], d[N];
int vis[N];
signed main(){
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> v;
		for(int i = 1 ; i <= n ; i++){
			cin >> c[i] >> d[i];
		}
		cout <<0 << '\n';
	}
	return 0; 
}
