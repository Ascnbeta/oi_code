#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n, s_1[N], s_2[N], sum11[N], sum10[N], sum21[N], sum20[N], tot, pos[N], ans, t_1[N], t_2[N]; 
char s[N];


void subtaska() {
	if(s_1[1] == 0) {
		for (int i = 1; i <= n; i++) {
			if (s_2[i] == 0) ans++;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (s_2[i] == 1) ans++; 
		}
	}
} 

void subtaskb() {
	
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);	
	cin >> T;
	while (T--) {
		cin >> n;
		memset(t_1, 0, sizeof t_1);
		memset(t_2, 0, sizeof t_2);
		memset(s_1, 0, sizeof s_1);
		memset(s_2, 0, sizeof s_2);
		tot = 0, ans = 0;
		for (int i = 1; i <= n; i++) cin >> s[i], s_1[i] = s[i] - '0';
		for (int i = 1; i <= n; i++) cin >> s[i], s_2[i] = s[i] - '0';
		for (int i = 1; i <= n; i++) cin >> s[i], t_1[i] = s[i] - '0';
		for (int i = 1; i <= n; i++) cin >> s[i], t_2[i] = s[i] - '0';
		bool f = 1;
		for (int i = 2; i <= n; i++) {
			if (s_1[i] != s_1[i - 1]) f = 0;
		}
		if (f) {
			subtaska();
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (s_1[i] == s_2[i]) {
				ans++;
			} else {
				bool flag = 0;
				for (int j = i; t_1[j]; j++) {
					if (s_1[j] != s_1[i]) {
						swap(s_1[j], s_1[i]);
						ans++;
						flag = 1;
						break;
					}
				}
				if (!flag) {
					for (int j = i; t_2[j]; j++) {
						if (s_2[j] != s_2[i]) {
							swap(s_2[j], s_2[i]);
							ans++;
							flag = 1;
							break;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}	
	return 0;
} 
/*
		
*/
