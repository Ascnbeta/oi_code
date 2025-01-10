#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
string s1,s2,t1,t2;
int cnt1[2][100005],cnt2[2][100005];
vector<int> d1,d2;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("edit5.in","r",stdin);
//	freopen("edit.out","w",stdout);
	cin >> T;
	while (T--) {
		s1 = s2 = t1 = t2 = "";
		cnt1[0][0] = cnt1[1][0] = cnt2[0][0] = cnt2[1][0] = ans = 0;
		cin >> n >> s1 >> s2 >> t1 >> t2;
		s1 = ' ' + s1;
		s2 = ' ' + s2;
		t1 = ' ' + t1;
		t2 = ' ' + t2;
		bool fa = true;
		for (int i = 1; i <= n; i++) {
			if (i != n && s1[i+1] != s1[i]) fa = false;
			if (s1[i] == '1') cnt1[1][i] = cnt1[1][i-1]+1,cnt1[0][i] = cnt1[0][i-1];
			else cnt1[1][i] = cnt1[1][i-1],cnt1[0][i] = cnt1[0][i-1]+1;
			if (s2[i] == '1') cnt2[1][i] = cnt2[1][i-1]+1,cnt2[0][i] = cnt2[0][i-1];
			else cnt2[0][i] = cnt2[0][i-1]+1,cnt2[1][i] = cnt2[1][i-1];
			if (t1[i] == '0') d1.push_back(i);
			if (t2[i] == '0') d2.push_back(i);
			if (t1[i] == '0' && t2[i] == '0' && s1[i] == s2[i]) ++ans;
		}
		d1.push_back(n+1);
		d2.push_back(n+1);
		int li = 0,lj = 0;
//		for (int i = 0,j = 0; i < d1.size() || j < d2.size();) {
//			if (d1[i] < d2[j]) {
//				int tmp1 = min(cnt1[1][d1[i]]-cnt1[1][li],cnt2[1][d2[j]-1]-cnt2[1][lj]);
//				ans += tmp1;
//				cnt2[1][d2[j]-1] -= tmp1;
//				int tmp0 = min(cnt1[0][d1[i]]-cnt1[0][li],cnt2[0][d2[j]-1]-cnt2[0][lj]);
//				ans += tmp0;
//				cnt2[0][d2[j]-1] -= tmp0;
//				li = d1[i];
//				lj = 
//				++i;
//				if (i == d1.size()) continue;
//				cnt1[1][d1[i]] -= tmp1;
//				cnt1[0][d1[i]] -= tmp0;
//			}else if(d1[i] > d2[j]) {
//				
//			}
//		}
		if (fa) {
			cout << 1 << '\n';
			char x = s1[1];
			for (int i = 1; i <= n; i++) {
				if (s2[i] == x) ++ans;
			}
			cout << ans << '\n';
			continue;//20 pts
		}
		if (t1 == t2) {
			for (int i = 0; i < d1.size(); i++) {
				int tmp1 = min(cnt1[1][d1[i]-1]-cnt1[1][li],cnt2[1][d1[i]-1]-cnt2[1][li]);
				ans += tmp1;
				int tmp0 = min(cnt1[0][d1[i]-1]-cnt1[0][li],cnt2[0][d1[i]-1]-cnt2[0][li]);
				ans += tmp0;
				li = d1[i];
			}
			cout << ans << '\n';
			continue;//40 pts
		}
	}
	return 0;
}
