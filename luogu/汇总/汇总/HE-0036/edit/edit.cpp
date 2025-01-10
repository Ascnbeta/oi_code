#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+70;
int T,n,fa[3][N],sum[3][N][2],ans;
char s[3][N],t[3][N];
signed main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) cin>>s[1][i];
		for(int i=1;i<=n;i++) cin>>s[2][i];
		for(int i=1;i<=n;i++) cin>>t[1][i];
		for(int i=1;i<=n;i++) cin>>t[2][i];
		for(int id=1;id<=2;id++) {
			bool tag=0;
			for(int i=1;i<=n;i++) {
				if(t[id][i]=='1') {//¿É½»»» 
					if(tag) {
						fa[id][i]=fa[id][i-1];
					}
					else fa[id][i]=i;
					tag=1;
					sum[id][fa[id][i]][s[id][i]-'0']++;
				}
				else {
					tag=0;
					sum[id][i][s[id][i]-'0']++;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) {
			if(t[1][i]=='0'&&t[2][i]=='0') {
				ans=ans+(s[1][i]==s[2][i]);
				continue;
			}
			if(t[1][i]=='1'&&t[2][i]=='0') {
				if(sum[1][fa[1][i]][s[2][i]-'0']>0) {
					sum[1][fa[1][i]][s[2][i]-'0']--;
					ans++;
				}
				continue;
			}
			if(t[1][i]=='0'&&t[2][i]=='1') {
				if(sum[2][fa[2][i]][s[1][i]-'0']>0) {
					sum[2][fa[2][i]][s[1][i]-'0']--;
					ans++;
				}
				continue;
			}
			if(t[1][i]=='1'&&t[2][i]=='1') {
				if(sum[1][fa[1][i]][0]>0&&sum[2][fa[2][i]][0]>0) {
					sum[1][fa[1][i]][0]--;
					sum[2][fa[2][i]][0]--;
					ans++;
					continue;
				}
				if(sum[1][fa[1][i]][1]>0&&sum[2][fa[2][i]][1]>0) {
					sum[1][fa[1][i]][1]--;
					sum[2][fa[2][i]][1]--;
					ans++;
					continue;
				}
				continue;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) 
			sum[1][i][0]=sum[1][i][1]=sum[2][i][0]=sum[2][i][1]=0; 
	}
	return 0;
}
/*
1 6
011101 111010 111010 101101
*/
