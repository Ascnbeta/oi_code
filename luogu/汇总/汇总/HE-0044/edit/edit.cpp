#include<bits/stdc++.h>
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=2e5+10;
int T,n,ans,r[N];
string s[2],t[2];
struct node{int num[2];}cnt[N];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void Merge(int x,int y){
	if((x=find(x))==(y=find(y)))return ;
	fa[x]=y; cnt[y].num[0]+=cnt[x].num[0];
	cnt[y].num[1]+=cnt[x].num[1]; r[y]=max(r[y],r[x]);
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n); ans=0;
		cin>>s[0]>>s[1]; s[0]=" "+s[0]; s[1]=" "+s[1];
		cin>>t[0]>>t[1]; t[0]=" "+t[0]; t[1]=" "+t[1];
		rpt(i,1,n*2)cnt[i].num[0]=cnt[i].num[1]=0,fa[i]=i,r[i]=i;
		rpt(i,1,n){
			if(s[0][i]=='1')cnt[i].num[1]=1;
			else cnt[i].num[0]=1;
			if(s[1][i]=='1')cnt[i+n].num[1]=1;
			else cnt[i+n].num[0]=1;
			if(t[0][i]=='1'&&t[0][i-1]=='1')Merge(i,i-1);
			if(t[1][i]=='1'&&t[1][i-1]=='1')Merge(n+i,n+i-1);
		}
		rpt(i,1,n){
			int x=find(i); int y=find(n+i);
			int a=(cnt[x].num[0]&&cnt[y].num[0]);
			int b=(cnt[x].num[1]&&cnt[y].num[1]);
			if(a)cnt[x].num[0]--,cnt[y].num[0]--,ans++;
			if(b)cnt[x].num[1]--,cnt[y].num[1]--,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
6
111000
000111
111100
001111

*/
