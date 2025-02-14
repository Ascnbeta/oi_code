<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct obj{
	int a,b;
	bool operator < (const obj &x) const{
		return a > x.a;
	}
}o[2004];
int f[2004][2004];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> o[i].a >> o[i].b;
	sort(o+1,o+n+1);
	memset(f,0xcf,sizeof(f));
	for (int i = 0; i <= n; i++) f[i][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0; j--) {\
			if (j+1-o[i].a < 1) cout << i << ' ' << j << '\n';
			f[i][j] = max(f[i-1][j],f[i-1][max(j+1-o[i].a,1)]+o[i].b);
		}
	}
	for (int i = 0; i <= n; i++) ans = max(ans,f[n][i]);
	cout << ans << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct obj{
	int a,b;
	bool operator < (const obj &x) const{
		return a > x.a;
	}
}o[2004];
int f[2004][2004];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> o[i].a >> o[i].b;
	sort(o+1,o+n+1);
	memset(f,0xcf,sizeof(f));
	for (int i = 0; i <= n; i++) f[i][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0; j--) {\
			if (j+1-o[i].a < 1) cout << i << ' ' << j << '\n';
			f[i][j] = max(f[i-1][j],f[i-1][max(j+1-o[i].a,1)]+o[i].b);
		}
	}
	for (int i = 0; i <= n; i++) ans = max(ans,f[n][i]);
	cout << ans << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}