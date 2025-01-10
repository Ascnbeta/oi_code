#include<bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,ans;
int ts[N],tt[N];
char s[N],t[N],a[N],b[N];
namespace sub1{
int calc(){
	int cs,ct,ls[N],rs[N],lt[N],rt[N],s1[N],t1[N],cnt1;
	int res=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1]){
			if(a[i-1]!='2')rs[cs-1]=i-1;
			if(a[i]!='2'){
				ls[++cs]=i;
				ts[cs]=(s[i]=='1');//ÑÕÉ« 
			}
		}
		if(b[i]!=b[i-1]){
			if(b[i-1]!='2')rt[ct-1]=i-1;
			if(b[i]!='2'){
				lt[++ct]=i;
				tt[ct]=(t[i]=='1');//ÑÕÉ« 
			}
		}
		s1[cs]+=(s[i]=='1');
		t1[ct]+=(t[i]=='1');
	}
	if(a[n]!='2')rt[cs]=n;
	if(b[n]!='2')rs[ct]=n;
	for(int i=1;i<=cs;++i){
		printf("%d %d %d\n",ls[i],rs[i],s1[i]);
	}
	printf("----\n");
	for(int i=1;i<=ct;++i){
		printf("%d %d %d\n",lt[i],rt[i],t1[i]);
	}
	for(int i=1,j;i<=cs;++i){
		if(ts[i]==0){
			j=lower_bound(rt+1,rt+ct+1,rs[i])-rt;
			res+=min(s1[i],t1[j]);
			t1[j]-=min(s1[i],t1[j]);
		}
	}
	for(int i=1,j;i<=ct;++i){
		if(tt[i]==0){
			j=lower_bound(rs+1,rs+cs+1,rt[i])-rs;
			res+=min(t1[i],s1[j]);
			s1[j]-=min(t1[i],s1[j]);
		}
	}
	int i=1,j=1,tmp;
	while(ts[i]==0&&i<=cs)++i;
	while(tt[j]==0&&j<=ct)++j;
	if(i<=cs&&j<=ct){
		while(1){
			tmp=min(min(s1[i],t1[j]),max(min(ls[i],lt[j])-max(rs[i],rt[j])+1,0));
			s1[i]-=tmp;
			t1[j]-=tmp;
			res+=tmp;
			if(rs[i]<=rt[j]){
				++i;
				while(ts[i]==0&&i<=cs)++i;
			}else{
				++j;
				while(tt[j]==0&&j<=ct)++j;
			}
			if(i>cs||j>ct)break;
		}
	}
	for(int i=1;i<=cs;++i)s1[i]=0;
	for(int i=1;i<=ct;++i)t1[i]=0;
	cs=ct=0;
	printf("------------\n");
	return res;
	
}
void solve(){
		for(int i=1;i<=n;++i){
			if(a[i]=='0'&&b[i]=='0'){
				ans+=(s[i]==t[i]);
				a[i]=b[i]='2';
			}
		}
		printf("%d ",ans);
		ans+=calc();
		for(int i=1;i<=n;++i){
			if(s[i]=='1')s[i]='0';
			else s[i]='1';
			if(t[i]=='1')t[i]='0';
			else t[i]='1';
		}
		ans+=calc();
		printf("%d\n",ans);
		ans=0;
}
}
namespace sub2{
	void solve(){
		int s0=0,t0=0,xs,ys,xt,yt;
		for(int i=1;i<=n;++i){
			ans+=s[i]==t[i];
			s0+=s[i]=='0';
			t0+=t[i]=='0';
		}
		if(s0==1&&t0==1){
			for(int i=1;i<=n;++i){
				if(s[i]=='0'){
					xs=ys=i;
					while(a[xs-1]=='1')--xs;
					while(a[ys+1]=='1')++ys;
					break;
				}
			}
			for(int i=1;i<=n;++i){
				if(t[i]=='0'){
					xt=yt=i;
					while(b[xt-1]=='1')--xt;
					while(b[yt+1]=='1')++yt;
					break;
				}
			}
			if(min(yt,ys)>=max(xs,xt)){
				ans=n;
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
}
namespace sub3{
	struct node{
		int l,r,cnt;
	};
	node x[N],y[N];
	int tx,ty;
	int solve(){
		int res=0,tmp;
		for(int i=1;i<=n;++i){
			if(a[i]=='0'){
				x[++tx]={i,i,s[i]=='1'};
			}else{
				if(a[i-1]!='1'){
					x[++tx]={i,i,0};
				}
				x[tx].r=i;
				x[tx].cnt+=s[i]=='1';
			}
			if(b[i]=='0'){
				y[++ty]={i,i,t[i]=='1'};
			}else{
				if(b[i-1]!='1'){
					y[++ty]={i,i,0};
				}
				y[ty].r=i;
				y[ty].cnt+=t[i]=='1';
			}
		}
//		for(int i=1;i<=tx;++i){
//			printf("%d %d %d\n",x[i].l,x[i].r,x[i].cnt);
//		}
//		printf("--\n");
//		for(int i=1;i<=ty;++i){
//			printf("%d %d %d\n",y[i].l,y[i].r,y[i].cnt);
//		}
////		printf("-------+++---\n");
		for(int i=1,j=1;i<=tx;++i){
			while(j<=ty&&y[j].r<x[i].l)++j;
			while(j<=ty&&y[j].l<=x[i].r){
				tmp=min(min(x[i].cnt,y[j].cnt),min(x[i].r,y[j].r)-max(x[i].l,y[j].l)+1);
				x[i].cnt-=tmp;
				y[j].cnt-=tmp;
				res+=tmp;
//				printf("++++++++++%d %d %d\n",i,j,tmp);
				++j;
			}
			--j;
		}
		tx=ty=0;
		return res;
	}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s%s%s%s",s+1,t+1,a+1,b+1);
//		sub2::solve();
		ans=sub3::solve();
//		printf("%d ",ans);
		for(int i=1;i<=n;++i){
			if(s[i]=='1')s[i]='0';
			else s[i]='1';
			if(t[i]=='1')t[i]='0';
			else t[i]='1';
		}
		ans+=sub3::solve();
		printf("%d\n",ans);
	}
	return 0;
}
