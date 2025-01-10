#include"bits/stdc++.h"
#define re register
#define int long long
using namespace std;
const int maxn=1e5+10;
int n;
char s1[maxn],s2[maxn];
char t1[maxn],t2[maxn];
inline void solve1(){
	int cnt0=0,cnt1=0;
	for(re int i=1;i<=n;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
	}
	if(cnt0==n){
		cnt0=0;
		for(re int i=1;i<=n;++i) cnt0+=(s2[i]=='0');
		cout<<cnt0<<'\n';
	}
	else{
		cnt1=0;
		for(re int i=1;i<=n;++i) cnt1+=(s2[i]=='1');
		cout<<cnt1<<'\n';
	}
}
inline void solve2(){
	int l=1,ans=0;
	for(re int i=1;i<=n;++i){
		if(t1[i]=='0'){
			int cnt0=0,cnt1=0;
			int cntt0=0,cntt1=0;
			for(re int j=l;j<=i-1;++j){
				cnt0+=(s1[j]=='0');
				cnt1+=(s1[j]=='1');
				cntt0+=(s2[j]=='0');
				cntt1+=(s2[j]=='1');
			}
			ans+=min(cnt0,cntt0)+min(cnt1,cntt1);
			if(s1[i]==s2[i]) ++ans;
			l=i+1;
		}
	}
	int cnt0=0,cnt1=0;
	int cntt0=0,cntt1=0;
	for(re int i=l;i<=n-1;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
		cntt0+=(s2[i]=='0');
		cntt1+=(s2[i]=='1');
	}
	ans+=min(cnt0,cntt0)+min(cnt1,cntt1);
	if(s1[n]==s2[n]) ++ans;
	cout<<ans<<'\n';
}
inline void solve3(){
	int id1=0,id2=0;
	for(re int i=1;i<=n;++i){
		if(t1[i]=='0') id1=i;
		if(t2[i]=='0') id2=i;
	}
	int pos1=min(id1,id2),pos2=max(id1,id2);
	int ans=0;
	int cnt0=0,cnt1=0;
	int cntt0=0,cntt1=0;
	if(id1>id2) swap(s1,s2);
	cnt0=0,cnt1=0;
	for(re int i=1;i<pos1;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
	}
	cntt0=0,cntt1=0;
	for(re int i=1;i<pos2;++i){
		cntt0+=(s2[i]=='0');
		cntt1+=(s2[i]=='1');
	}
	if(cnt0<=cntt0){
		ans+=cnt0,cntt0-=cnt0;
		if(cnt1<=cntt1) ans+=cnt1,cntt1-=cnt1;
		else ans+=cntt1,cntt1=0,cntt0=max(0ll,cntt0-(cnt1-cntt1));
	}
	else{
		ans+=cntt0,cntt0=0,cntt1=max(0ll,cntt1-(cnt0-cntt0));
		if(cnt1<=cntt1) ans+=cnt1,cntt1-=cnt1;
		else ans+=cntt1,cntt1=0,cntt0=max(0ll,cntt0-(cnt1-cntt1));
	}
	if(s1[pos1]=='0'){
		if(cntt0>=1) ++ans,--cntt0;
		else --cntt1;
	}
	if(s1[pos1]=='1'){
		if(cntt1>=1) ++ans,--cntt1;
		else --cntt0;
	}
	cnt0=0,cnt1=0;
	for(re int i=pos1+1;i<=n;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
	}
	if(cntt0<=cnt0) ans+=cntt0,cnt0-=cntt0;
	else ans+=cnt0,cnt0=0;
	if(cntt1<=cnt1) ans+=cntt1,cnt1-=cntt1;
	else ans+=cnt1,cnt1=0;
	if(s2[pos2]=='0'){
		if(cnt0>=1) ++ans,--cnt0;
		else --cnt1;
	}
	if(s2[pos2]=='1'){
		if(cnt1>=1) ++ans,--cnt1;
		else --cnt0;
	}
	cntt0=0,cntt1=0;
	for(re int i=pos2+1;i<=n;++i){
		cntt0+=(s2[i]=='0');
		cntt1+=(s2[i]=='1');
	}
	ans+=min(cnt0,cntt0)+min(cnt1,cntt1);
	cout<<ans<<'\n';
}
inline void solve4(){
	int cnt0=0,cnt1=0;
	int cntt0=0,cntt1=0;
	for(re int i=1;i<=n;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
		cntt0+=(s2[i]=='0');
		cntt1+=(s2[i]=='1');
	}
	cout<<min(cnt0,cntt0)+min(cnt1,cntt1)<<'\n';
}
inline void solve(){
	cin>>n>>(s1+1)>>(s2+1)>>(t1+1)>>(t2+1);
	bool flag=1;
	int cnt0=0,cnt1=0;
	int cntt0=0,cntt1=0;
	int tot1=0,tot2=0;
	for(re int i=1;i<=n;++i){
		cnt0+=(s1[i]=='0');
		cnt1+=(s1[i]=='1');
		if(t1[i]!=t2[i]) flag=0;
		tot1+=(t1[i]=='0');
		tot2+=(t2[i]=='0');
	}
	if(cnt0==n||cnt1==n) solve1();
	else if(flag) solve2();
	else if(tot1==1&&tot2==1) solve3();
	else solve4();
}
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;while(T--) solve();
	return 0;
}

