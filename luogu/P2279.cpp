#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int to,nxt;
}e[2003];
int head[2003],tot;
void add(int u,int v) {
	e[++tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
}
int min(int a,int b,int c,int d,int e) {
	return min(a,min(b,min(c,min(d,e))));
}
int min(int a,int b,int c,int d) {
	return min(a,min(b,min(c,d)));
}
int min(int a,int b,int c) {
	return min(a,min(b,c));
}
int f[2004][5];//0 -> self 1 -> son 2 -> grandson 3 -> father 4 -> grandfather
void dfs(int u,int fa) {
	f[u][0] = 1;
	f[u][4] = 0;
	f[u][3] = 0;
	int sum1 = 0,sum2 = 0;
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		dfs(v,u);
		f[u][0] += min(f[v][0],f[v][1],f[v][2],f[v][3],f[v][4]);
		sum1 += min(f[v][0],f[v][1],f[v][2],f[v][4]);
		sum2 += min(f[v][1],f[v][2]);
		f[u][3] += min(f[v][0],f[v][1],f[v][2],f[v][4]);
		f[u][4] += min(f[v][0],f[v][1],f[v][2]); 
	}
	for (int i = head[u];i;i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa) continue;
		int tmp1 = min(f[v][1],f[v][0],f[v][2],f[v][4]);
		if (f[v][0] == tmp1) f[u][1] = min(sum1,f[u][1]);
		else f[u][1] = min(f[u][1],sum1+f[v][0]-tmp1);
		int tmp2 = min(f[v][1],f[v][2]);
		if (f[v][1] == tmp2) f[u][2] = min(sum2,f[u][2]);
		else f[u][2] = min(f[u][2],sum2+f[v][1]-tmp2);
	}
}
int main () {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		add(i,x);
		add(x,i);
	}
	memset(f,0x0f,sizeof(f));
	dfs(1,0);
	cout << min(f[1][1],f[1][2],f[1][0]) << '\n';
	return 0;
}