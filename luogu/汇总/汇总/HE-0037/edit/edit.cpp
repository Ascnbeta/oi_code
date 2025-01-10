#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
char read_ch() {
	char ch = getchar();
	while(ch != '0' && ch != '1') ch = getchar();
	return ch;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int N = 1e5 + 5;

int n;
int s0[N], s1[N];
int ex0[N], ex1[N];

int cnt[N][2], tot;
int BL0[N], BL1[N];
int L[N], R[N];
void calc1() {
	int l = 1, r = 1;
	while(l <= n) {
		while(r <= n && ex0[r]) r++; // [l, r)
		tot++;
		L[tot] = l;
		R[tot] = r;
		for(int i = l; i < r; i++) {
			BL0[i] = tot;
			cnt[tot][s0[i]]++;
		}
		l = r + 1;
		r++;
	}
	return;
}
void calc2() {
	int l = 1, r = 1;
	while(l <= n) {
		while(r <= n && ex1[r]) r++; // [l, r)
		tot++;
		L[tot] = l;
		R[tot] = r;
		for(int i = l; i < r; i++) {
			BL1[i] = tot;
			cnt[tot][s1[i]]++;
		}
		l = r + 1;
		r++;
	}
	return;
}

void init() {
	for(int i = 1; i <= tot; i++) cnt[i][0] = cnt[i][1] = 0;
	tot = 0;
	return;
}
void solve() {
	bool case_A = true, case_B = true;
	n = read();
	for(int i = 1; i <= n; i++) {
		s0[i] = read_ch() == '1';
		case_A &= (s0[i] == s0[1]);
	}
	for(int i = 1; i <= n; i++) s1[i] = read_ch() == '1';
	int cnt00 = 0, cnt01 = 0;
	for(int i = 1; i <= n; i++) {
		ex0[i] = read_ch() == '1';
		cnt00 += !ex0[i];
	}
	for(int i = 1; i <= n; i++) {
		ex1[i] = read_ch() == '1';
		cnt01 += !ex1[i];
		case_B &= (ex0[i] == ex1[i]);
	}

	calc1();
	calc2();

	int ans = 0;
	if(case_A) {
		for(int i = 1; i <= n; i++) ans += s1[i] == s0[1];
	} else if(case_B) {
		for(int i = 1; i <= n; i++) {
			if(!ex0[i]) ans += s0[i] == s1[i];
			else {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
					ans++;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
					ans++;
				}
			}
		}
	} else if(cnt00 == 1 && cnt01 == 1) {
		int pos1 = 0, pos2 = 0;
		for(int i = 1; i <= n; i++) {
			if(!ex0[i]) {
				pos1 = i;
				break;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(!ex1[i]) {
				pos2 = i;
				break;
			}
		}
		if(cnt[BL1[pos1]][s0[pos1]]) {
			ans++;
			cnt[BL1[pos1]][s0[pos1]]--;
		}
		if(cnt[BL0[pos2]][s1[pos2]]) {
			ans++;
			cnt[BL0[pos2]][s1[pos2]]--;
		}
		if(pos1 <= pos2) {
			for(int i = pos1 + 1; i < pos2; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
			for(int i = 1; i < pos1; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
			for(int i = pos2 + 1; i <= n; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
		} else {
			for(int i = pos2 + 1; i < pos1; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
			for(int i = 1; i < pos2; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
			for(int i = pos1 + 1; i <= n; i++) {
				if(cnt[BL0[i]][0] && cnt[BL1[i]][0]) {
					ans++;
					cnt[BL0[i]][0]--;
					cnt[BL1[i]][0]--;
				} else if(cnt[BL0[i]][1] && cnt[BL1[i]][1]) {
					ans++;
					cnt[BL0[i]][1]--;
					cnt[BL1[i]][1]--;
				}
			}
		}
	} else  {
		for(int i = 1; i <= 1000; i++) {
			int l = 1, r = 1;
			while(l <= n) {
				while(r <= n && ex0[r]) r++; // [l, r)
				if(l < r)random_shuffle(s0 + l, s0 + r);
				l = r + 1;
				r++;
			}
			l = r = 1;
			while(l <= n) {
				while(r <= n && ex1[r]) r++; // [l, r)
				if(l < r)random_shuffle(s1 + l, s1 + r);
				l = r + 1;
				r++;
			}
			int tmp = 0;
			for(int j = 1; j <= n; j++) tmp += s0[j] == s1[j];
			ans = max(ans, tmp);
		}
	}

	print(ans);
	putchar('\n');

	return;
}
int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);

	int T = read();
	while(T--) solve();
	return 0;
}
