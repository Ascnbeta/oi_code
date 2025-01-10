#include<bits/stdc++.h>
using namespace std;
#define rd read()
#define gc getchar()
#define dg(ch) isdigit(ch)
#define _mul(x) ((x<<3)+(x<<1))
#define ll long long
#define il inline
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ROF(i,j,k) for(int i=j;i>=k;i--)
il int read(){int x=0,f=1;char ch=gc;while(!dg(ch)){if(ch=='-')f=-1;ch=gc;}while(dg(ch))x=_mul(x)+(ch^48),ch=gc;return x*f;}
const int N=1e6+10,mod=1e9+7;
int MOD(int x){return x>=mod?x-mod:x;}
int T,n,m,v,a[N],b[N],p[N],t[N];

namespace solve1{
	int ans=0;
	void DFS(int x){
		if(x>=n){
			bool flag=true;
			FOR(i,1,n) t[i]=p[i];
			FOR(i,1,n-1){
				if(t[i]==a[i]){
					if(t[i+1]&&t[i+1]!=b[i]){flag=false;break;}
					t[i+1]=b[i];
				}
			}
			if(flag) ans++;
			return;
		}
		FOR(i,1,v){b[x]=i,DFS(x+1);}
	}
	void dfs(int x){
		if(x>=n){
			DFS(1);
			return;
		}
		FOR(i,1,v){a[x]=i,dfs(x+1);}
	}
	int main(){
		FOR(i,1,m){
			int x=rd,y=rd;
			if(p[x]&&p[x]!=y){puts("0");return 0;}
			p[x]=y;
		}
		dfs(1),printf("%d\n",ans);
		return 0;
	}
}
using namespace solve1;

int qpow(int a,int b){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod,b>>=1;}return res;}
void solve(){
	memset(p,0,sizeof(p));
	n=rd,m=rd,v=rd,ans=0;
	if(v<=2) solve1::main();
	else{
		ans=1;bool flag=true;
		FOR(i,1,m){
			int x=rd,y=rd;if(x>=1e6) continue;
			if(p[x]&&p[x]!=y) flag=false;
			p[x]=y;
		}
		if(m==1){
			int tt=2*(n-1);ans=qpow(v,tt);
			printf("%d\n",ans);
			return;
		}
		if(!flag){puts("0");return;}
		FOR(i,1,n-1){
			if(p[i]&&p[i+1]) ans=1ll*ans*(1ll*v*(v-1)%mod+1)%mod;
			else ans=1ll*ans*v%mod*v%mod;
		}
		printf("%d\n",ans);
	}
}

int main(){
	
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	T=rd;
	while(T--) solve();
	return 0;
}
