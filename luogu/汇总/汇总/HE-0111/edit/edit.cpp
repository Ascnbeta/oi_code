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
const int N=1e5+5;

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
	return x*w;
}

int mx(int a,int b){return a>b?a:b;}
int mn(int a,int b){return a<b?a:b;}

int n;
char s1[N],s2[N];
char t1[N],t2[N];

int main(){

	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);

	int T=rd;
	while(T--){
		n=rd;
		scanf("%s %s",(s1+1),(s2+1));
		scanf("%s %s",(t1+1),(t2+1));
		bool f1=0;
		fro(i,2,n){
			if(s1[i]!=s1[i-1])f1=1;
		}
		int ans=0;
		if(!f1){
			fro(i,1,n){
				if(s1[i]==s2[i])ans++;
			}
		}
		else{
			int cn10=0,cn11=0;
			int cn20=0,cn21=0;
			fro(i,1,n){
				if(!t1[i]){
					if(s1[i]==s2[i])ans++;
				}
				else{
					if(s1[i]=='1')cn11++;
					else cn10++;
					if(s2[i]=='1')cn21++;
					else cn20++;
				}
			}
			ans+=(mn(cn11,cn21)+mn(cn10,cn20));
		}
		printf("%d\n",ans);
	}

	return 0;
}

