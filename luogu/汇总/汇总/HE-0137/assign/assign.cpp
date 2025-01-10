#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+10;
int T;
int n;
int m;
int v;
int c[mx+10],d[mx+10];
map<int,int> s;
signed main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		bool k = 0 ;
		for(int i=1;i<=m;i++){
			cin >> c[i] >> d[i];
			if(s[c[i]]){
				k=1;
				break;
			}
			s[c[i]]=d[i];
		} 
		if(k) {
			cout << 0 << '\n';
			continue;
		}
		
	}
	return 0;
}

