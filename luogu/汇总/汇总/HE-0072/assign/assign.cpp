#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int read(){
	int s=0,f=1;
	char _z=getchar();
	while(_z<'0'||_z>'9'){
		if(_z=='-')
		f=-1;
		_z=getchar();
	}
	while(_z>='0'&&_z<='9'){
		s=(s<<3)+(s<<1)+(_z-'0');
		_z=getchar();
	}
	return s*f;
}
const int N=1e5+10,mo=1e9+7;
typedef long long ll;
struct Qu{
	int c,d;
	bool operator<(const Qu x)const{
		return c<x.c;
	}
}qu[N];
ll POW(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)
		res=(res*x)%mo;
		y>>=1;
		x=(x*x)%mo;
	}
	return res;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int t=read();
	while(t--){
		int n=read(),m=read();
		ll v=read();
		for(int i=1;i<=m;i++){
			qu[i].c=read(),qu[i].d=read();
		}
		sort(qu+1,qu+m+1);
		ll ans=POW(v*v%mo,qu[1].c-1),z=0;
		for(int i=2;i<=m;i++){
			if(qu[i-1].c==qu[i].c){
				if(qu[i-1].d!=qu[i].d){
					ans=0;
					break;
				}else{
					continue;
				}
			}else if(qu[i-1].c+1==qu[i].c){
				ans=(ans*(((v-1)*v+1)%mo))%mo;
			}else{
				ll res=POW(v*v%mo,qu[i].c-qu[i-1].c);
				res=((res-POW(v,qu[i].c-qu[i-1].c-1)*(v-1))%mo+mo)%mo;
				ans=(ans*res)%mo;
			}
		}
		if(qu[m].c<n)
		ans=(ans*POW(v*v%mo,n-qu[m].c))%mo;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
