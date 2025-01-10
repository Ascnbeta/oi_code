#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = a; i <= b; ++i)
#define rep(i, a, b) for (int i = a; i >= b; --i)
#define ep(i, u) for (int i = H[u]; i; i = e[i].n)

typedef long long ll;
const int _ = 2e5 + 7;

enum { _1, _2 };
int T, n, ans, c[_][2][2], x[_][2]; //c[i][_1][0], x[i][_1]
char s[2][_], t[_];

void S(char s[], char t[], int id) {
	int lst = n + 1;
	rep(i, n, 1) {
		if (t[i] == '0') lst = i, --c[lst][id][s[i] - '0']; x[i][id] = lst;
		if (s[i] == '0') ++c[lst][id][0];
		else ++c[lst][id][1];
	}
}
void C() {
	lep(i, 1, n) c[i][0][0] = c[i][0][1] = c[i][1][0] = c[i][1][1] = x[i][0] = x[i][1] = 0;
	ans = 0;
}

int main() {
	
	freopen("edit.in", "r", stdin);
	freopen("edit.out","w",stdout);
	
	scanf("%d", & T);
	while (T--) {
		scanf("%d", & n);
		scanf("%s%s", s[_1] + 1, s[_2] + 1);
		scanf("%s", t + 1), S(s[_1], t, 0);
		scanf("%s", t + 1), S(s[_2], t, 1);
		lep(i, 1, n) {
			if (x[i][_1] == i and x[i][_2] != i and c[x[i][_2]][_2][s[_1][i] - '0']) { --c[x[i][_2]][_2][s[_1][i] - '0'], ++ans; continue; }
			if (x[i][_2] == i and x[i][_1] != i and c[x[i][_1]][_1][s[_2][i] - '0']) { --c[x[i][_1]][_1][s[_2][i] - '0'], ++ans; continue; }
			if (x[i][_1] == i and x[i][_2] == i and s[_1][i] == s[_2][i]) { ++ans; continue; }
			if (x[i][_1] != i and x[i][_2] != i) {
				if (c[x[i][_1]][_1][0] and c[x[i][_2]][_2][0]) { --c[x[i][_1]][_1][0], --c[x[i][_2]][_2][0], ++ans; continue; }
				if (c[x[i][_1]][_1][1] and c[x[i][_2]][_2][1]) { --c[x[i][_1]][_1][1], --c[x[i][_2]][_2][1], ++ans; continue; }
			}
		}
		printf("%d\n", ans);
		C();
	}
	return 0;
}

