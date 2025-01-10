#include <bits/stdc++.h>

const int N = 1e5 + 5;

int t, n;
bool s1[N], s2[N], q1[N], q2[N];
char ch;
struct Seg {
	int l, r;
	int cnt1, cnt0;
} vec1[N], vec2[N];
int c1, c2;

int read() {
	int res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

void work() {
	n = read();
//	int qwq = 0, qaq = 0;
	for (int i = 1; i <= n; ++i) {
		ch = getchar();
		while (ch != '1' && ch != '0') ch = getchar();
		s1[i] = ch - '0';
//		qwq += s1[i];
	}
	for (int i = 1; i <= n; ++i) {
		ch = getchar();
		while (ch != '1' && ch != '0') ch = getchar();
		s2[i] = ch - '0';
//		qaq += s2[i];
	}
//	write(qwq), putchar(' '), write(qaq), puts("");
	for (int i = 1; i <= n; ++i) {
		ch = getchar();
		while (ch != '1' && ch != '0') ch = getchar();
		q1[i] = ch - '0';
	}
	for (int i = 1; i <= n; ++i) {
		ch = getchar();
		while (ch != '1' && ch != '0') ch = getchar();
		q2[i] = ch - '0';
	}
//	puts("a");
	c1 = 0, c2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (!q1[i]) vec1[++c1] = {i, i, s1[i], 0};
		else { 
			if (i - 1 < 1 || !q1[i - 1]) vec1[++c1] = {i, 0, 0, 0};
			vec1[c1].cnt1 += s1[i];
			if (i + 1 > n || !q1[i + 1]) vec1[c1].r = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!q2[i]) vec2 [++c2] = {i, i, s2[i], 0};
		else {
			if (i - 1 < 1 || !q2[i - 1]) vec2[++c2] = {i, 0, 0, 0};
			vec2[c2].cnt1 += s2[i];
			if (i + 1 > n || !q2[i + 1]) vec2[c2].r = i;
		}
	}
//	puts("b");
	for (int i = 1; i <= c1; ++i)
		vec1[i].cnt0 = vec1[i].r - vec1[i].l + 1 - vec1[i].cnt1;
	for (int i = 1; i <= c2; ++i)
		vec2[i].cnt0 = vec2[i].r - vec2[i].l + 1 - vec2[i].cnt1;
//	for (int i = 1; i <= c1; ++i)
//		write(vec1[i].l), putchar(' '), write(vec1[i].r), putchar(' '), write(vec1[i].cnt1), putchar(' '), write(vec1[i].cnt0), puts("");
//	for (int i = 1; i <= c2; ++i)
//		write(vec2[i].l), putchar(' '), write(vec2[i].r), putchar(' '), write(vec2[i].cnt1), putchar(' '), write(vec2[i].cnt0), puts("");
//	int qwq = 0, qaq = 0;
//	for (int i = 1; i <= c1; ++i)
//		qwq += vec1[i].cnt1, qaq += vec1[i].cnt0;
//	write(qwq), putchar(' '), write(qaq), puts("");
//	qwq = 0, qaq = 0;
//	for (int i = 1; i <= c2; ++i)
//		qwq += vec2[i].cnt1, qaq += vec2[i].cnt0;
//	write(qwq), putchar(' '), write(qaq), puts("");
//	puts("c");
//	for (auto ele : vec1)
//		write(ele.l), putchar(' '), write(ele.r), putchar(' '), write(ele.cnt1), putchar(' '), write(ele.cnt0), puts("");
//	for (auto ele : vec2)
//		write(ele.l), putchar(' '), write(ele.r), putchar(' '), write(ele.cnt1), putchar(' '), write(ele.cnt0), puts("");
	int ans = 0, x, y;
	for (int i = 1, j = 1; i <= c1; ) {
//		if (vec1[i].r - vec1[i].l + 1 != vec1[i].cnt0 + vec1[i].cnt1 || vec2[j].r - vec2[j].l + 1 != vec2[j].cnt0 + vec2[j].cnt1) {
//			write(vec1[i].l), putchar(' '), write(vec1[i].r), putchar(' '), write(vec1[i].cnt1), putchar(' '), write(vec1[i].cnt0), puts("");
//			write(i), putchar(' '), write(j), putchar(' '), puts("wtf?!");
//		}
		x = std::min(vec1[i].cnt1, vec2[j].cnt1), y = std::min(vec1[i].cnt0, vec2[j].cnt0);
		if (vec1[i].r == vec2[j].r) {
			ans += x + y;
			++i, ++j;
		} else if (vec1[i].r < vec2[j].r) {
			if (vec2[j].cnt0 >= vec1[i].cnt0 && vec2[j].cnt1 >= vec1[i].cnt1) {
				vec2[j].cnt0 -= vec1[i].cnt0;
				vec2[j].cnt1 -= vec1[i].cnt1;
			} else {
				if (vec2[j].cnt1 < vec1[i].cnt1) {
					vec2[j].cnt0 -= vec1[i].r - vec1[i].l + 1 - vec2[j].cnt1;
					vec2[j].cnt1 = 0;
				} else if (vec2[j].cnt0 < vec1[i].cnt0) {
					vec2[j].cnt1 -= vec1[i].r - vec1[i].l + 1 - vec2[j].cnt0;
					vec2[j].cnt0 = 0;
				}
			}
			vec2[j].l = vec1[i].r + 1;
			ans += x + y;
			++i;
		} else if (vec1[i].r > vec2[j].r) {
			if (vec1[i].cnt0 >= vec2[j].cnt0 && vec1[i].cnt1 >= vec2[j].cnt1) {
				vec1[i].cnt0 -= vec2[j].cnt0;
				vec1[i].cnt1 -= vec2[j].cnt1;
			} else {
				if (vec1[i].cnt1 < vec2[j].cnt1) {
					vec1[i].cnt0 -= vec2[j].r - vec2[j].l + 1 - vec1[i].cnt1;
					vec1[i].cnt1 = 0;
				} else if (vec1[i].cnt0 < vec2[j].cnt0) {
					vec1[i].cnt1 -= vec2[j].r - vec2[j].l + 1 - vec1[i].cnt0;
					vec1[i].cnt0 = 0;
				}
			}
			vec1[i].l = vec2[j].r + 1;
			ans += x + y;
			++j;
		}
	}
	write(ans), puts("");
}

int main() {
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	t = read();
	while (t--) work();
	return 0;
}
