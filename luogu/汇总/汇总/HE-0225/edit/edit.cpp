#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int T, ans;
int n, sum1[N], sum2[N];
string s1, s2, t1, t2, mj;
char q;
bool flag;

int main() {
	
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T --) {
		cin >> n;
		sum1[0] = sum2[0] = 0;
		ans = 0;
		flag = true;
		cin >> s1 >> s2; 
		for(int i = 0; i < n; i ++) {
			if(i == 0) q = s1[i];
			else if(q != s1[i]) {
				flag = false;
			}
			if(i > 0) sum1[i] = sum1[i - 1];
			if(s1[i] == '1') sum1[i] ++;
		}
		for(int i = 0; i < n; i ++) {
			if(i > 0) sum2[i] = sum2[i - 1];
			if(s2[i] == '1') sum2[i] ++;
		}
		cin >> t1 >> t2;
		if(flag == true) {
			if(q == '0') {
				cout << n - sum2[n - 1] << '\n';
			}else cout << sum2[n - 1] << '\n';
		}else if(t1 == t2) {
			bool yon = false;
			int l = 0, r;
			for(int i = 0; i < n; i ++) {
				if(t1[i] == '0') 
					if(s1[i] == s2[i]) 
						ans ++;
				if(t1[i] == '0' && yon == false) {
					yon = true;
					r = i - 1;
					if(l > r) continue;
					int len = r - l + 1;
					int yi = sum1[r] - sum1[l] + (int)(s1[l] - '0');
					int er = sum2[r] - sum2[l] + (int)(s2[l] - '0');
					ans += len + min(yi, er) - max(yi, er);
				}else if(t1[i] == '1' && yon == true) {
					yon = false;
					l = i;
				}
			}
			if(yon == false) {
				int r = n - 1;
				int len = r - l + 1;
				int yi = sum1[r] - sum1[l] + (int)(s1[l] - '0');
				int er = sum2[r] - sum2[l] + (int)(s2[l] - '0');
				ans += len + min(yi, er) - max(yi, er);
			}
			cout << ans << '\n';
		}else {
			cout << "YES" << '\n';
		}
	}
	
	return 0;
	
}
