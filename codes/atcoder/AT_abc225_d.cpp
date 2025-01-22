#include <bits/stdc++.h>
using namespace std; 
int n,q,ans;
struct node {
	int nxt;
}a[100005];
int head[100005];
vector<int> v;
int find(int x) {
	if (x == head[x]) {
		return x; 
	};
	return find(head[x]);
}
int main () {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		head[i] = i;
	}	
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x,y;
			cin >> x >> y;
			int tmp = find(x);
			a[x].nxt = y;
			head[y] = x;	
		}
		if (op == 2) {
			int x,y;
			cin >> x >> y;
			int tmp = find(x);
			a[x].nxt = 0;
			head[y] = y;
		}
		if (op == 3) {
			int x;
			cin >> x;
			int tmp = find(x);
			ans = 0;
			v.clear();
			do{
				v.push_back(tmp);
				tmp = a[tmp].nxt;
			}while(tmp);
			cout << v.size() << ' ';
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
			cout << '\n';
		} 
	}
	return 0;
}
