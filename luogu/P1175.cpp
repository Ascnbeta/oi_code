#include <bits/stdc++.h>
using namespace std;
string s,s1;
stack<char>st;
int main () {
	cin >> s;
	int cnt = 0;
	for (int i = 0 ; i < st.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[cnt++] = s[i] - '0';
		}
		if (s[i] == '+' || s[i] == '-') {
			while(st.top() == '*' && st.top() == '/') {
				s1[cnt++] = st.pop();
				st.pop();
			}
		}
	}
	return 0;
}