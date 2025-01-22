#include <bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],cnt[100005],ans[100005];
void msort(int l,int r) {
	int mid = (l+r)/2;
	if (l == r) return;
	msort(l,mid);
	msort(mid+1,r);
	for (int i = l; i <= r; i++) {
		b[i] = a[i];
	}
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (b[i] > b[j]) {
			a[p++] = b[j];
			++j;
			cnt[p] += mid - i + 1;
			cnt[p] += ans[j];
		}else{
			a[p++] = b[i];
			++i;
			cnt[p] += ans[i];
		}
	}
	while (i <= mid) {
		a[p++] = b[i];
		++i;
	}
	while (j <= r) {
		a[p++] = b[j];
		++j;
	}
	for (int i = l; i <= r; i++) {
		ans[i] = cnt[i];
		cnt[i] = 0;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	msort(1,n);
	int anss = -1;
	for (int i = 1; i <= n; i++) anss = max(ans[i],anss);
	cout << anss + 1 << endl;
	return 0;
}
