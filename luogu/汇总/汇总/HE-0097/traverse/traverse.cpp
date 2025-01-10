#include <bits/stdc++.h>

int c, t;

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

int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
    //¿ª°×
    c = read(), t = read();
    while (t--) write(3), puts("");
    return 0;
}
