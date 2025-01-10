#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e7+1;
int T,n,m,v;
int c,d;
int x[N];
long long ans;
bool b,h;

int mian(){
//	freopen("assign.in","r",stdin);
//	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T --){
		memset(x,0,sizeof(x));
		ans = 0;
		cin>>n>>m>>v;
		for(int j = 1;j <= m;j ++){
			cin>>c>>d;
			if(c != j) h = true;
			if(x[c] == 0) x[c] = d;
			else b = true;
		}
		if(m == n && h == false){
			if(b == true){
				cout<<0<<"\n";
				continue;
			}
			else{
				cout<<((v*(v-1)+1)%MOD)*(n-1)<<"\n";
			}
		}
		if(b == true){
			cout<<0<<"\n";
			continue;
		}
		for(int i = 1;i < n;i ++){
			//if(b[i] == true) continue;
			if(x[i] == 0 && x[i+1] == 0) ans += v*v%MOD;
			if(x[i] != 0 && x[i+1] == 0) ans += v*v%MOD;
			if(x[i] != 0 && x[i+1] != 0) ans += (v*(v-1)+1)%MOD;
		}
		cout<<ans%MOD<<"\n";
	}
	return 0;
}
