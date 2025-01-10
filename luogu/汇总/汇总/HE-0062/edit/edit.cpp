#include<bits/stdc++.h>
using namespace std;
#define rd read()
#define gc getchar()
#define dg(ch) isdigit(ch)
#define _mul(x) ((x<<3)+(x<<1))
#define ll long long
#define il inline
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ROF(i,j,k) for(int i=j;i>=k;i--)
il int read(){int x=0,f=1;char ch=gc;while(!dg(ch)){if(ch=='-')f=-1;ch=gc;}while(dg(ch))x=_mul(x)+(ch^48),ch=gc;return x*f;}
const int N=1e5+10;
int T,n,tot,vis[N];char a[N],b[N],A[N],B[N],C[N];
struct node{int l,r;}p[N];
void solve(){
	n=rd,tot=0;memset(vis,0,sizeof(vis));
	scanf("%s %s %s %s",a+1,b+1,A+1,B+1);
	A[0]='0',B[0]='0',A[n+1]='0',B[n+1]='0';
	FOR(i,1,n){
		if(A[i-1]=='0'&&A[i+1]=='0') A[i]='0';
		if(B[i-1]=='0'&&B[i+1]=='0') B[i]='0';
	}
	FOR(i,1,n){
		if(A[i]=='1'||B[i]=='1') C[i]='1';
		else C[i]='0';
	}
	for(int i=1,l=0;i<=n;i=l+1){
		l=i;
		if(C[l]=='0') continue;
		while(l<=n&&C[l]=='1') l++;l--;
		p[++tot]=(node){i,l};
	}
	int ans=0;
	FOR(i,1,tot){
		int ca0=0,ca1=0,cb0=0,cb1=0;
		FOR(j,p[i].l,p[i].r){
			vis[j]=1;
			if(a[j]=='0') ca0++;else ca1++;
			if(b[j]=='0') cb0++;else cb1++; 
		}
		ans+=min(ca0,cb0)+min(ca1,cb1);
	}
	FOR(i,1,n){
		if(vis[i]) continue;
		ans+=(a[i]==b[i]);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	T=rd;
	while(T--) solve();
	return 0;
}
