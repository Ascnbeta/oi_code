#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
const int N=1e5+10;
int ksm(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*a%P){
		if(b&1)r=r*a%P;
	}
	return r;
}
int t;
int n,m,v,ans;
struct node{
	int c,d;
}a[N];
int cmp(node a,node b){
	return a.c<b.c;
}
int f[N];
void pprework(){
	ans=0;
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++){
		cin>>a[i].c>>a[i].d;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=2;i<=m;i++){
		if(a[i].c==a[i-1].c&&a[i].d!=a[i-1].d){
			cout<<0<<'\n';
			return;
		}
	}
	if(m==1){
		ans=ksm(v*v%P,n-1);
		cout<<(ans%P+P)%P<<'\n';
		return;
	}
	if(n==m){
		cout<<(ksm(((v-1)*v+1)%P,n-1)%P+P)%P<<'\n';
		return;
	}
	f[1]=ksm(v*v%P,a[1].c-1);
	for(int i=2;i<=m;i++){
		if(a[i].c==a[i-1].c)f[i]=f[i-1];
		else f[i]=f[i-1]*((ksm(v,a[i].c-a[i-1].c-1)+ksm(v,2*(a[i].c-a[i-1].c))-ksm(v,a[i].c-a[i-1].c)+P)%P)%P;
	}
	ans=f[m]*ksm(v*v%P,n-a[m].c)%P;
	cout<<(ans%P+P)%P<<'\n';
}
void ssolve(){
	for(int i=1;i<=m;i++){
		a[i].c=a[i].d=f[i]=0;
	}
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--){
		pprework();
		ssolve();
	}
	return 0;
}
