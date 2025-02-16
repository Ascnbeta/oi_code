<<<<<<< 
#include <bits/stdc++.h>
using namespace std;
int n,p[300003],q[300004];
int src[300005];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> q[i];
	for (int i = 1; i <= n; i++) {
		src[q[i]] = q[p[i]];
	}
	for (int i = 1; i <= n; i++) cout << src[i] << ' ';
	cout << '\n';
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int n,p[300003],q[300004];
int src[300005];
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> q[i];
	for (int i = 1; i <= n; i++) {
		src[q[i]] = q[p[i]];
	}
	for (int i = 1; i <= n; i++) cout << src[i] << ' ';
	cout << '\n';
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}