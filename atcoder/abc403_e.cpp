#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+30;
int q,ans;
int trie[maxn][27],tot = 1,rt = 1;
int edx[maxn],visy[maxn];
int f[maxn];
string s;
int insertx(int &p,int cur) {
	if (!p) p = ++tot;
	if (cur > s.size()-1) {
		int tmp = visy[p];
		ans -= visy[p];
		visy[p] = 0;
		edx[p] = 1;
		return tmp;
	}
	int f = insertx(trie[p][s[cur]-'a'],cur+1);
	visy[p] -= f;
	return f;
}
bool inserty(int &p,int cur,int cnt) {
	if (!p) p = ++tot;
	++visy[p];
	if (edx[p] == 1) return --visy[p],false;
	if (cur > s.size()-1) {
		++ans;
		f[visy[p]] = 1;
		return true;
	}
	bool f = inserty(trie[p][s[cur]-'a'],cur+1,cnt);
	if (!f) --visy[p];
	return f;
}
int main () {
#ifdef LOCAL
	freopen("D:/codes/exe/a.in","r",stdin);
	freopen("D:/codes/exe/a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int opt;
		cin >> opt >> s;
		s = ' ' + s;
		if (opt == 1) {
			insertx(rt,1);
		}else {
			inserty(rt,1,i);
		}
		cout << ans << '\n';
	}
	return 0;
}
