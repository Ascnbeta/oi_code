#include"bits/stdc++.h"
using namespace std;
const int maxn = 1e5+10;
const int mo = 1e9+7;
int Ksm(int b,int t){
	int r=1;
	while(t){
		if(t&1)r=1ll*r*b%mo;
		b=1ll*b*b%mo;
		t>>=1;
	}
	return r;
}
int Case,T;
int n,k,u[maxn],v[maxn],Vs[maxn];
int Pw[maxn],As[maxn][2];
struct l{int To,w;};
vector<l>e[maxn];
int S,A;
int Sn[maxn],Sg[maxn];
void Df(int p,int Fa){
	Sn[p]=0;
	for(auto It:e[p]){
		int To=It.To;
		if(To==Fa)continue;
		Df(To,p);
		if(It.w&&(S&(1<<It.w-1))){
			Sn[p]++;
		}else{
			Sn[p]+=(Sn[To]>0);
		}
	}
}
void Dg(int p,int Fa){
	int Su=Sg[p];
	for(auto It:e[p])
		if(It.To!=Fa){
			if(S&(1<<It.w-1))Su+=1;
			else Su+=Sn[It.To];
		}
	for(auto It:e[p]){
		int To=It.To;
		if(To==Fa)continue;
		Sg[To]=0;
		if(It.w&&(S&(1<<It.w-1))){
			Sg[To]++;
		}else{
			Sg[To]+=(Su!=Sn[To]);
		}
		Dg(To,p);
	}
}
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>Case>>T;
	while(T--){
		cin>>n>>k,Pw[0]=1;
		for(int i=1;i<=n;i++)Pw[i]=1ll*i*Pw[i-1]%mo;
		for(int i=1;i<=n;i++){
			As[i][0]=Pw[i-1];
			if(i>=2)As[i][1]=Pw[i-2];
		}
		for(int i=1;i<n;i++)cin>>u[i]>>v[i];
		for(int i=1,t;i<=k;i++)cin>>t,Vs[t]=i;
		for(int i=1;i<n;i++){
			e[u[i]].push_back({v[i],Vs[i]});
			e[v[i]].push_back({u[i],Vs[i]});
		}
		int Ans=0;
		for(int s=1;s<(1<<k);s++){
			S=s,A=1;
			Df(1,0),Dg(1,0);
			for(int i=1;i<=n;i++){
				if(Sn[i]+Sg[i]>2){A=0;
				}else A=1ll*A*As[e[i].size()][Sn[i]+Sg[i]-1]%mo;
			}
			if(__builtin_popcount(s)&1)Ans=(Ans+A)%mo;
			else Ans=(Ans-A+mo)%mo;
		}	
		cout<<Ans<<endl;
		for(int i=1;i<=n;i++){
			u[i]=v[i]=Vs[i]=0;
			e[i].clear();
		}
	}
}
