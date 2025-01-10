#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
const int mod=1e9+7;

int n,t;
int m,v,a,b;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
}

int ksm(int x,int y){
	int num=1;
	x%=mod;
	while(y){
		if(y&1)num=num*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return num%mod;
}

void solve(){
	n=read();
	m=read();
	v=read();
	for(int i=1;i<=m;i++){
		a=read();
		b=read();
	}
	print(ksm(v*v,n-1)%mod);
	cout<<"\n";
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	t=read();
	while(t--)solve();
}
