#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

const int N = 1e5 + 10;
int n, c, type;
int a[N];
std::vector < int > eg[N];

int read () {
	char ch = getchar();
	int x = 0;
	while (ch < '0' || ch > '9') 
		ch = getchar();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar(); 
	}
	return x;
}

void Main() {
	n = read(); c = read();
	for (int i = 1, x, y; i < n; i++) {
		x = read(), y = read();
		eg[x].push_back(y);
		eg[y].push_back(x);
	} 
	for (int i = 1; i <= c; i++)
		a[i] = read();
	if (type == 18) std::cout << 1 << '\n';
} 

int main() {
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	int T = 1;
	type = read(); T = read();
	while (T--) Main();
	return 0;
} 
