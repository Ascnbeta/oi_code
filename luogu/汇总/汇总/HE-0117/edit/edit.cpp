#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int T,n,dp[maxn],cnt[3][maxn][2];
char s1[maxn],s2[maxn];
char t1[maxn],t2[maxn];
inline int query(int tp,int l,int r,bool v){return cnt[tp][r][v]-cnt[tp][l-1][v];}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof cnt);
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		cin>>(s1+1)>>(s2+1)>>(t1+1)>>(t2+1);
		for(int i=1;i<=n;i++){
			cnt[1][i][0]=cnt[1][i-1][0]+(s1[i]=='0');
			cnt[1][i][1]=cnt[1][i-1][1]+(s1[i]=='1');
			cnt[2][i][0]=cnt[2][i-1][0]+(s2[i]=='0');
			cnt[2][i][1]=cnt[2][i-1][1]+(s2[i]=='1');
		}
		int _0=min(query(1,1,n,0),query(2,1,n,0));
		int _1=min(query(1,1,n,1),query(2,1,n,1));
		dp[n]=_0+_1;
		printf("%d\n",dp[n]);
	}
	return 0;
}
