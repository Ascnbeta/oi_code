#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
const int mod=1e9+7;
int T;
int n,m,c;
map<int,int>a;
int b[N];
int ans;

void Add(int &x,int y) { x=(x+y)%mod; }

void Del(int &x,int y) { x=(x-y+mod)%mod; }

int Fastpow(int x,int k){
	int ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans; 
}

void Solve(){
	scanf("%lld%lld%lld",&n,&m,&c);
	int x,y,F=1,tot=0;
	a.clear();
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		if(a[x] && a[x]!=y) F=0;
		a[x]=y;
		b[++tot]=x;
	}
	if(!F){
		printf("0\n");
		return ;
	}
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	ans=Fastpow(c,2*(n-1));
	int pre=Fastpow(c,2*(b[1]-1));
	int g=0;
	for(int i=1;i<tot;i++){
		int len=b[i+1]-b[i]+1;
		int qwq=Fastpow(c,len-2)*(c-1)%mod;
		Add(g,pre*qwq%mod*Fastpow(c,2*(n-b[i+1]))%mod);
		int QwQ=Fastpow(c,2*(len-1));
		Del(QwQ,qwq);
		pre=pre*QwQ%mod;
	}
	Del(ans,g);
	printf("%lld\n",ans);
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%lld",&T);
	while(T--) Solve();	
	return 0;
}
