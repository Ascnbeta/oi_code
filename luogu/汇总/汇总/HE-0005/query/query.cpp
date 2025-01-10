#include"bits/stdc++.h"
using namespace std;
const int maxn = 5e5+10;
const int Lgn = 19;
int n,q;
int Ans[maxn];
vector<int>e[maxn];
struct Itr{
	bool Ty;
	int l,r,k,I;
	//Ty==0->Interval [l,r,Dp]
	//Ty==1->Query [l,r,k,I]
}N[maxn<<2];
inline bool cmp(const Itr& u,const Itr& v){return u.k==v.k?u.Ty<v.Ty:u.k>v.k;}
inline bool cmp2(const Itr& u,const Itr& v){return u.l==v.l?(u.Ty<v.Ty):u.l<v.l;}
int Ix;
namespace Sg1{
	int F[maxn][Lgn+1],Dp[maxn];
	struct Node{int Ls,Rs,Su;}Tr[maxn*22];
	int TIdx;
	int rt[maxn];
	vector<int>Q[maxn];
	void D1(int p,int Fa){
		F[p][0]=Fa,Dp[p]=Dp[Fa]+1;
		for(int i=1;i<=Lgn;i++)
			F[p][i]=F[F[p][i-1]][i-1]; 
		for(auto To:e[p]){
			if(To==Fa)continue;
			D1(To,p);
		}
	}
	inline void P(const int& x){
		Tr[x].Su=Tr[Tr[x].Ls].Su+Tr[Tr[x].Rs].Su; 
	}
	inline int Lca(int u,int v){
		if(Dp[u]>Dp[v])swap(u,v);
		for(int j=Lgn;j>=0;j--)
			if(Dp[u]<=Dp[F[v][j]])
				v=F[v][j];
		if(u==v)return u;
		for(int j=Lgn;j>=0;j--)
			if(F[u][j]!=F[v][j])
				u=F[u][j],v=F[v][j];
		return F[u][0];
	} 
	void Insert(int &x,int l,int r,int p){
		if(!x)x=++TIdx;
		if(l==r)return Tr[x].Su=1,void();
		int M=(l+r)>>1;
		if(p<=M)Insert(Tr[x].Ls,l,M,p);
		else Insert(Tr[x].Rs,M+1,r,p);
		P(x);
	}
	int FindL(int x,int l,int r,int ql,int qr){
		if(Tr[x].Su==r-l+1)return 0;
		if(l==r)return l;
		if(ql<=l&&r<=qr){
			int M=(l+r)>>1,K=0;
			if(K==0)K=FindL(Tr[x].Rs,M+1,r,ql,qr);
			if(K==0)K=FindL(Tr[x].Ls,l,M,ql,qr);
			return K;	
		}else{
			int M=(l+r)>>1,K=0;
			if(qr>M&&K==0)K=FindL(Tr[x].Rs,M+1,r,ql,qr);
			if(ql<=M&&K==0)K=FindL(Tr[x].Ls,l,M,ql,qr);
			return K;
		}
	}
	int FindR(int x,int l,int r,int ql,int qr){
		if(Tr[x].Su==r-l+1)return n+1;
		if(l==r)return l;
		if(ql<=l&&r<=qr){
			int M=(l+r)>>1,K=n+1;
			if(K==n+1)K=FindR(Tr[x].Ls,l,M,ql,qr);
			if(K==n+1)K=FindR(Tr[x].Rs,M+1,r,ql,qr);
			return K;	
		}else{
			int M=(l+r)>>1,K=n+1;
			if(ql<=M&&K==n+1)K=FindR(Tr[x].Ls,l,M,ql,qr);
			if(qr>M&&K==n+1)K=FindR(Tr[x].Rs,M+1,r,ql,qr);
			return K;
		}
	}
	int Merge(int u,int v){
		if(!u||!v)return u+v;
		Tr[u].Su+=Tr[v].Su;
		Tr[u].Ls=Merge(Tr[u].Ls,Tr[v].Ls);
		Tr[u].Rs=Merge(Tr[u].Rs,Tr[v].Rs);
		return u;
	}
	void D2(int p,int Fa){
		for(auto To:e[p]){
			if(To==Fa)continue;
			D2(To,p);
			rt[p]=Merge(rt[p],rt[To]); 
		}
		N[++Ix]={0,p,p,1,Dp[p]};
		for(auto It:Q[p]){
			int L=FindL(rt[p],1,n,1,It);
			int R=FindR(rt[p],1,n,It+1,n);
			N[++Ix]={0,L+1,R-1,R-L-1,Dp[p]};
		}
	}
	void Work(){
		D1(1,0);
		for(int i=1;i<n;i++)
			Q[Lca(i,i+1)].push_back(i);
		for(int i=1;i<=n;i++)
			Insert(rt[i],1,n,i);
		D2(1,0);
	}
}

int Tr[maxn<<2];
inline void P(const int& x){Tr[x]=max(Tr[x<<1],Tr[x<<1|1]);}
void BdTree(const int& x,const int& l,const int& r){
	Tr[x]=0;
	if(l==r)return void();
	int M=(l+r)>>1;
	BdTree(x<<1,l,M);
	BdTree(x<<1|1,M+1,r);
}
void Modify(const int& x,const int& l,const int& r,const int& p,const int& D){
	if(l==r)return Tr[x]=max(Tr[x],D),void();
	int M=(l+r)>>1;
	if(p<=M)Modify(x<<1,l,M,p,D);
	if(p>M)Modify(x<<1|1,M+1,r,p,D);
	P(x);
}
int Query(const int& x,const int& l,const int& r,const int& ql,const int& qr){
	if(ql<=l&&r<=qr)return Tr[x];
	const int M=(l+r)>>1;
	int Re=0;
	if(ql<=M)Re=max(Re,Query(x<<1,l,M,ql,qr));
	if(qr>M)Re=max(Re,Query(x<<1|1,M+1,r,ql,qr));
	return Re;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr); 
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	Sg1::Work();
	cin>>q;
	for(int i=1,l,r,k;i<=q;i++){
		cin>>l>>r>>k;
		N[++Ix]={1,l,r,k,i};
	}
	sort(N+1,N+Ix+1,cmp);
	for(int i=1;i<=Ix;i++){
		if(N[i].Ty==0){
			Modify(1,1,n,N[i].r,N[i].I);
		}else{
			Ans[N[i].I]=max(Ans[N[i].I],Query(1,1,n,N[i].l+N[i].k-1,N[i].r));
		}
	}
	BdTree(1,1,n);
	for(int i=1;i<=Ix;i++){
		if(N[i].Ty==0){
			Modify(1,1,n,N[i].l,N[i].I);
		}else{
			Ans[N[i].I]=max(Ans[N[i].I],Query(1,1,n,N[i].l,N[i].r-N[i].k+1));
		}
	}
	BdTree(1,1,n);
	sort(N+1,N+Ix+1,cmp2);
	for(int i=1;i<=Ix;i++){
		if(N[i].Ty==0){
			Modify(1,1,n,N[i].r,N[i].I);
		}else{
			Ans[N[i].I]=max(Ans[N[i].I],Query(1,1,n,N[i].r,n));
		}
	}
	for(int i=1;i<=q;i++)
		cout<<Ans[i]<<'\n'; 
}
