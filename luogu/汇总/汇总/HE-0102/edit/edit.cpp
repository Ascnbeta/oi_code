#include<bits/stdc++.h>
using namespace std;
//如果某一极大段上两串都固定，直接统计，否则 ，若可换部分有交，分开统计 ，反之直接统计。 
const int N=1e5+10;
char a[N],b[N],t[N],tl[N];
int tot,l[N],r[N],n,T,ll[N],rr[N],totl,cnt[N][2],cntl[N][2],ans;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>a+1>>b+1>>t+1>>tl+1; 
		tot=totl=ans=0;
		memset(cnt,0,sizeof cnt);
		memset(cntl,0,sizeof cntl);
		for(int i=1;i<=n;i++){
			if(t[i]=='1'){
				l[++tot]=i;
				while(t[i+1]=='1')i++; 
				r[tot]=i;
				if(l[tot]==r[tot])r[tot]=l[tot]=0,tot--;
				else{
					for(int j=l[tot];j<=r[tot];j++)
						cnt[tot][a[j]-'0']++;
				}
			}
			while(t[i+1]=='0'&&i<=n)i++;
		}
		for(int i=1;i<=n;i++){
			if(tl[i]=='1'){
				ll[++totl]=i;
				while(tl[i+1]=='1')i++;
				rr[totl]=i;
				if(ll[totl]==rr[totl])rr[totl]=ll[totl]=0,totl--;
				else{
					for(int j=ll[totl];j<=rr[totl];j++)
						cntl[totl][b[j]-'0']++;
				}
			}
			while(tl[i+1]=='0'&&i<=n)i++;
		}
		l[tot+1]=1e8;ll[totl+1]=1e8;
		int pos=1,posl=1,rpos=1;
		for(int lpos=1;lpos<=n;lpos=rpos+1){
			rpos=lpos;
			if(lpos>=l[pos]&&lpos<=r[pos]&&lpos>=ll[posl]&&lpos<=rr[posl]){
				int op1=min(cnt[pos][1],cntl[posl][1]);
				ans+=op1;
				cnt[pos][1]-=op1;
				cntl[posl][1]-=op1;
				
				int op0=min(cnt[pos][0],cntl[posl][0]);
				ans+=op0;
				cnt[pos][0]-=op0;
				cntl[posl][0]-=op0;
				if(cnt[pos][0]+cnt[pos][1]>cntl[posl][0]+cntl[posl][1]){
					if(cntl[posl][0])cnt[pos][1]-=cntl[posl][0];
					if(cntl[posl][1])cnt[pos][0]-=cntl[posl][1];
				}else{
					if(cnt[pos][0])cntl[posl][1]-=cnt[pos][0];
					if(cnt[pos][1])cntl[posl][0]-=cnt[pos][1];
				}
				if(r[pos]>rr[posl])rpos=rr[posl],posl++;
				else if(r[pos]<rr[posl])rpos=r[pos],pos++;
				else rpos=r[pos],pos++,posl++;
			}else if(lpos>=l[pos]&&lpos<=r[pos]){
				int op0=b[rpos]=='0',op1=b[rpos]=='1';
				while(rpos+1<ll[posl]&&rpos<r[pos]){
					rpos++;
					if(b[rpos]=='1')op1++;
					else op0++;
				}int delta=0;
				if(op1>cnt[pos][1])delta=op1-cnt[pos][1];
				op1=min(op1,cnt[pos][1]);
				cnt[pos][1]-=op1;
				ans+=op1;
				cnt[pos][0]-=op1;
				delta=0;
				if(op0>cnt[pos][0])delta=op0-cnt[pos][0];
				op0=min(op0,cnt[pos][0]);
				cnt[pos][0]-=op0;
				ans+=op0; 
				cnt[pos][1]-=delta;
				if(rpos==r[pos])pos++;
			}else if(lpos>=ll[posl]&&lpos<=rr[posl]){
				int op0=a[rpos]=='0',op1=a[rpos]=='1';
				while(rpos+1<l[pos]&&rpos<rr[posl]){
					rpos++;
					if(a[rpos]=='1')op1++;
					else op0++;
				}
				int delta=0;
				if(op1>cntl[posl][1])delta=op1-cntl[posl][1];
				op1=min(op1,cntl[posl][1]);
				cntl[posl][1]-=op1;
				ans+=op1;
				cntl[posl][0]-=delta;
				delta=0;
				if(op0>cntl[posl][0])delta=op0-cntl[posl][0];
				op0=min(op0,cntl[posl][0]);
				cntl[posl][0]-=op0;
				ans+=op0; 
				cntl[posl][1]-=delta;
				if(rpos==rr[posl])posl++;
			}else{
				int up=min(ll[posl]-1,l[pos]-1);
				up=min(up,n);
				for(;rpos<=up;rpos++){
					if(a[rpos]==b[rpos])ans++;
				}rpos--;
			}
		} 
		cout<<ans<<'\n';
	}
}

/*
1
10
0110111100
1111111100
1110000100
0110111011

8
*/
