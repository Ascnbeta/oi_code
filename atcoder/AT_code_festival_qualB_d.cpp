#include <bits/stdc++.h>
using namespace std;
int n;
int h[100004];
stack<int> st;
int ans[100004];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		while (!st.empty()&&h[st.top()]<h[i]) {
			ans[st.top()] += i-st.top()-1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		ans[st.top()] += n-st.top();
		st.pop();
	}
	for (int i = n; i >= 1; i--) {
		while (!st.empty()&&h[st.top()]<h[i]) {
			ans[st.top()] += st.top()-i-1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		ans[st.top()] += st.top()-1	;
		st.pop();
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
}