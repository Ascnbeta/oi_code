#include <bits/stdc++.h>
using namespace std;

int c,T;
int n,k;
vector <int> tu[114514];
int du[114514];

int main ( ) {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin >> c >> T ;
	while (T--) {
		cin >> n >> k ;
		for (int i = 1;i <= n - 1;++i) {
			int x,y;cin >> x >> y ;
			tu[x].push_back(y);
			tu[y].push_back(x);
			++du[x];
			++du[y];
		}
		cout << n / 2 << '\n' ;
	}
}
/*
1 2 3 4 5 6
1 2 3
*/
