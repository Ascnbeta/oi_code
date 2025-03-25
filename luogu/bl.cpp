#include <bits/stdc++.h>
using namespace std;
int T,k;
int b[29],c[29];
string s,ans = " zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/b.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
		ans = " zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		memset(b,0,sizeof(b));
        cin >> k >> s;
		int n = s.size();
		s = ' ' + s;
		for (int i = 1; i <= n; i++) b[s[i]-'a']++;
		for (int i = 1; i < (1<<n); i++) {
			string tmp = " ";
			memset(c,0,sizeof(c));
			int t = i,pt = 1;
			while (t) {
				if (t&1) tmp+=s[pt];
				t >>= 1;
				++pt;
			}
			for (int j = 1;j < tmp.size(); j++) {
				++c[tmp[j]-'a'];
			}
			int cnt = 0;;
			for (int j = 0; j <= 25; j++) {
				if (b[j] == 0) {
					assert(c[j]==0);
					continue;
				}
				if (c[j] == 0) ++cnt;
			}
			if (cnt != k) continue;
			ans = min(ans,tmp);
		}
		if (ans == " zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i < ans.size(); i++) cout << ans[i];
		cout << '\n';
    }
    return 0;
}