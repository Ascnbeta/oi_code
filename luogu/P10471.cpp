#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,ans;
int a[maxn];
int trie[maxn*32][2],ed[maxn*32],tot = 1;
signed main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		string s = "";
		for (int j = 32; j >= 0; j--) {
			if (a[i]>>j&1) s += '1';
			else s += '0';
		}
		int u = 1;
		for (int j = 0; j < s.size(); j++) {
			int v = s[j]-'0';
			if (!trie[u][v^1]) u = trie[u][v];
			else u = trie[u][v^1];
		}
		ans = max(ans,ed[u]^a[i]);
		u = 1;
		for (int j = 0; j < s.size(); j++) {
			int v = s[j]-'0';
			if (!trie[u][v]) trie[u][v] = ++tot;
			u = trie[u][v];
		}
		ed[u] = a[i];
 	}
 	cout << ans << '\n';
	return 0;
}