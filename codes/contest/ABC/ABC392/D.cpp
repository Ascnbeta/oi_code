#include <bits/stdc++.h>
using namespace std;
const double t1 = 1.0;
int n,k[103];
double ans = 0;
vector<int> a[103];
int b1[100003],b2[100003];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(b1,0,sizeof(b1));
		for (int j = 0; j < a[i].size(); j++) {
			++b1[a[i][j]];
		}
		for (int j = 1; j < i; j++) {
			double tmp = 0;
			for (int k = 0; k < a[j].size(); k++) {
				if (b1[a[j][k]] != 0) tmp += t1*b1[a[j][k]]/a[i].size()*t1/a[j].size();
			}
			ans = max(ans,tmp);
			//cout << i << ' ' << j << ' ' << tmp << '\n';
		}
	}
	printf("%.13f\n",ans);
	return 0;
}