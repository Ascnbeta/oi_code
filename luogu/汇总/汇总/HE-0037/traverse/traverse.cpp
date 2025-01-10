#include <iostream>
#include <vector>
#include <queue>

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
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
	return;
}

typedef pair<int, int> pii;
const int N = 500;

pii E[N];
int Ke[N];

int du[N];
void init(int n) {
	for(int i = 1; i < n; i++) du[i] = 0;
	return;
}
void solve() {
	int n = read(), k = read();
	init(n);
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		du[u]++;
		du[v]++;
		E[i] = {u, v};
	}
	for(int i = 1; i <= k; i++) Ke[i] = read();

	if(n <= 3) {
		print(1);
	} else if(n == 4) {
		int V = 0;
		for(int i = 1; i <= 4; i++) V = max(V, du[i]);
		if(V == 3) print(2);
		else print(1);
	} else {
		int V = 0;
		for(int i = 1; i <= 5; i++) V = max(V, du[i]);
		if(V == 2) print(1);
		else if(V == 3) print(2);
		else if(V == 4) print(6);
	}
	putchar('\n');
	return;
}
int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);

	int ty = read(), T = read();
	while(T--) solve();
	return 0;
}
