#include <bits/stdc++.h>
using namespace std;
int n=1000,m;
struct edge{
	int u,v,w;
}e[100005];
int tot;
mt19937 r(time(0));
inline void add(int u,int v,int w) {
	e[++tot].u = u;
	e[tot].v = v;
	e[tot].w = w;
}
inline void print() {
	printf("%d %d\n",1000,100000);
	for (int i = 1; i <= 100000; i++) {
		printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
	}
}
int main () {
	freopen("hack.in","w",stdout);
	for (int i = 1; i < n; i++) {
		add(i,i+1,r()%100);
		add(i+1,i,r()%100);
	}
	for (int i = 2; i <= n; i++) {
		add(i,1,r()%7000+3000);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (tot >= 100000) {
				print();
				return 0;
			}
			add(i,j,r()%7000+3000);
			add(i,j,r()%7000+3000);
		}
	}
	return 0;
}