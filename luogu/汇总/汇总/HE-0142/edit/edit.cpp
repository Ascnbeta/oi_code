#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100005;

int t, n;
string s1, s2;
string s3, s4;
bool a[maxn], b[maxn];
bool f1[maxn], f2[maxn];
int sum1[maxn],sum2[maxn];
bool is[maxn];
int la1[maxn], la2[maxn], l1, l2;
int ne1[maxn], ne2[maxn], r1, r2;
int ans = 0;
bool is11, is10;
int ze1,ze2;


int main () {
	
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		cin >> s1 >> s2 >> s3 >> s4;
		is11 = true;
		is10 = true;
		
		if (s1[0] - '0') sum1[0] = 1;
		else sum1[0] = 0;
		if (s2[0] - '0') sum2[0] = 1;
		else sum2[0] = 0;
		a[0] = sum1[0];
		if (a[0]) is10 = false;
		else is11 = false;
		if(!a[0]) ze1 = 0;
		b[0] = sum2[0];
		if(!b[0]) ze2 = 0;
		for (int i = 1; i < n; i++) {
			a[i] = s1[i] - '0';
			if (a[i]) is10 = false;
			else is11 = false;
			if(!a[i]) ze1=i;
			b[i] = s2[i] - '0';
			if(!b[i]) ze2=i;
			if (a[i]) sum1[i] = sum1[i-1] + 1;
			else sum1[i] = sum1[i-1];
			if (b[i]) sum2[i] = sum2[i-1] + 1;
			else sum2[i] = sum2[i-1];
		}
		//cout << sum1[n-1] << ' ' << sum2[n-1] << endl;
//		for (int i = 0; i < n; i++) {
//			cout << sum2[i] << ' ';
//		}
//		cout << " end   "<< endl;
		if (is11) {
			//cout << "is11" << endl;
			cout << sum2[n-1] << endl;
			continue;
		}
		if (is10) {
			//cout << "is12" << endl;
			cout << n - sum2[n-1] << endl;
			continue;
		}
		
		if (n - sum1[n-1] == 1) {
			if (n - sum2[n-1] == 1) {
				if (ze1 == ze2) {
					cout << n << endl;
					continue;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (int(s3[i] - '0')) f1[i] = 1;
			else f1[i] = false;
			if (int(s4[i] - '0')) f2[i] = 1;
			else f2[i] = false;
		}
		
//		for (int i = 0; i < n; i++) cout << f1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << f2[i] << ' ';
//		cout << endl;
		
		if (!f1[1]) f1[0] = false;
		if (!f2[1]) f2[0] = false;
		if (!f1[n - 2]) f1[n-1] = false;
		if (!f2[n - 2]) f2[n-1] = false;
		for (int i = 1; i < n - 1; i++) {
			if ((!f1[i-1]) && (!f1[i+1])) f1[i] = false;
			if ((!f2[i-1]) && (!f2[i+1])) f2[i] = false;
		}
		//cout << ze1 << ' ' << ze2 << endl;
		if (n - sum1[n-1] == 1) {
			if (n - sum2[n-1] == 1) {
				if (!f1[ze1] && !f2[ze2]) cout << n - 2 <<endl;
				else cout << n << endl;
				continue;
			}
		}
//		
//		for (int i = 0; i < n; i++) cout << f1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << f2[i] << ' ';
//		cout << endl;
		
		l1 = -1;
		l2 = -1;
		for (int i = 1; i < n; i++) {
			if (!f1[i]) l1 = i;
			if (!f2[i]) l2 = i;
			if (f1[i] && (!f1[i+1])) la1[i] = l1 + 1;
			if (f2[i] && (!f2[i+1])) la2[i] = l2 + 1;
		}
		
		r1 = n-1;
		r2 = n-1;
		for (int i = n - 2; i >= 0; i--) {
			if (!f1[i]) r1 = i;
			if (!f2[i]) r2 = i;
			if (f1[i] && (!f1[i-1])) ne1[i] = l1 - 1;
			if (f2[i] && (!f2[i-1])) ne2[i] = l2 - 1;
		}
		
		for (int i = 0; i < n; i++) {
		//	cout << "i = " << i << ", is ";
			if ((!f1[i]) && (!f2[i])) {
				is[i] = (a[i] == b[i]);
				if(is[i]) ans++;
				//cout << 1 << endl;
			} else if (f1[i] ^ f2[i]) {
				if (a[i] == b[i]) {
					is[i] = true;
					ans++;
					f1[i] = false;
					f2[i] = false;
					//cout << 2 << endl;
					continue;
				}
				if (!f1[i]) {
				//	cout << 3 << endl;
					int l = la2[i], r = ne2[i];
					if (a[i]) {
						if (sum2[i] - sum2[l-1]) {
							is[i] = true;
							ans++;
							f2[i] = false;
							sum2[i-1]--;
						} else if (sum2[r] - sum2[i-1]) {
							is[i] = true;
							ans++;
							f2[i] = false;
							sum2[r]--;
						}
					} else {
						int len = i - l+1;
						if (sum2[i] - sum2[l-1] < len) {
							is[i] = true;
							ans++;
							f2[i] = false;
						} else if (sum2[r] - sum2[i-1] < r-i+1) {
							is[i] = true;
							ans++;
							f2[i] = false;
						}
					}	
				} else {
					//cout << 4 << endl;
					int l = la1[i], r = ne1[i];
					if (b[i]) {
						if (sum1[i] - sum1[l-1]) {
							is[i] = true;
							ans++;
							f1[i] = false;
							sum1[i-1]--;
						} else if (sum1[r] - sum1[i-1]) {
							is[i] = true;
							ans++;
							f1[i] = false;
							sum1[r]--;
						}
					} else {
						int len = i - l+1;
						if (sum1[i] - sum1[l-1] < len) {
							is[i] = true;
							ans++;
							f1[i] = false;
						} else if (sum1[r] - sum1[i-1] < r-i+1) {
							is[i] = true;
							ans++;
							f1[i] = false;
						}
					}
				}
				
			} 
		}
		int cha = 0, c1=0,c2=0;
		for (int i = 0; i < n; i++) {
			if (f1[i]) {
				c1=sum1[la1[i]]-sum1[i-1];
				c2=sum2[la2[i]]-sum2[i-1];
				cha = c1-c2;
				if (cha<0) cha = 0-cha;
				ans+= la1[i] - i + 1 - cha;
			}
		}
		
//		for (int i = 0; i < n; i++) cout << f1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << f2[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << la1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << la2[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << ne1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << ne2[i] << ' ';
//		cout << endl;
		
		cout << ans << endl;
	}
	
	return 0;
}
/*
1
6
011101
111010
111010
101101

1
5
11110
10111
11111
10101
*/
