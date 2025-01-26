#include <bits/stdc++.h>
using namespace std;
int n,T,p,k;
struct team{
	int lac,lrac,cnt;
	bool f[104];
}t[105];
int ans1 = -1,ans2 = -1,ans3 = -1,ans4 = -1;
int tmp1,tmp2,tmp3,tmp4;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> T >> p >> k;
	for (int i = 1; i <= n; i++) {
		int tid,pid,st;
		cin >> tid >> pid >> st;
		if (st == 0) continue;
		t[tid].lac = i;
		if (t[tid].f[pid]) continue;
		t[tid].f[pid] = true;
		++t[tid].cnt;
		t[tid].lrac = i;
		if (t[tid].cnt == 1) ans4 = tid;
	}
	for (int i = 1; i <= T; i++) {
		if (t[i].lac > tmp1) ans1 = i,tmp1 = t[i].lac;
		if (t[i].lrac > tmp2) ans2 = i,tmp2 = t[i].lrac;
		if (t[i].cnt < k && t[i].lrac > tmp3) ans3 = i,tmp3 = t[i].lrac;
		
	}
	cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';
	return 0;
}