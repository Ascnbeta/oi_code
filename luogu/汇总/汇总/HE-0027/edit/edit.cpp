#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using llf=long double;
using ull=unsigned long long;
#define endl '\n'
#ifdef LOCAL
	FILE *InFile=freopen("in_out/in.in","r",stdin),*OutFile=freopen("in_out/out.out","w",stdout);
#else
	FILE *InFile=freopen("edit.in","r",stdin),*OutFile=freopen("edit.out","w",stdout);
#endif

const int N=1e5+3;
bool s1[N],s2[N]; int n;
struct P{int p,c1,c0; P(int a,int b,int c):p(a),c1(b),c0(c){};};
vector<P> cp1,cp2;

void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){char c; cin>>c; s1[i]=c-'0';} s1[n+1]=0;
	for(int i=1;i<=n;++i){char c; cin>>c; s2[i]=c-'0';} s2[n+1]=1;
	int c1=0,c0=0;
	for(int i=1;i<=n;++i){
		char c; cin>>c;
		if(c=='1') s1[i]?++c1:++c0;
		else cp1.emplace_back(i,c1,c0),c1=c0=0;
	} cp1.emplace_back(n+1,c1,c0);
	c1=0,c0=0;
	for(int i=1;i<=n;++i){
		char c; cin>>c;
		if(c=='1') s2[i]?++c1:++c0;
		else cp2.emplace_back(i,c1,c0),c1=c0=0;
	} cp2.emplace_back(n+1,c1,c0);
	auto p1=cp1.begin(),p2=cp2.begin(); int ans=0;
	while(p1!=cp1.end()||p2!=cp2.end()){
		if(p1->p==p2->p){
			ans+=(s1[p1->p]==s2[p2->p]);
			int m0=min(p1->c0,p2->c0),m1=min(p1->c1,p2->c1);
			ans+=m0+m1,++p1,++p2;
		}else if(p1->p<p2->p){
			(s1[p1->p]?++(p1->c1):++(p1->c0));
			int m0=min(p1->c0,p2->c0),m1=min(p1->c1,p2->c1);
			ans+=m0+m1;
			p2->c0-=m0,p2->c1-=m1,(p2->c0?p2->c0:p2->c1)-=p1->c0+p1->c1-m0-m1,++p1;
		}else{
			(s2[p2->p]?++(p2->c1):++(p2->c0));
			int m0=min(p2->c0,p1->c0),m1=min(p2->c1,p1->c1);
			ans+=m0+m1;
			p1->c0-=m0,p1->c1-=m1,(p1->c0?p1->c0:p1->c1)-=p2->c0+p2->c1-m0-m1,++p2;
		}
	}
	cout<<ans<<endl;
}

void Clear(){cp1.clear(),cp2.clear();};

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t; cin>>t; while(t--) Solve(),Clear();
}