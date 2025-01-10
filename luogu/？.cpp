#include <bits/stdc++.h>
using namespace std;
int n;
struct area{
	int a,b;
}z[200005];
int atot,btot;
bool cmp(area x,area y) {
	
}
int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> z[i].a >> z[i].b;
	}
	sort(z+1,z+n+1,cmp);
	return 0;
}
