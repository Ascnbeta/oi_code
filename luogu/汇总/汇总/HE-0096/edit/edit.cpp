#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 1e5 + 10 ;
int sum1[MAXN], sum2[MAXN], sum3[MAXN], sum4[MAXN] ;
int kkk[MAXN] ;
int main () {
	freopen("edit.in","r",stdin) ;
	freopen("edit.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	int t, n;
	cin >> t ;
	string s1, s2, t1, t2 ;
	while (t--) {
		int g = 0, h = 0 ;
		cin >> n ;
		for (int i = 1 ; i <= n ; i++) {
			sum1[i] = 0 ;
			sum2[i] = 0 ;
			sum3[i] = 0 ;
			sum4[i] = 0 ;
		}
		string s3 ;
		cin >> s1 >> s2 >> t1 >> t2 ;
		s1 = " " + s1, s2 = " " + s2, t1 = " " + t1, t2 = " " + t2 ;
		int pos1, pos2 ;
		bool key = 1 ;
		for (int i = 1 ; i <= n ; i++) {
			if (t1[i] == '0') pos1 = i, h++ ;
			if (t2[i] == '0') pos2 = i, g++ ;
			sum2[i] = sum2[i - 1] ;
			sum1[i] = sum1[i - 1] ;
			if (s1[i] != s1[i - 1] && i > 1) key = 0 ;
			if (s2[i] == '1') sum2[i]++ ;
			if (s2[i] == '0') sum1[i]++ ;
		}
		if (t1 == t2) {
			int ans = 0, a = 0, b = 0, c = 0, d = 0 ;
			for (int i = 1 ; i <= n ; i++) {
				if (t1[i] != '0'){
					if (s1[i] == '1') a++ ;
					if (s1[i] == '0') b++ ;
					if (s2[i] == '1') c++ ;
					if (s2[i] == '0') d++ ;
				}
				if (i == n) ans += min(a, c) + min (b, d) ;
				if (t1[i] == '0') {
					ans += min (a, c) + min (b, d) ;
					a = 0, b = 0, c = 0, d = 0 ;
					if (s1[i] == s2[i]) ans++ ;
				}
			}
			cout << ans << '\n' ;
			continue ;
		}
		else if (g == 1 && h == 1) {
			int a = 0, b = 0, c = 0, d = 0 ;
			int k = max(pos1, pos2) ;
			for (int i = k + 1 ; i <= n ; i++) {
				if (s1[i] == '1') a++ ;
				if (s1[i] == '0') b++ ;
				if (s2[i] == '1') c++ ;
				if (s2[i] == '0') d++ ;
			}
			int ans = min(a, c) + min (b, d) ;
			a = 0, b = 0, c = 0, d = 0 ;
			for (int i = 1 ; i <= k ; i++) {
				if (s1[i] == '1') a++ ;
				if (s1[i] == '0') b++ ;
				if (s2[i] == '1') c++ ;
				if (s2[i] == '0') d++ ;
			}
			ans += min(a, c) + min(b, d) ;
			if (pos1 < pos2) ans-= 2 ;
//			if (b == 1 || d == 1) ans-= 2 ;
			cout << ans << '\n' ;
			continue ;
		}
		else if (key) {
			if (s1[1] == '1') cout << sum2[n] << '\n' ;
			else cout << sum1[n] << '\n' ;
			continue ;
		}
		else {
			int a = 0, b = 0, c = 0, d = 0, tot = 0,ans = 0 ;
			for (int i = 1 ; i <= n ; i++) {
				if (t2[i] == '0') {
					continue ;	
					kkk[++tot] = i ;
				}
				if (s1[i] == '1') a++ ;
				if (s1[i] == '0') b++ ;
				if (s2[i] == '1') c++ ;
				if (s2[i] == '0') d++ ;
			}
			for (int i = 1 ; i <= tot ; i++) if (s1[kkk[i]] == s2[kkk[i]]) ans++ ;
			ans += min(a, c) + min(b, d) ;
			cout << ans + 1 << '\n' ;
			continue ;
		}
	}
}
