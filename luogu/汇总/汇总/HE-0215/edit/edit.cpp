#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,sum[4][N];
int x,y,z,l,r,k,t;
char s[5][N];
int st[3][N],tp[3];
map<int,int>mp1[2][N],mp2[2][N];
void solve(){
	cin>>n;
	for(int i=0;i<=n+2;i++){
		mp1[1][i].clear();mp1[0][i].clear();
		mp2[1][i].clear();mp2[0][i].clear();
		st[1][i]=st[2][i]=0;
	}
	tp[1]=tp[2]=0;
	for(int i=1;i<=4;i++)cin>>(s[i]+1);
	st[1][++tp[1]]=0;
	st[2][++tp[2]]=0;
	for(int k=1;k<=2;k++){
		for(int i=1;i<=n;i++){
			sum[k][i]=sum[k][i-1]+(s[k][i]=='1');
			if(s[k+2][i]=='0')st[k][++tp[k]]=i;
		}
	}
	st[1][++tp[1]]=n+1;
	st[2][++tp[2]]=n+1;
	int ans=0;
	for(int i=1;i<tp[1];i++){
		mp1[1][i][i+1]=sum[1][st[1][i+1]-1]-sum[1][st[1][i]];
		mp1[0][i][i+1]=st[1][i+1]-st[1][i]-1-mp1[1][i][i+1];
	}
	for(int i=1;i<tp[2];i++){
		mp2[1][i][i+1]=sum[2][st[2][i+1]-1]-sum[2][st[2][i]];
		mp2[0][i][i+1]=st[2][i+1]-st[2][i]-1-mp2[1][i][i+1];
	}
	for(int i=1;i<=n;i++){
		int l1=lower_bound(st[1]+1,st[1]+1+tp[1],i)-st[1]-1;
		int l2=lower_bound(st[2]+1,st[2]+1+tp[2],i)-st[2]-1;
		// if(mp1[1][l1][l1+1]<0||mp2[1][l2][l2+1]<0)cout<<"???"<<endl;
		// if(mp1[0][l1][l1+1]<0||mp2[0][l2][l2+1]<0)cout<<"???"<<endl;
		if(st[1][l1+1]==i&&st[2][l2+1]==i&&s[1][i]==s[2][i])ans++;
		else if(st[1][l1+1]==i){
			if(s[1][i]=='1'){
				if(mp2[1][l2][l2+1]>0)mp2[1][l2][l2+1]--,ans++;
				else mp2[0][l2][l2+1]--;
			}
			if(s[1][i]=='0'){
				if(mp2[0][l2][l2+1]>0)mp2[0][l2][l2+1]--,ans++;
				else mp2[1][l2][l2+1]--;
			}
		}else if(st[2][l2+1]==i){
			if(s[2][i]=='1'){
				if(mp1[1][l1][l1+1]>0)mp1[1][l1][l1+1]--,ans++;
				else mp1[0][l1][l1+1]--;
			}
			if(s[2][i]=='0'&&mp1[0][l1][l1+1]>0){
				if(mp1[0][l1][l1+1]>0)mp1[0][l1][l1+1]--,ans++;
				else mp1[1][l1][l1+1]--;
			}
		}else{
			if(mp1[1][l1][l1+1]>0&&mp2[1][l2][l2+1]>0)mp1[1][l1][l1+1]--,mp2[1][l2][l2+1]--,ans++;				
			else if(mp1[0][l1][l1+1]>0&&mp2[0][l2][l2+1]>0)mp1[0][l1][l1+1]--,mp2[0][l2][l2+1]--,ans++;
			else if(mp1[0][l1][l1+1]>0&&mp2[1][l2][l2+1]>0)mp1[0][l1][l1+1]--,mp2[1][l2][l2+1]--;
			else if(mp1[1][l1][l1+1]>0&&mp2[0][l2][l2+1]>0)mp1[1][l1][l1+1]--,mp2[0][l2][l2+1]--;
		}
		// cout<<i<<' '<<ans<<endl;
	}cout<<ans<<'\n';
}	
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
