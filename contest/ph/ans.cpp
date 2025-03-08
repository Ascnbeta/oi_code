#include <bits/stdc++.h>
using namespace std;
int c;
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> c;
	if (c == 5) puts("NARROW-MINDED");
	if (c == 2) puts("VOID");
	if (c == 1) puts("POLICE");
	if (c == 4) puts("POINTOFVIEW");
	return 0;
}