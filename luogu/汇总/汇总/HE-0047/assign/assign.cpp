#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N=1e5+9;
const int p=1e9+7;
int n,m;
ll v,as;
int c[N],d[N];


struct node{
	int c,d;
	node(){
		c=0;d=0;
	}
}e[N];



bool cmp(node a,node b){
	if(a.c==b.c)return a.d<b.d;
	return a.c<b.c;
}

ll pw(ll x,ll k){
	ll as=1;
	x%=p;
	while(k){
		if(k&1)as=(as*x)%p;
		k>>=1;
		x=(x*x)%p;
	}return as;
}

void sol(){
	cin>>n>>m>>v;
	int tp=0;
	for(int i=1;i<=m;++i){
		cin>>e[i].c>>e[i].d;
	}sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(e[i].c==e[i-1].c){
			if(e[i].d==e[i-1].d)continue;
			else {
				cout<<"0\n";
				return ;
			}
		}else c[++tp]=e[i].c;
	}m=tp;
//	as=pw(v*v%p,n-1);
	ll t0=0,t1=pw(v*v%p,c[1]-1),s=pw(v*v%p,c[1]-1); 
//	cout<<t1<<" "<<t0<<" "<<s<<"\n";
	for(int i=2;i<=m;++i){
		t0=(((t1*pw(v,c[i]-c[i-1]-1)%p)%p+(t0*pw(v*v%p,c[i]-c[i-1])%p)%p)%p+p)%p;
		s=s*pw(v*v%p,c[i]-c[i-1])%p;
		t1=((s-t0)%p+p)%p;
//		cout<<" "<<i<<" "<<s<<"¡¡  "<<t1<<" "<<t0<<"\n"; 
	}cout<<(t1*pw(v*v%p,n-c[m]))%p<<"\n";
}

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
//	T=4;
	while(T--){
		sol();
	}
	return 0;
}
/*
1
10 11 2
10 2
7 2
7 2
2 2
3 2
4 2
10 2
7 2
10 2
3 2
3 2

*/
