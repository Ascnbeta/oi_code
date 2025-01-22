#include <bits/stdc++.h>
using namespace std;
int a[7];
struct node{
	int s;
	string n;
};
bool operator <(node x,node y) {
	if (x.s == y.s) return x.n > y.n;
	return x.s < y.s;
}
priority_queue<node> q;
string f(int x) {
	if (x == 1) return "A";
	if (x == 2) return "B";
	if (x == 3) return "C";
	if (x == 4) return "D";
	if (x == 5) return "E";
}
int main () {
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	for (int i = 0; i <= 31; i++) {
		int t = i;
		int cnt = 1,sc = 0;
		string s = "";
		while (t) {
			if (t&1) {
				sc += a[cnt];
				s += f(cnt);
			}
			t >>= 1;
			++cnt;
		}
		q.push({sc,s});
	}
	while (!q.empty()) {
		cout << q.top().n << '\n';
		q.pop();
	}
	return 0;
}