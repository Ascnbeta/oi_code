#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define U(x) ((int)x.size())
#define ar(x) array<int,x>
const int N=1e5+100,MOD=1e9+7; int inv[N];
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

int jc[N],fjc[N];
void init(int n){
	jc[0]=1; for(int i=1;i<=n;++i) jc[i]=1ll*jc[i-1]*i%MOD;
	fjc[n]=qm(jc[n]); for(int i=n-1;~i;--i) fjc[i]=1ll*fjc[i+1]*(i+1)%MOD;
}

int n,m,op,sp[N],is[N];
struct E{ int x,y; }e[N];
vector<ar(2)> G[N];

inline void solA(){ printf("1\n"); }
inline void solB(){
	int res=1ll*m*jc[n-2]%MOD;
	if(n>=3) mod(res-=1ll*m*(m-1)%MOD*inv[2]%MOD*jc[n-3]%MOD);
	printf("%d\n", res);
}

int f[N][20][2][2],tmp[2][20],ts[20][2][2];
void dfs(int u,int fu){
	for(int i=0;i<=m;++i) f[u][i][0][0]=f[u][i][0][1]=f[u][i][1][0]=f[u][i][1][1]=0;
	f[u][0][1][0]=f[u][0][0][0]=1; int fl=0;
	for(auto to:G[u]){
		int v=to[0],id=to[1];
		if(v==fu) continue;
		dfs(v,u),fl|=1;
		memset(ts,0,sizeof(ts));
		mod(ts[0][0][0]+=1ll*f[u][0][0][0]*f[v][0][0][0]%MOD);
		for(int i=0;i<=m;++i){
			mod(ts[i][1][1]+=1ll*f[u][i][1][1]*f[v][0][0][0]%MOD);
			mod(ts[i][1][0]+=1ll*f[u][i][1][0]*f[v][0][0][0]%MOD);
			for(int j=0;j<=m;++j) mod(ts[i+j+is[id]][1][1]+=1ll*f[u][i][1][0]*f[v][j][1][1]%MOD);
		}
		for(int i=0;i<=m;++i) f[u][i][0][0]=ts[i][0][0],f[u][i][0][1]=ts[i][0][1],f[u][i][1][0]=ts[i][1][0],f[u][i][1][1]=ts[i][1][1];
	}
	
	for(int i=0;i<=m;++i) f[u][i][1][1]=1ll*f[u][i][1][1]*jc[U(G[u])-2]%MOD;
//	for(int i=0;i<=m;++i) f[u][i][1][1]=1ll*f[u][i][1][0]*jc[U(G[u])-2]%MOD;
//	for(int i=0;i<=m;++i) f[u][i][1][1]=1ll*f[u][i][1][1]*jc[U(G[u])-2]%MOD;
	f[u][0][0][0]=1ll*f[u][0][0][0]*jc[U(G[u])-1]%MOD;
	
	if(!fl) f[u][0][1][1]=1;
}

void sol(){
	int ans=0;
	for(int i=1;i<=m;++i){
		dfs(e[sp[i]].x,0);
		for(int j=0;j<=m;++j) tmp[0][j]=f[e[sp[i]].y][j][1][1];
		dfs(e[sp[i]].y,0);
		for(int j=0;j<=m;++j) tmp[1][j]=f[e[sp[i]].x][j][1][1];
		for(int j=0;j<=m;++j){
			for(int k=0;k<=m;++k){
				
//				cout<<j<<" "<<k<<" "<<tmp[0][j]<<" "<<tmp[1][k]<<"\n";
				
				mod(ans+=1ll*inv[j+k+1]*tmp[0][j]%MOD*tmp[1][k]%MOD);
			}
		}
	}
	printf("%d\n", ans);
}

void solve(){
	n=rd,m=rd;
	for(int i=1,x,y;i<n;++i) x=rd,y=rd,G[x].pb({y,i}),G[y].pb({x,i}),e[i]={x,y};
	for(int i=1;i<=m;++i) is[sp[i]=rd]=1;
	if(op==18) return solA(),void();
	if(19<=op&&op<=21) return solB(),void();
	
//	cerr<<"???";
	
	sol();
	
	for(int i=1;i<=n;++i) G[i]={},is[i]=0;
}

int main(){

	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	for(int i=1;i<=N-100;++i) inv[i]=qm(i);
	
	init(N-100);
	
	op=rd; int T=rd;
	while(T--) solve();
	
	return 0;
}
/*
1 1
4 1
1 2
2 3
2 4
1
*/
