#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool a1[N], yep1[N];
bool a2[N], yep2[N];


int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --) {
		int n, ans = 0;
		char s;
		cin >> n;
		for(int i = 1; i <= n; ++ i) {
			cin >> s;
			a1[i] = (bool)(s - '0');
		}
		for(int i = 1; i <= n; ++ i) {
			cin >> s;
			a2[i] = (bool)(s - '0');
		}
		for(int i = 1; i <= n; ++ i) {
			cin >> s;
			yep1[i] = (bool)(s - '0');
		}
		for(int i = 1; i <= n; ++ i) {
			cin >> s;
			yep2[i] = (bool)(s - '0');
		}
		int i = 1, j = 1, pos = 1,num10 = 0, num11 = 0, num20 = 0, num21 = 0;
		while(yep1[i] && i <= n) {
			if(a1[i]) num11 ++;
			else num10 ++;
			i ++;
		}
		while(yep2[j] && j <= n) {
			if(a2[j]) num21 ++;
			else num20 ++;
			j ++;
		}
		while(pos <= n) {
			while(pos < min(i, j)) {
				if(yep2[pos]) {
					if(yep1[pos]) {
						if(num11 && num21) ans ++, num11 --, num21 --;
						if(num10 && num20) ans ++, num10 --, num20 --;
					} else {
						if(a1[pos] && num21) ans ++, num21 --;
						if(!a1[pos] && num20) ans ++, num20 --;
					}
				} else {
					if(yep1[pos]) {
						if(a2[pos] && num11) ans ++, num11 --;
						if(!a2[pos] && num10) ans ++, num10 --;
					} else if(a1[pos] == a2[pos]) ans ++;
				}
				pos ++;
			}
			if(i <= j && i <= n) {
				while(!yep1[i] && i <= n)i ++;
				num10 = 0, num11 = 0;
				while(yep1[i] && i <= n) {
					if(a1[i]) num11 ++;
					else num10 ++;
					i ++;
				}
			}
			if(pos == j && j <= n) {
				while(!yep2[j] && j <= n) j ++;
				num21 = 0, num20 = 0;
				while(yep2[j] && j <= n) {
					if(a2[j]) num21 ++;
					else num20 ++;
					j ++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
/*
1
6
011101
111010
111010
101101
*/
