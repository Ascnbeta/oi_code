#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> s1 >> s2;
	if (s1 == "sick" && s2 == "sick") {
		puts("1");
		return 0;
	}else if(s1 == "sick") {
		puts("2");
		return 0;
	}else if(s2 == "sick") {
		puts("3");
		return 0;
	}else{
		puts("4");
	}
	return 0;
}