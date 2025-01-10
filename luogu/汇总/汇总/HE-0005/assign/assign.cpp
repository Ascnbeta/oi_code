#include"bits/stdc++.h"
using namespace std;
#define F first
#define S second
const int maxn = 1e5+10;
const int mo = 1e9+7;
int T,n,m,v;
struct Matrix{
	int M[2][2];
	Matrix(int x=0){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				M[i][j]=(i==j?x:0);
	}
	Matrix operator * (Matrix x){
		Matrix R(0);
		for(int k=0;k<2;k++)
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					R.M[i][j]=(R.M[i][j]+1ll*M[i][k]*x.M[k][j])%mo;
		return R;
	}
}Bs;
Matrix Ksm(Matrix b,int t){
	Matrix r(1);
	while(t){
		if(t&1)r=r*b;
		b=b*b,t>>=1;
	}
	return r;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n>>m>>v;
		Bs.M[0][0]=v;
		Bs.M[0][1]=1ll*v*(v-1)%mo;
		Bs.M[1][1]=1ll*v*v%mo;
		vector<pair<int,int> >Vc;
		for(int i=1,u,v;i<=m;i++)
			cin>>u>>v,Vc.push_back({u,v});
		sort(Vc.begin(),Vc.end());
		int Fl=1;
		for(int i=1;i<Vc.size();i++)
			if(Vc[i].F==Vc[i-1].F&&Vc[i].S!=Vc[i-1].S)
				Fl=0;
		Vc.erase(unique(Vc.begin(),Vc.end()),Vc.end());
		if(Fl==0){
			cout<<0<<endl;
		}else{
			int p=0,Ans=1;
			for(int i=0;i<Vc.size();i++){
				if(Vc[i].F==1){
					Ans=1;
				}else{
					if(p==0){
						Matrix Z=Ksm(Bs,Vc[i].F-2);
						Ans=(1ll*Ans*Z.M[1][1]%mo)*(1ll*v*v%mo)%mo;
					}else{
						Matrix Z=Ksm(Bs,Vc[i].F-p);
						Ans=((1ll*Ans*Z.M[0][0]%mo)*(1ll*v*(v-1)%mo+1)%mo+
							(1ll*Ans*Z.M[0][1]%mo)*(1ll*v*v%mo)%mo)%mo;
					}
				}
				p=Vc[i].F+1;
			}
			if(p<=n){
				Matrix Z=Ksm(Bs,n-p+1);
				int A=(Z.M[0][0]+Z.M[0][1])%mo;
				Ans=1ll*Ans*A%mo;
			}
			cout<<Ans<<endl;
		}
	}
}
