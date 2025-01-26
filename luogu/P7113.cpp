#include <bits/stdc++.h>
#define int __int128
using namespace std;
inline int read() {
	int x=0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
void print(int x) {
	if (x > 9) {
		print (x/10);
	}
	putchar(x%10+'0');
}
int n,m;
struct edge{
	int nxt,to;
}e[200005];
int head[100005],ex[100005],tot = 1;
bool ext[100005];
void add(int u,int v) {
	e[tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot++;
}
struct fs{
	int z,m;
	void ql() {
		z = 0,m = 0;
	}
}ans[100005],a[100005];
int gcd(int x,int y) {
	while (y != 0) {
		int temp = x % y;
		x = y,y = temp;
	}
	return x;
}
fs operator + (fs &x,fs &y) {
	if (x.m == 0) return y;
	fs p = x,q = y,ret;
	if (x.m == y.m) {
		ret.m = x.m;
		ret.z = x.z + y.z;
	}else{
		int g = gcd(x.m,y.m);
		ret.m = x.m * y.m / g;
		ret.z = x.z * (ret.m / x.m) + y.z * (ret.m / y.m);
	}
	int g1 = gcd(ret.z,ret.m);
	if (g1 != 1) {
		ret.z /= g1;
		ret.m /= g1;
	}
	return ret;
}
void dfs(int x) {
	if (ext[x]) {
		ans[x] = ans[x] + a[x];
		a[x].m = 1,a[x].z = 0;
		return;
	}
	fs y = a[x];
	y.m *= ex[x];
	for (int i = head[x];i;i = e[i].nxt) {
		int tmp = e[i].to;
		a[tmp] = a[tmp] + y;
		dfs(tmp);
	}
	a[x].m = 1,a[x].z = 0;
}
signed main () {
	n = read(),m = read();
//	print(n);
//	printf("\n");
	for (int i = 1; i <= n ; i++){
		ans[i].ql();
		int t;
		t = read();
		ex[i] = t;
		if (t == 0) {
			ext[i] = true;
		}
		for (int j = 1; j <= t; j++) {
			int x = read();
			add(i,x);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n ; j++) {
			a[j].ql();
		}
		a[i].z = a[i].m = 1;
		dfs(i);
	}
	for (int i = 1; i <= n ; i++) {
		if (ext[i]) {
			print(ans[i].z);
			printf(" ");
			print(ans[i].m);
			printf("\n");
		}
	}
	return 0;
}