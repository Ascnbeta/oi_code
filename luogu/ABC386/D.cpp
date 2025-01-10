#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,y,c;
	char ch;
	bool operator < (const node &b) const{
		if (x == b.x) {
			return y < b.y;
		}
		return x < b.x;
	}
}op[200005];
int former = 0,l_ans = 0x3f3f3f3f;
int main () {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> op[i].x >> op[i].y >> op[i].ch;
		if (op[i].ch == 'B') {
			op[i].c = 1;
		}else{
			op[i].c = 0;
		}
	}
	l_ans = n;
	sort(op+1,op+m+1);
	for (int i = 1; i <= m; i++) {
		int l_b = 0,f_w = 0,j = i;
		for (; j <= m && op[j].x == op[i].x; j++) {
			if (op[j].c == 1) l_b = op[j].y;
			else if(op[j].c == 0 && f_w == 0) f_w = op[j].y;  
		}
		//cout << f_w << ' ' << l_b << '\n';
 		if (f_w <= l_b && l_b != 0 && f_w != 0) {
			puts("No");
			return 0;
		}
		if (f_w == 0) {
			if (l_b > l_ans) {
				puts("No");
				return 0;
			}
		}else{
			if (f_w-1 <= l_ans) {
				l_ans = f_w-1;
			}else if(l_ans < l_b) {
				puts("No");
				return 0;
			}
		}
		if (j > m) {
			break;
		}else{
			i = j - 1;
		}
	}
	puts("Yes");
	return 0;
}