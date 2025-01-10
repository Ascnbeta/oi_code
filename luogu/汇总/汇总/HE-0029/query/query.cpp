#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m;
vector<int> e[N];

/*
	//freopen("query1.in","w",stdin)
	//freopen("query1.out","r",stdout)
	y1
	return 0
	
	-----------
	
	Never mind these.
	You know what I'm going to do : write something like "coufusing code";
	And cheat you to look it.
	
	But please do not be annoyed, I'd like to share my story of OI with you.
	
	I'm a student of Hengshui High School.
	To be honest, one of the reasons of coming Hengshui is to learn olympics.
	And between OI and Math, I choose former.
	With no experience before, what I got is the passion, the friend, and the mate.
	So I come through.
	
	However, the more I know, the fewer expection I had.
	HE, was a weak province.
	With only 7 place to go to NOI, how can I get in to it ? 
	
	But I stuck to it.
	Why ? I had asked myself many times.
	Maybe, this is passion.
	
	Time passed by.
	A new season is coming, and for us, zero-experience, it's the only chance.
	Got 250Pts in CSP-S, HE 29.
	I acted alright in this contest.
	
	But the problem is, if you act just normal, then it's bad.
	And I act normal in NOIP.
	
	So, maybe this is my final contest.
	But I won't regard as learning OI.
	As it brings me happiness, friends, challenges, and a period of great memory.
	Thanks all of you.
	
	At last, hope int_R, 5k_sync_closer, Estllen, jijidawang, K8HE;
	And many master in S2 or ZhiZhen od somewhere else;
	Hope you can make HE great again.
	For yout dream.
	
	luobotianle AFO.
	luogu uid:1245780
	(Maybe there are a lot of mistakes, never mind QAQ)
*/

int dep[N],fa[N],son[N],top[N],siz[N];
void dfs1(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	siz[x]=1;
	int maxc=0;
	for(int to:e[x]){
		if(to==f)continue;
		dfs1(to,x);
		siz[x]+=siz[to];
		if(siz[to]>maxc){
			maxc=siz[to];
			son[x]=to;
		}
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	if(!son[x])return;
	dfs2(son[x],topf);
	for(int to:e[x]){
		if(to==fa[x]||to==son[x])continue;
		dfs2(to,to);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}

int st[N][21];
int lg[N];
void init(int n){
	for(int i=1;i<=n;i++)st[i][0]=i;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j){
			lg[i]++;
			j>>=1;
		}
		lg[i]--;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=lca(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	int k=lg[r-l+1];
	return lca(st[l][k],st[r-(1<<k)+1][k]);
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1);
	init(n);
	cin>>m;
	for(int i=1,l,r,k;i<=m;i++){
		cin>>l>>r>>k;
		int ans=0;
		for(int j=l;j+k-1<=r;j++){
			ans=max(ans,dep[query(j,j+k-1)]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
