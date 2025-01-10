#include <bits/stdc++.h>
using namespace std;
int n,h;
struct node{
	int pre,nxt;
}c[104];
queue <int> q;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i].pre >> c[i].nxt;
		if (c[i].pre == 0 && h == 0) {
			h = i;
			continue; 
		}
		if (c[i].pre == 0) {
			q.push(i);
		}
	}
	int tot = h;
	while (!q.empty()) {
		while (c[tot].nxt != 0) {
			tot = c[tot].nxt;
		}
		c[tot].nxt = q.front();
		c[c[tot].nxt].pre = tot;
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		cout << c[i].pre << ' ' << c[i].nxt << endl;
	}
	return 0;
}
