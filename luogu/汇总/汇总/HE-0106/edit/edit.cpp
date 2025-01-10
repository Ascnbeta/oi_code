#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int sum1[N][2], sum2[N][2];
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s1, s2; cin >> s1 >> s2;
		
		s1 = ' ' + s1; s2 = ' ' + s2;
		string t1, t2; cin >> t1 >> t2;
		t1 = ' ' + t1; t2 = ' ' + t2;		
		int cnt1 = 0, cnt2 = 0, kk, kk2;
		for (int i = 1; i <= n; i++) {
			if (s1[i] == '0') cnt1 ++, kk = i;
			if (s2[i] == '0') cnt2 ++, kk2 = i;
		}
		
		if (cnt1 == 1 && cnt2 == 1) {
			int l1, r2,r1,l2;
			for (int i = kk; i >= 1 && t1[i] == '1'; i--) l1 = i;
			for (int i = kk; i <= n && t1[i] == '1'; i++) r1 = i;
			for (int i = kk2; i >= 1 && t2[i] == '1'; i--) l2 = i;
			for (int i = kk2; i <= n && t2[i] == '1'; i++) r2 = i;
			if ((l1 >= l2 && l1 <= r2) || (l2 >= l1 && l2 <= r1)) {
				cout << n << "\n";
			} else cout << n - 2 << "\n";
			return 0;
		}
		
		for (int i = 1; i <= n; i++) {
			int tp = s1[i] - '0', tp2 = s2[i] - '0';
			sum1[i][tp] = sum1[i - 1][tp] + 1;
			sum1[i][!tp] = sum1[i - 1][!tp];
			sum2[i][tp2] = sum2[i - 1][tp2] + 1;
			sum2[i][!tp2] = sum2[i - 1][!tp2];
		}

		int l = 1, r = 0, ans = 0, now;
		for (int i = 1; i <= n; i++) {
			//cout << i << " " << t1[i] << " " <<t1[i - 1]<<"  "<<t2[i] <<" "<<t2[i - 1]<< " ";
			if (((t1[i]-'0') && (t1[i - 1]-'0')) || ((t2[i]-'0') && (t2[i - 1]-'0'))) r = i;
			else {
				ans += min(sum1[r][1] - sum1[l - 1][1], sum2[r][1] - sum2[l - 1][1])
				 + min(sum1[r][0] - sum1[l - 1][0], sum2[r][0] - sum2[l - 1][0]);
				l = i; r = i ;
			}
		//	cout << ans << " ";
		//	cout << l << " " << r << "\n";
		}
		if(r >= l - 1)
		ans += min(sum1[r][1] - sum1[l - 1][1], sum2[r][1] - sum2[l - 1][1])
				 + min(sum1[r][0] - sum1[l - 1][0], sum2[r][0] - sum2[l - 1][0]);
		cout << ans << "\n";
	}
	return 0;
}
/*

看来要退役了 

1
6
011101
111010
111010
101101

1
5
11011
01111
11000
01111
*/ 
