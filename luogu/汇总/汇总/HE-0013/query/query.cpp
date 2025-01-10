#include<bits/stdc++.h>
using namespace std;
struct node{
	int end,nxt;
}edge[1000100];
int n,q,cnt,dfncnt,head[500100],fa[500100],dep[500100],dfn[500100],mp[500100];
int lg[500100];
struct sttb{
	int st[20][500100];
	inline void build(auto fx,auto fy){
		for(int i=1;i<=n;++i){
			st[0][i]=fx(i);
			// cout<<st[0][i]<<" ";
			for(int j=1;(1<<j)<=i;++j){
				if(fy(st[j-1][i-(1<<(j-1))],st[j-1][i])){
					st[j][i]=st[j-1][i-(1<<(j-1))];
				}else{
					st[j][i]=st[j-1][i];
				}
				// cout<<st[j][i]<<" ";
			}
			// cout<<endl;
		}
	}
	inline int query(int x,int y,auto fy){
		int tem=lg[y-x+1];
		return fy(st[tem][x+(1<<tem)-1],st[tem][y]);
	}
}mnds,mxds,ds;
inline void add(int x,int y){
	++cnt;
	edge[cnt]={y,head[x]};
	head[x]=cnt;
}
void dfs(int x,int y){
	dep[x]=dep[y]+1;
	fa[x]=y;
	++dfncnt;
	dfn[x]=dfncnt;
	mp[dfncnt]=x;
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].end^y){
			dfs(edge[i].end,x);
		}
	}
}
inline int qans(int x,int y){
	int tx=mnds.query(x,y,[](int x,int y){return min(x,y);}),ty=mxds.query(x,y,[](int x,int y){return max(x,y);});
	// cout<<x<<" "<<y<<" "<<tx<<" "<<ty<<endl;
	if(tx==ty){
		return dep[x];
	}
	++tx;
	int tem=lg[ty-tx+1];
	return min(ds.st[tem][tx+(1<<tem)-1],ds.st[tem][ty]);
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	int ta,tb;
	for(int i=1;i<n;++i){
		scanf("%d%d",&ta,&tb);
		add(ta,tb);
		add(tb,ta);
	}
	dfs(1,0);
	// for(int i=1;i<=n;++i){
	// 	cout<<i<<" "<<fa[i]<<" "<<dep[i]<<" "<<dfn[i]<<endl;
	// }
	mnds.build([](int x){return dfn[x];},[](int x,int y){return x<y;});
	mxds.build([](int x){return dfn[x];},[](int x,int y){return x>y;});
	ds.build([](int x){return dep[fa[mp[x]]];},[](int x,int y){return x<y;});
	scanf("%d",&q);
	int tc;
	for(;q;--q){
		scanf("%d%d%d",&ta,&tb,&tc);
		int ans=0;
		for(int i=ta,j=ta+tc-1;j<=tb;++i,++j){
			ans=max(ans,qans(i,j));
		}
		printf("%d\n",ans);
	}
	return 0;
}