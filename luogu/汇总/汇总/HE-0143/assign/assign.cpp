#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int MAXN=1e6+10;
int T,n,m,v,f[MAXN][2];
int kep[MAXN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(kep,0,sizeof(kep));
		memset(f,0,sizeof(f));
		cin>>n>>m>>v;
		int c,d;
		bool wrong=false;
		for(int i=1; i<=m; i++) {
			cin>>c>>d;
			if(kep[c]!=0){
				wrong=true;
			}
			kep[c]=d;
		}
		if(wrong){
			cout<<0<<endl;
			continue;
		}
		f[0][0]=1;
		for(int i=1; i<n; i++) {
			if(kep[i]==0&&kep[i+1]==0) {
				f[i][0]=((long long)((f[i-1][0]*v)%MOD*v)%MOD+(long long)((f[i-1][1]*(v-1))%MOD*v))%MOD;
				f[i][1]=(long long)(f[i-1][0]*v)%MOD+(long long)(f[i-1][1]*v)%MOD;
			} else if(kep[i]==0&&kep[i+1]!=0) {
				f[i][0]=((long long)((f[i-1][0]*v)%MOD*v)%MOD+(long long)((f[i-1][1]*(v-1))%MOD))%MOD;
				f[i][1]=(long long)(f[i-1][0])%MOD+(long long)(f[i-1][1])%MOD;
			} else if(kep[i]!=0&&kep[i+1]==0) {
				f[i][0]=((long long)((f[i-1][0]*(v-1))%MOD*v)%MOD+(long long)((f[i-1][1]*(v-1))%MOD)*v)%MOD;
				f[i][1]=(long long)(f[i-1][0]*v)%MOD+(long long)(f[i-1][1]*v)%MOD;
			} else if(kep[i]!=0&&kep[i+1]!=0) {
				f[i][0]=((long long)((f[i-1][0]*(v-1))%MOD*v)%MOD+(long long)((f[i-1][1]*(v-1))%MOD))%MOD;
				f[i][1]=(long long)(f[i-1][0])%MOD+(long long)(f[i-1][1])%MOD;
			}
		}
		cout<<(long long)(f[n-1][0]+f[n-1][1])%MOD<<endl;
	}
	return 0;
}
