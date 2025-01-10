#include <bits/stdc++.h>
using namespace std;
int n,m,tmm;
vector<int> t[100005];
int sum[100005],ans[100005];
bool cmp(int x,int y) {
	return x > y;
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n ; i++) {
		int x,y;
		cin >> x >> y;
		t[x].push_back(y);
	}
	for (int i = 1; i <= m ; i++) {
		int tmp = t[i].size();
		tmm = max(tmm,tmp);
		if (tmp == 0) continue;
		sort(t[i].begin(), t[i].end(), cmp );
		
		sum[1] = t[i][0];
		if (sum[1] <= 0) continue;
		ans[1] += sum[1];
		for (int j = 1; j < t[i].size(); j++) {
			sum[j+1] = sum[j] + t[i][j];
			if (sum[j+1] <= 0) continue;
			else ans[j+1] += sum[j+1];
		}
	}
	int anss = -1;
	for (int i = 1; i <= tmm; i++) {
		anss = max(ans[i],anss);
	}
	cout << anss << endl;
	return 0;
}
