#include <bits/stdc++.h>
using namespace std;
int read() {
	char ch;
	int x = 0;
	ch = getchar();
	while(ch < '0'|| ch > '9') {
        ch = getchar();
    }
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
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
int n,r,q,N;
struct node{
	int s,w;
	int n;
}a[200006],w[200006],l[200006];
inline bool cmp(node x,node y) {
	if (x.s == y.s) return x.n < y.n;
	return x.s > y.s;
}
void msort() {
	int i = 1, j = 1,p = 1;
	while(i <= N && j <= N) {
		if (cmp(l[i],w[j])) {
			a[p++] = l[i];
			++i;
		}else{
			a[p++] = w[j];
			++j;
		}
	}
	if (i <= N) {
		while(i <= N) {
			a[p++] = l[i];
			++i;
		}
	}
	if (j <= N) {
		while(j <= N) {
			a[p++] = w[j];
			++j;
		}
	}
}
	
int main () {
	N = read(),r = read(), q = read();
	n = N << 1;
	for (int i = 1; i <= n; i++) {
		a[i].s = read();
		a[i].n = i;
	}
	for (int i = 1; i <= n; i++) {
		a[i].w = read(); 
	}
	sort(a+1,a+n+1,cmp);
	while (r--) {
//		for (int i = 1; i <= n ;i++) {
//			cout << a[i].n << ' ';
//		}
//		cout << '\n';
		int p = 1;
		for (int i = 1; i <= n; i += 2) {
			if (a[i].w > a[i+1].w) {
				a[i].s += 1;
				w[p] = a[i];
				l[p++] = a[i+1];
			}else{
				a[i+1].s += 1;
				w[p] = a[i+1];
				l[p++] = a[i];
			}
		}
		msort();
		
	} 
	print(a[q].n);
	return 0;
}
