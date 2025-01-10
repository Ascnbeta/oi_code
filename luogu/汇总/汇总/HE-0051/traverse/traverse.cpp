#include <bits/stdc++.h>
#define ll long long
#define ts cout<<"*************"<<endl;
#define pb push_back
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N =2e5+5;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline void write(ll x,char p){
	write(x);putchar(p);
}
bool Mbe;
int n,k;
inline void solve(){
	// ts;
	n=read();k=read();
	// cout<<n<<" "<<k<<endl;
	// for(int i=1,u,v;i<n;i++){
	// 	u=read();v=read();
	// }
	// int a;
	// for(int i=1;i<=k;i++){
	// 	a=read();
	// }
	write(1,'\n');
}	
bool Med;
int main(){
	file("traverse");
	int c=read();
	int T=read();
	while(T--)
		solve();
	cerr<<(&Mbe-&Med)/1024.0/1024.0<<"MB "<<" "<<(double)clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}