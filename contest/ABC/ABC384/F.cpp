#include <bits/stdc++.h>
#define int long long;
using namespace std;
int n;
int a[200005];
int f[10];
struct node{
	int num;
	int p,ot;
}b[200005]
void div(int p) {
	int x = a[p],cnt = 0;
	for (int i = 5; i >= 1; i--) {
		if (x % f[i] == 0) {
			x /= f[i];
			switch(i) {
			case 1:{
				cnt += 1;
				break;
			}
			case 2:{
				cnt += 2;
				break;
			}
			case 3:{
				cnt += 4;
				break;
			} 
			case 4:{
				cnt += 8;
				break;
			}
			case 5:{
				cnt += 16;
				break;
			}
			}
		}
	}
	b[p].num = a[p],b[p].p = cnt,b[p].ot = x;
}
void init() {
	int base = 2;
	f[1] = base;
	for (int i = 2; i <= 5; i++) {
		f[i] = base * base;
		base *= base;
	}
}
int main () {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],div(i);
	for (int i = 1; i <= n; i++) {
		
	}
	return 0;
}