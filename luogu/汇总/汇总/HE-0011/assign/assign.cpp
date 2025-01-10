#include<bits/stdc++.h>
using namespace std;

#define ar(x) array<int,x>
const int N=1e5+100,MOD=1e9+7;
inline void mod(int &x){ if(x>=MOD) x-=MOD; if(x<0) x+=MOD; }
inline int qm(int x,int y=MOD-2){ int res=1; for(;y;y>>=1,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD; return res; }
#define gc getchar()
#define rd read()
inline int read(){
	int x=0,f=0; char c=gc;
	for(;c<'0'||c>'9';c=gc) f|=(c=='-');
	for(;c>='0'&&c<='9';c=gc) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

int n,m,v,v2,ans=0; ar(2) a[N];
inline int calc(int j,int i){ if(i==j) return 1; return (qm(v2,i-j)-1ll*qm(v,i-j-1)*(v-1)%MOD+MOD)%MOD; }

void solve(){
	n=rd,m=rd,v=rd,v2=1ll*v*v%MOD;
	for(int i=1,x,y;i<=m;++i) x=rd,y=rd,a[i]={x,y};
	sort(a+1,a+m+1);
	
	ans=qm(v2,a[1][0]-1);
	for(int i=2;i<=m;++i){
		if(a[i-1][0]==a[i][0]){
			if(a[i-1][1]!=a[i][1]) return printf("0\n"),void();
			continue;
		}
		ans=1ll*ans*calc(a[i-1][0],a[i][0])%MOD;
	}
	ans=1ll*ans*qm(v2,n-a[m][0])%MOD;
	
	printf("%d\n", ans);
}

int main(){

	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	int T=rd;
	while(T--) solve();
	
	return 0;
}
/*
3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2

*/

