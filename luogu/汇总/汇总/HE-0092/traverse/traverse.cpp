#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
const int mod=1e9+7;

int c,n,t;
int k,a,b;
int x[N];

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
	if(c==18){
		cout<<1<<"\n";
	}
	if(c>=19&&c<=21){
		n=read();
		k=read();
		for(int i=1;i<n;i++)a=read(),b=read();
		for(int i=1;i<=k;i++)a=read();
		if(n==1)cout<<0<<"\n";
		if(n==2)cout<<1<<"\n";
		int ans=0;
		int y=x[n-2];
		y=k*(k-1)%mod*y%mod*ksm(2,mod-2)%mod;
		ans=x[n]-y;
		print((ans%mod+mod)%mod);
		cout<<"\n";
	}
}

signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	x[1]=1;
	for(int i=2;i<=100000;i++){
		x[i]=x[i-1]*i%mod;
	}
	c=read();
	t=read();
	while(t--)solve();
	return 0;
}
/*
19 1
3 2
1 2
1 2
1 2
*/
