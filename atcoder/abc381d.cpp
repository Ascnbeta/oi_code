#include <bits/stdc++.h>
// #define int long long

using namespace std;
int n;
int a[200005],num[200005];
struct node{
	int p,n;
};
vector<node> b;
vector<node> cnt(200009);
#ifdef int
signed main () {
	
	return 0;
}
#else
int main() {
	cin >> n;
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i-1]&&i!=1) {
			b.push_back(node{tmp,a[i-1]});
			tmp = 1;
		}else if (i!=1){
			tmp++;
		}
	}
	b.push_back(node{tmp,a[n]});
	// for (int i = 0; i < b.size(); i++) {
	// 	cout << b[i].n << ' ';
	// }
	for (int i = 0; i < b.size(); i++) {
		cnt.clear();
		
	}
	return 0;
}
#endif

