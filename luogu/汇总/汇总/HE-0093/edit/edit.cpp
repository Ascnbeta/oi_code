#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 100;
int t;
int n;
string a, b, c, d;
int flag1[N], flag2[N];
signed main(){
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		int cnt1 = 0;
		int cnt2 = 0; 
		int ans = 0;
		cin >> n;
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;
		a = " " + a;
		b = " " + b;
		c = " " + c;
		d = " " + d;
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == a[i + 1]) cnt1++;
			if(c[i] == d[i]) cnt2++;
			if(c[i] == '1') flag1[i] = 1;
			if(d[i] == '1') flag2[i] = 1;
		}
		if(cnt == n - 1){
			for(int i = 1 ; i <= n ; i++)
				if(a[1] == b[i]) ans++;
			cout << ans << '\n';
		}
		else{
			for(int i = 1 ; i <= n ; i++)
				if(a[i] == b[i]) ans++;
			cout << ans << '\n';
		}
	}
	return 0;
} 
