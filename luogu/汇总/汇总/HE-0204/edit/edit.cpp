#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 5;

int n, s_1[N], s_2[N], t_1[N], t_2[N], t_3[N], ed[2];

void play() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s_1[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s_2[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		t_1[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		t_2[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) if (t_1[i - 1] == 0 && t_1[i + 1] == 0) t_1[i] = 0;
	for (int i = 1; i <= n; i++) if (t_2[i - 1] == 0 && t_2[i + 1] == 0) t_2[i] = 0;
	for (int i = 1; i <= n; i++) t_3[i] = t_1[i] | t_2[i];
	int ans1 = 0; ed[1] = 0, ed[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (t_3[i] == 0) ed[1] = ed[0] = i;
		if (t_3[i] == 0 && s_1[i] == s_2[i]) {ans1++;continue;}
		for (int j = ed[s_1[i]] + 1; j <= n; j++) {
			if (t_3[j] == 0) break;
			if (s_1[i] == s_2[j]) {
				if (t_1[i] == 0 && t_2[j] == 0) break;
				cout << i << ' ' << j << '\n';
				ans1++;
				ed[s_1[i]] = j;
				break;
			}
			
		}
	}
	cout << ans1 << '\n';
}

signed main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) play();
	return 0;
}
/*
1
6
1 1 1 0 1 0
0 1 0 1 1 1
1 1 0 1 1 1
1 1 1 1 0 1
*/

