#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m,T;
string str1,str2,st1,st2;
signed main () {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	while (T -- && cin >> n >> str1 >> str2 >> st1 >> st2) {
		for(int i=0; i<n; ++i) {
			if(!(st1[i-1]-'0')&&!(st1[i+1]-'0')&&st1[i]=='1') st1[i] = '0';
			if(!(st2[i-1]-'0')&&!(st2[i+1]-'0')&&st2[i]=='1') st2[i] = '0';
		}
		if(st1[1]=='0'&&st1[0]=='1') st1[0] = '0';
		if(st1[n-2]=='0'&&st1[n-1]=='1') st1[n-1] = '0';
		if(st2[1]=='0'&&st2[0]=='1') st2[0] = '0';
		if(st2[n-2]=='0'&&st2[n-1]=='1') st2[n-1] = '0';
		int bi = 0,li = 0,rei = 0,rej = 0,ans = 0;
		for(int i=0; i<n; ++i) {
//			cout << "\ni = " << i << ',';
			if(str1[i] == str2[i]) ++ans;
			else if(st1[i] == st2[i] && st1[i] == '0') {
				if(str1[i] == str2[i]) ++ ans;
			} else {
				if(st1[i] == '1' && st2[i] == '0') {
					bi = i;
					while (st1[bi] == '1' && bi < n) {
//						cout << str1[bi] << ' ' << str2[i] << ' ';
//						cout << bi << ' ' << i << '\n';
						if(str1[bi] == str2[i]) {
							++ ans;
							swap(str1[bi],str1[i]);
							break;
						}
						++ bi;
					}
				} else if(st1[i] == '1' && st2[i] == '0') {
					li = i;
					while (st2[li] == '1' && li < n) {
						if(str2[li] == str1[i]) {
							++ ans;
							swap(str2[i],str2[li]);
						}
						++ li;
					}
				} else {
					bi = li = i;
					while (st1[bi] == '1' && bi < n) ++ bi;
					while (st2[li] == '1' && li < n) ++ li;
					if(bi < li) {
						li = i;
						while (st2[li] == '1' && li < n) {
							if(str2[li] == str1[i]) {
								++ ans;
								swap(str2[i],str2[li]);
							}
							++ li;
						}
					} else {
						bi = i;
						while (st1[bi] == '1' && bi < n) {
//							cout << str1[bi] << ' ' << str2[i] << ' ';
//							cout << bi << ' ' << i << '\n';
							if(str1[bi] == str2[i]) {
								++ ans;
								swap(str1[bi],str1[i]);
								break;
							}
							++ bi;
						}
					}
				}
			}
//			cout << str1 << '\n' << str2 << '\n';
//			cout << "ans = " << ans << '\n';
		}
		cout << ans << '\n';
	}
}
