#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+10;
int n;
int a[maxn],ans[maxn];
stack<int> st;
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (!st.empty()&&a[st.top()]<a[i]) {
			ans[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}