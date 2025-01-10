#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct a1{
	int nex,to;
}x[N];int head[N],p;
void add(int a,int b){
	x[++p].nex=head[a];
	x[p].to=b;
	head[a]=p;
}
int deep[N],f[N][25],dfn[N],cnt,n,m,id[N];
void dfs(int a,int fa){
	deep[a]=deep[fa]+1;
	f[a][0]=fa;dfn[a]=++cnt;id[cnt]=a;
	for(int q=1;q<=20;q++)f[a][q]=f[f[a][q-1]][q-1];
	for(int q=head[a];q;q=x[q].nex){
		int o=x[q].to;
		if(o!=fa){
			dfs(o,a);
		}
	}
}
int logg[N];
int LCA(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	while(deep[a]>deep[b])a=f[a][logg[deep[a]-deep[b]]-1];
	if(a==b)return a;
	for(int q=20;q>=0;q--){
		if(f[a][q]!=f[b][q]){
			a=f[a][q];b=f[b][q];
		}
	}
	return f[a][0];
}
int Max[N][25],Min[N][25];
void ST(){
	for(int q=0;q<=n+2;q++){
		for(int i=0;i<=21;i++){
			Max[q][i]=-1e9;
			Min[q][i]=1e9;
		}
	}
	for(int q=1;q<=n;q++)Max[q][0]=Min[q][0]=dfn[q];
	for(int i=1;i<=20;i++){
		for(int q=1;q+(1<<i)-1<=n;q++){
			Max[q][i]=max(Max[q][i-1],Max[q+(1<<(i-1))][i-1]);
			Min[q][i]=min(Min[q][i-1],Min[q+(1<<(i-1))][i-1]);
		}
	}
}
int Gmin(int l,int r){
	int k=logg[r-l+1]-1;
	return min(Min[l][k],Min[r-(1<<k)+1][k]);
}
int Gmax(int l,int r){
	int k=logg[r-l+1]-1;
	return max(Max[l][k],Max[r-(1<<k)+1][k]);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	cin>>n;
	for(int q=1;q<=n;q++)logg[q]=logg[q/2]+1;
	for(int q=1;q<n;q++){
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	dfs(1,1);ST();
	cin>>m;
	for(int q=1;q<=m;q++){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		int ans=0;
		for(int i=l;i<=r-k+1;i++){
			int x=id[Gmin(i,i+k-1)],y=id[Gmax(i,i+k-1)];
			ans=max(ans,deep[LCA(x,y)]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
