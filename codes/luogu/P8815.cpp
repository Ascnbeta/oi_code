#include <bits/stdc++.h>
using namespace std;
string s;
int n,ans1,ans2;
char ch;
stack<int> c;
bool solve(int l,int r) {
	int bg,ed;
	bool f1 = false;//bracket or no
	bool f_and = false,f_or = false;
	for (int i = l;i <= r; i++) {
		if (s[i] == '(') {
			f1 = true;
			c.push(i);
		}else if (s[i] == ')'){
			bg = c.top()+1;
			c.pop();
			if (c.size() == 0) {
				ed = i - 1;
				bool tmp = solve(bg,ed);
				s[bg-1] = (tmp?'1':'0');
				for (int j = bg; j <= ed+1; j++) {
					s[i] = ' ';
				}
			}
		}else if (s[i] == '&'){
			f_and = true;
		}else if (s[i] == '|') {
			f_or = true;
		}
	}
	int lpos = 0;//last sign
	if (!f_and) {
		for (int i = l;i <= r; i++) {
			if (s[i] == ' ') continue;
			if (s[i] == '|') {
				bool left = false,right = false;				
				for (int j = i - 1; j >= lpos + 1; j--) {
					if (s[j] == '1') {
						left = true;
						break;
					}else if (s[j] == '0') {
						left = false;
						break;
					}
				}
				if (left == true) {
					++ans2;
					for (int j = lpos+1; j <= i; j++) {
						s[j] = ' ';
					}
					lpos = i;
					s[lpos+1] = '1';
					
					for (int j = lpos+1; j <= r; j++) {
						if (s[j] == '|') break;
						s[j] = ' ';
					}
					continue;
				}
				for (int j = i + 1; i <= r; j++) {
					if (s[j] != '0' && s[j] != '1') {
						puts("ERR,line 53");
						exit(0);
					}
					if (s[j] == '1') {
						right = true;
						break;
					}else if (s[j] == '0') {
						left = true;
						break;
					}
				}
				if (right == true) {
					for (int j = lpos+1; j <= i; j++) {
						s[j] = ' ';
					}
					lpos = i;
					s[lpos+1] = '1';
					for (int j = lpos+1; j <= r; j++) {
						if (s[j] == '|') break;
						s[j] = ' ';
					}
					continue;
				}else{
					for (int j = lpos+1; j <= i; j++) {
						s[j] = ' ';
					}
					lpos = i;
					s[lpos+1] = '0';
					for (int j = lpos+1; j <= r; j++) {
						if (s[j] == '|') break;
						s[j] = ' ';
					}
					continue;
				}
			}
		}
		for (int i = r; i >= l; i--) {
			if (s[i] == '0') return false;
			else if (s[i] == '1') return true;
		}
	}
}
int main () {
	cin >> s;
	n = s.size();
	s = s + ' ';
	cout << solve(1,n) << '\n';
	cout << s << '\n';
	return 0;
}
