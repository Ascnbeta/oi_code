#include <bits/stdc++.h>
using namespace std;
string s;
deque<char> q;
int main () {
	getline(cin,s);
	for (int i = 0; i < s.size(); i++) q.push_back(s[i]);
	
	while (!q.empty()) {
		if (!q.empty()) cout << q.front(),q.pop_front();
		else break;
		if (!q.empty()) cout << q.back(),q.pop_back();
		else break;
	}
	return 0;
}