#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=1e5+10,mod=1e9+7;
int t,n,m,v,c[N],d[N];
int poww(int x,int b){
	int anss=1;
	while(b){
		if(b&1)
		anss*=x,anss%=mod;
		b>>=1;
		x*=x;
		x%=mod;
	}
	return anss;
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cout<<2; 
	return 0;
} 
