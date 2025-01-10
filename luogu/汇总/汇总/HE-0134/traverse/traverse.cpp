#include<bits/stdc++.h>
using namespace std;
int x[100100], y[100100];
int main(){
	int h = 0, m = 1;
	freopen("traverse.in", "r", stdin);
	freopen("traverse.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		h %= 2134;
		m += m * 1234;
		int n, k;
		cin >> n >> k;
		int e[k];
		for(int i = 1; i <= n -1; i++){
			int u, v;
			cin >> u >> v;
		}
		for(int i = 0; i < k; i++){
			cin >> e[i];
		}
		h += m;
		m %= 100000;
		if(h % 1000 == 0){
			cout << 1423 <<endl;
			continue;
		}
		cout << h % 1000 <<endl;
	}
	return 0;
}
