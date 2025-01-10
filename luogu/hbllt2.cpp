#include <bits/stdc++.h>
using namespace std;
string s;
int nxt[2000004];
void gnxt() {
	int j = 0,k = -1;
	nxt[0] = -1;
	while (j < s.size()) {
		if (k == -1 || s[j] == s[k]) {
			j++;
			k++;
			nxt[j] = k;
		}else{
			k = nxt[k];
		}
	}
}
int main () {
	cin >> s;
	gnxt();
	cout << s;
	for (int i = nxt[s.size()]; i < s.size(); i++) {
		cout << s[i];
	}
	return 0;
}