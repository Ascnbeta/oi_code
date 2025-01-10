#include <iostream>
using namespace std;
int t,n,ans;
char c;
string s1,s2,t1,t2;
int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++) {
		cin >> n;
		cin >> s1 >> s2 >> t1 >> t2;
		for(int j = 0;j < n;j++) {
			if(s1[j] == s2[j]) {
				ans++;
				continue;
			}
			else {
				if(t1[j] == 0 || t1[j+1] == 0) {
					continue;
				}
				else {
					c = s1[j];
					s1[j] = s1[j+1];
					s1[j+1] = c;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
