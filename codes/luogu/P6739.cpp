#include <bits/stdc++.h>
using namespace std;
int n,ans;
string t;
string s1,s2,s3;
int main () {
#ifdef LOCAL
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin >> n >> t;
	t = ' ' + t;
	if (n % 2 == 0) {
		puts("NOT POSSIBLE");
		return 0;
	}
	int mid = n / 2 + 1;
	bool f = false;
	if (t[1] == t[mid+1]) {
		for (int i = 1,j = mid + 1; i < mid; i++,j++) {
			if (t[i] != t[j]) {
				f = true;
				break;
			}
		}
		if (!f) {
			++ans;
			s1 = t.substr(1,mid-1);
		} 
	}
	//cout << s1 << '\n';
	f = false;
	int d = 0;
	for (int i = 1,j = mid + 1; i <= mid && j <= n;) {
		if (t[i] != t[j] && d == 0) {
			++i;
			++d;
			continue;
		}else if(t[i] != t[j] && d == 1) {
			f = true;
			break;
		}else if(t[i] == t[j]) {
			++i,++j;
		}
	}
	if (!f) {
		++ans;
		s2 = t.substr(mid+1,n/2);
		if (s2 == s1) --ans,s2 = "";
	}
	f = false;
	d = 0;
	for (int i = 1,j = mid; i < mid && j <= n;) {
		if (t[i] != t[j] && d == 0) {
			++j;
			++d;
			continue;
		}else if(t[i] != t[j] && d == 1) {
			f = true;
			break;
		}else if(t[i] == t[j]) {
			++i,++j;
		}
	}
	if (!f) {
		++ans;
		s3 = t.substr(1,n/2);
		if (s3 == s1 || s3 == s2) --ans,s3 = "";
	}
	if (ans == 0) {
		puts("NOT POSSIBLE");
	}else if (ans > 1) {
		puts("NOT UNIQUE");
	}else{
		if (s1 != "") cout << s1 << '\n';
		else if (s2 != "") cout << s2 << '\n';
		else if (s3 != "") cout << s3 << '\n';
	}
	return 0;
}