#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10,mod=1e9+7;
struct a1{
	int nex,to,i;
}x[N];int head[N],p;
void add(int a,int b,int i){
	x[++p].nex=head[a];
	x[p].to=b;x[p].i=i;
	head[a]=p;
}
struct a2{int a,b;}z[N];
LL siz[N],s[N],v[N],u[N],ans=1;
void dfs(int a,int fa){
	siz[a]=0;LL k=0;
	for(int q=head[a];q;q=x[q].nex){
		int o=x[q].to;
		siz[a]++;
		if(o!=fa)dfs(o,a);
		if(v[x[q].i]==1)k++;
	}
	ans=ans*s[siz[a]-1]%mod;
}
void dfs3(int a,int fa){
	siz[a]=0;LL k=0;
	for(int q=head[a];q;q=x[q].nex){
		int o=x[q].to;
		siz[a]++;
		if(o!=fa)dfs3(o,a);
		if(v[x[q].i]==1)k++;
	}
	if(k==2)ans=ans*((s[siz[a]-1]*2%mod-s[siz[a]-2]+mod)%mod)%mod;
	else ans=ans*s[siz[a]-1]%mod;
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	int c,T;cin>>c>>T;
	s[0]=1;for(int q=1;q<=2e5;q++)s[q]=s[q-1]*q%mod;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int q=1;q<=n;q++)head[q]=0;p=0;
		for(int q=1;q<n;q++){
			int a,b;scanf("%d%d",&a,&b);
			add(a,b,q);add(b,a,q);
			z[q]={a,b};
		}
		for(int q=1;q<=n;q++)v[q]=0;
		for(int q=1;q<=m;q++){
			int i;scanf("%d",&i);
			v[i]=1;
		}
		ans=1;
		if(m==1){dfs(1,1);}
		if(m==2){dfs3(1,1);}
		cout<<ans<<"\n";
	}
	return 0;
}
