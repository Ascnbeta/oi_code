#include<bits/stdc++.h>
#define rd read()
#define pk(a) push_back(a)
#define epk(a) emplace_back(a)
#define mst(a,b) memset(a,b,sizeof(a))
#define fro(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b) for(int i=a;i>=b;i--)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
const int N=5e5+5,M=1e6+5;

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
	return x*w;
}

int mx(int a,int b){return a>b?a:b;}
int mn(int a,int b){return a<b?a:b;}

int n,q;

int h[N],e[M],ne[M],idx;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dep[N],id[N],tot;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	id[u]=++tot;
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa)continue;
		dfs(j,u);
	}
}

int main(){

	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	n=rd;mst(h,-1);
	rep(i,1,n){
		int a=rd,b=rd;
		add(a,b),add(b,a);
	}
	dfs(1,0);
	q=rd;
	while(q--){
		int l=rd,r=rd,k=rd;
		int ans=-1;
		for(int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			ans=max(ans,dep[(id[i]+id[j])/2]);
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}

