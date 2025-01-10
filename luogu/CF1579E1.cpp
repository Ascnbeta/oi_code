#include <bits/stdc++.h>
using namespace std;
int T,n,a[200006];
deque<int> d;
int main () {
	cin >> T;
	while(T--){
		while(!d.empty()) d.pop_front();
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (i == 1) {
				d.push_front(x);
			}else{
				if (x <= d.front()) {
					d.push_front(x);
				}else{
					d.push_back(x);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << d.front() << ' ';
			d.pop_front();
		}
		cout << '\n';
	}
	return 0;
}
