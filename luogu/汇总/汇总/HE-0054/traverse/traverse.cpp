#include<bits/stdc++.h>
#define int long long
using namespace std;
int kuaidu(){
	int r=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=(r<<3)+(r<<1)+(ch-'0');
		ch=getchar();
	}
	return r*f;
}
int c,t;
const int N=1e5+10;
const int P=1e9+7;
int n,k,a[N],d[N],ans,f[N];
bool fl[N];
vector< pair<int,int> >v[N],vv[N];
int dfs(int s,int fa){
	
}
void pprework(){
	ans=0;
	n=kuaidu(),k=kuaidu();
//	for(int i=1;i<n;i++){
//		int x,y;
//		x=kuaidu(),y=kuaidu();
//		d[x]++,d[y]++;
//		v[x].push_back({i,y});
//		v[y].push_back({i,x});
//		vv[i].push_back({x,y});
//	}
//	for(int i=1;i<=k;i++){
//		a[i]=kuaidu();
//		dfs(a[i],0);
//	}
	cout<<n<<'\n';
}
void ssolve(){
	for(int i=1;i<=n;i++){
		v[i].clear();
		vv[i].clear();
		d[i]=0;
	}
	for(int i=1;i<=k;i++){
		a[i]=0;
	}
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	c=kuaidu(),t=kuaidu();
	while(t--){
		pprework();
		ssolve();
	}	
	return 0;
} 
