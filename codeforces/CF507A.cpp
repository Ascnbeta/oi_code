#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> q;
int ans,tot;
struct object{
	int num,w; 
}c[104];
bool cmp(object a,object b) {
	if (a.w == b.w) return a.num < b.num;
	return a.w < b.w;
}
int main () {
	cin >> n >> k;
	for (int i = 1; i <= n ;i++) {
		cin >> c[i].w;
		c[i].num = i;
	}
	sort(c+1,c+n+1,cmp);
	for (int i = 1; i <= n; i++) {
		if (tot + c[i].w <= k) {
			++ans;
			q.push_back(c[i].num);
			tot += c[i].w;
		}else{
			break;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << ' ';
	}
	return 0;
}
