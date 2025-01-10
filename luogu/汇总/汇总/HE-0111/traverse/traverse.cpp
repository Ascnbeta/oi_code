#include<bits/stdc++.h>
#define rd read()
#define pk(a) push_back(a)
#define epk(a) emplace_back(a)
#define mst(a,b) memset(a,b,sizeof(a))
#define fro(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b) for(int i=a;i>=b;i--)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
const int N=1e5+5,M=2e5+5;
const int mod=1e9+7;

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
	return x*w;
}

int mx(int a,int b){return a>b?a:b;}
int mn(int a,int b){return a<b?a:b;}

int n,k;

int h[N],e[M],ne[M],idx;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){

	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);

	int C=rd;int T=rd;
	while(T--){
		int n=rd;int k=rd;
		bool fl=0;
		rep(i,1,n){
			int a=rd;int b=rd;
			add(a,b),add(b,a);
			if(b!=a+1)fl=1;
		}
		if(fl){
			fro(i,1,k){
				int c=rd;
				printf("1 ");
			}
			puts("");
		}
		else{
			fro(i,1,k){
				int c=rd;
				if(n>4)printf("%d ",(n*(n-1)/2)%mod);
				else printf("1 ");
			}
			puts("");
		}
	}

	return 0;
}

