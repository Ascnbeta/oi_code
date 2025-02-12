#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+6;
int n,m;
double sum,avg;
int a[maxn];
signed main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		if (avg > a[i]) {
			avg = sum / i;
		}else{
			sum += m;
			avg = sum / i;
		}
	}
	printf("%.2f",avg);
	sum = avg = 0;
	sort(a+1,a+n+1,greater<int>());
	for (int i = 1; i <= n; i++) {
		if (avg > a[i]) {
			avg = sum / i;
		}else{
			sum += m;
			avg = sum / i;
		}
	}
	printf(" %.2f",avg);
	return 0;
}