#include <bits/stdc++.h>
using namespace std;

struct qwq{
	int one,zero;
}tot1[114514],tot2[114514];
int T;
int n;
bool s1[114514],s2[114514];
bool t1[114514],t2[114514];
bool c1[114514],c2[114514];
int use1[114514],use2[114514];
int now1 = 1,now2 = 1;
int ans1[114514],ans2[114514];
int ans;

int main ( ) {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin >> T ;
	while (T--) {
		cin >> n ;
		for (int i = 1;i <= n;++i) {
			char c;cin >> c ;
			if (c == '1') s1[i] = 1;
			else s1[i] = 0;
		}
		for (int i = 1;i <= n;++i) {
			char c;cin >> c ;
			if (c == '1') s2[i] = 1;
			else s2[i] = 0;
		}
		for (int i = 1;i <= n;++i) {
			char c;cin >> c ;
			if (c == '1') t1[i] = 1;
			else t1[i] = 0;
		}
		for (int i = 1;i <= n;++i) {
			char c;cin >> c ;
			if (c == '1') t2[i] = 1;
			else t2[i] = 0;
		}		
		for (int i = 2;i <= n;++i) {
			if (t1[i] == 1 && t1[i - 1] == 1) c1[i] = c1[i - 1] = 1;
			if (t2[i] == 1 && t2[i - 1] == 1) c2[i] = c2[i - 1] = 1;
		}
		for (int i = 1;i <= n;++i) {
			if (c1[i - 1] == 1 && c1[i] == 0) ++now1;
			else if (c1[i - 1] != 0 || c1[i] != 0) {
				if (s1[i] == 1) ++tot1[now1].one;
				else ++tot1[now1].zero;
			}
			if (c2[i - 1] == 1 && c2[i] == 0) ++now2;
			else if (c2[i - 1] != 0 || c2[i] != 0) {
				if (s2[i] == 1) ++tot2[now2].one;
				else ++tot2[now2].zero;
			}
			use1[i] = now1;
			use2[i] = now2;
		}
		for (int i = 1;i <= n;++i) {
			if (c1[i] == 1 && c2[i] == 0) {
				if (s2[i] == 1 && tot1[use1[i]].one > 0) {
					--tot1[use1[i]].one;
					ans1[i] = 1;
					ans2[i] = 1;
				}
				else if (s2[i] == 0 && tot1[use1[i]].zero >= 1) {
					--tot1[use1[i]].zero;
					ans1[i] = 0;
					ans2[i] = 0;
				}
				else if (tot1[use1[i]].one > 0) {
					--tot1[use1[i]].one;
					ans1[i] = 1;
					ans2[i] = 0;
				}
				else {
					--tot1[use1[i]].zero;
					ans1[i] = 0;
					ans2[i] = 1;
				}
			}
			else if (c1[i] == 0 && c2[i] == 1) {
				if (s1[i] == 1 && tot2[use2[i]].one > 0) {
					--tot2[use2[i]].one;
					ans2[i] = 1;
					ans1[i] = 1;
				}
				else if (s1[i] == 0 && tot2[use2[i]].zero >= 1) {
					--tot2[use2[i]].zero;
					ans2[i] = 0;
					ans1[i] = 0;
				}
				else if (tot2[use2[i]].one > 0){
					--tot2[use2[i]].one;
					ans2[i] = 1;
					ans1[i] = 0;
				}
				else {
					--tot2[use2[i]].zero;
					ans2[i] = 0;
					ans1[i] = 1;
				}
			}
			else if (c1[i] == 0 && c2[i] == 0) {
				ans1[i] = s1[i];
				ans2[i] = s2[i];
			}
			else {
				if (tot1[use1[i]].one > 0 && tot2[use2[i]].one > 0) ans1[i] = 1,ans2[i] = 1,--tot1[use1[i]].one,--tot2[use2[i]].one;
				else if (tot1[use1[i]].zero > 0 && tot2[use2[i]].zero > 0) ans1[i] = 0,ans2[i] = 0,--tot1[use1[i]].zero,--tot2[use2[i]].zero;
				else if (tot1[use1[i]].one > 0 && tot2[use2[i]].zero > 0) ans1[i] = 1,ans2[i] = 0,--tot1[use1[i]].one,--tot2[use2[i]].zero;
				else if (tot1[use1[i]].zero > 0 && tot2[use2[i]].one > 0) ans1[i] = 0,ans2[i] = 1,--tot1[use1[i]].zero,--tot2[use2[i]].one;
			}
		}
		for (int i = 1;i <= n;++i) if (ans1[i] == ans2[i]) ++ans;
		cout << ans << '\n' ;
		now1 = now2 = ans = 0;
		for (int i = 1;i <= n;++i) c1[i] = c2[i] = 0;
	}
}
/*

*/
