#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
int T,n,k;
long long st1[N][30],st2[N][30];
int f[N],ans1,ans2;
inline void init() {
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st1[i][j] = max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j] = min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int query(int l,int r) {
	int j = f[r-l+1];
	int q1 = max(st1[l][j],st1[r-(1<<j)+1][j]);
	int q2 = min(st2[l][j],st2[r-(1<<j)+1][j]);
	return q1 - q2;
}
inline bool check(int x) {
	int tmp = 0;
	for (int i = 1; i + x - 1 <= n; i++) {
		if (query(i,i+x-1) >= ans1) ++tmp;
	}
	if (tmp < k) return false;
	else return true;
}
int main () {
	cin >> T;
	for (int i = 2; i <= N; i++) {
		f[i] = f[i/2]+1;
	}
	while(T--) {
		cin >> n >> k;
		ans1 = INT_MAX;
		memset(st1,0,sizeof(st1));
		memset(st2,0x3f,sizeof(st2));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			st1[i][0] = st2[i][0] = x;
		}
		init();
		int len = n - k + 1;
		for (int i = 1; i + len - 1 <= n; i++) {
			ans1 = min(ans1,query(i,i+len-1));
		}
		cout << ans1 << ' ';
		int l = 1,r = len;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}	
		cout << l << '\n';
	}
	return 0;
}