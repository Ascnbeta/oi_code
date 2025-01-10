#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],fa[100010],fb[100010];
int tota,totb,tag[100010],cnta[100010][2],cntb[100010][2],La[100010],Ra[100010],Lb[100010],Rb[100010];
int ans,anss,tot,d[200010];
vector<int> dp[200010],f[200010];
struct node{
	int l,r,cnt[2];
}c[200010];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		char cc;
		cin>>n;
		for(int i=1;i<=n;i++){cin>>cc; a[i]=cc-'0';}
		for(int i=1;i<=n;i++){cin>>cc; b[i]=cc-'0';}
		for(int i=1;i<=n;i++){cin>>cc; fa[i]=cc-'0'; fa[i]^=1;}
		for(int i=1;i<=n;i++){cin>>cc; fb[i]=cc-'0'; fb[i]^=1;}
		for(int i=1;i<=n;i++) if(fa[i] && fb[i] && a[i]==b[i]) ans++;
		//找连续段 
		for(int i=1;i<=n;i++){
			if(fa[i]) continue;
			int j=i;
			while(j<=n && !fa[j]) j++;
			j--;
			tota++;
			La[tota]=i;
			Ra[tota]=j;
			for(int k=i;k<=j;k++) cnta[tota][a[k]]++;
			for(int k=i;k<=j;k++){
				if(!fb[k]) continue;
				if(cnta[tota][b[k]]){
					cnta[tota][b[k]]--;
					ans++;
				} 
			}
			i=j;
		}
		
		for(int i=1;i<=n;i++){
			if(fb[i]) continue;
			int j=i;
			while(j<=n && !fb[j]) j++;
			j--;
			totb++;
			Lb[totb]=i;
			Rb[totb]=j;
			for(int k=i;k<=j;k++) cntb[totb][b[k]]++;
			for(int k=i;k<=j;k++){
				if(!fa[k]) continue;
				if(cntb[totb][a[k]]){
					cntb[totb][a[k]]--;
					ans++;
				}
			}
			i=j;
		}
		
		//去除包含 
		for(int i=1,j=1;i<=tota && j<=totb;){
			if(La[i]<=Lb[j]){
				if(Rb[j]<=Ra[i]){
					ans+=min(cntb[j][0],cnta[i][0])+min(cntb[j][1],cnta[i][1]);
					cnta[i][0]-=min(cntb[j][0],cnta[i][0]);
					cnta[i][1]-=min(cntb[j][1],cnta[i][1]);
					tag[j]=1;
					j++;
				}else i++;
			}else j++;
		}
		for(int j=1;j<=totb;j++){
			if(tag[j]) continue;
			c[++tot].l=Lb[j];
			c[tot].r=Rb[j];
			c[tot].cnt[0]=cntb[j][0];
			c[tot].cnt[1]=cntb[j][1];
		}
		totb=tot;
		for(int i=1;i<=tot;i++){
			Lb[i]=c[i].l;
			Rb[i]=c[i].r;
			cntb[i][0]=c[i].cnt[0];
			cntb[i][1]=c[i].cnt[1];
		}
		memset(tag,0,sizeof(tag));
		
		for(int i=1,j=1;i<=totb && j<=tota;){
			if(Lb[i]<=La[j]){
				if(Ra[j]<=Rb[i]){
					ans+=min(cnta[j][0],cntb[i][0])+min(cnta[j][1],cntb[i][1]);
					c[i].cnt[0]-=min(cnta[j][0],cntb[i][0]);
					cntb[i][0]-=min(cnta[j][0],cntb[i][0]);
					c[i].cnt[1]-=min(cnta[j][1],cntb[i][1]);
					cntb[i][1]-=min(cnta[j][1],cntb[i][1]);
					tag[j]=1;
					j++;
				}else i++;
			}else j++;
		}
		for(int j=1;j<=tota;j++){
			if(tag[j]) continue;
			c[++tot].l=La[j];
			c[tot].r=Ra[j];
			c[tot].cnt[0]=cnta[j][0];
			c[tot].cnt[1]=cnta[j][1];
		}
		
		sort(c+1,c+tot+1,cmp);
	//	for(int i=1;i<=tot;i++){
	//		cout<<c[i].l<<' '<<c[i].r<<' '<<c[i].cnt[0]<<' '<<c[i].cnt[1]<<endl;
	//	}
	//	cout<<ans<<endl;
		dp[0].push_back(0);
		for(int i=1;i<=tot;i++){
			dp[i].push_back(0);
			f[i].push_back(0);
			if(c[i].l<=c[i-1].r){
				d[i]=c[i-1].r-c[i].l+1;
				for(int j=1;j<=d[i];j++) dp[i].push_back(0);
				for(int j=1;j<=d[i];j++) f[i].push_back(0); 
				for(int j=0;j<=d[i];j++){
					if(j>c[i].cnt[0] || j>c[i-1].cnt[0]) break;
					int x=min(d[i-1],min(c[i-2].cnt[0],c[i-1].cnt[0]-j));
					int y=min(d[i]-j,min(c[i].cnt[1],c[i-1].cnt[1]-f[i-1][x]));
					dp[i][j]=max(dp[i][j],dp[i-1][x]+j+y);
					f[i][j]=y;
				//	if(i<=10) cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<f[i][j]<<endl;
				}
			}else for(int j=0;j<=d[i-1];j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
		}
		for(int i=0;i<=d[tot];i++) anss=max(anss,dp[tot][i]);
		cout<<ans+anss<<endl;
		
		
		memset(tag,0,sizeof(tag));
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		memset(La,0,sizeof(La));
		memset(Ra,0,sizeof(Ra));
		memset(Lb,0,sizeof(Lb));
		memset(Rb,0,sizeof(Rb));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		for(int i=0;i<=n;i++){
			dp[i].clear();
			f[i].clear();
		}
		tot=tota=totb=0;
		ans=anss=0;
	}
	
	return 0;
}
