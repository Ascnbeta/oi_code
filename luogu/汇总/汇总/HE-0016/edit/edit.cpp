#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char a[N],b[N];
char aa[N],bb[N];
int ans;
int c1[2],c2[2];
void solve(){
	
	int p1=1,p2=1;
	c1[0]=c1[1]=c2[0]=c2[1]=0;
	int q1=0,q2=0;
	while(1){
		if(p1>q1){
			q1=p1;
			if(aa[q1]=='1') while(aa[q1+1]=='1') q1++;
			for(int i=p1;i<=q1;i++) c1[a[i]-'0']++;
		}
		if(p2>q2){
			q2=p2;
			if(bb[q2]=='1') while(bb[q2+1]=='1') q2++;
			for(int i=p2;i<=q2;i++) c2[b[i]-'0']++;
		}
		if(c1[0]&&c2[0]) ans++,c1[0]--,c2[0]--;
		else if(c1[1]&&c2[1]) ans++,c1[1]--,c2[1]--;
		else if(c1[0]&&c2[1]) c1[0]--,c2[1]--;
		else if(c1[1]&&c2[0]) c1[1]--,c2[0]--;
		else assert(0);
		p1++,p2++;
//		cerr<<p1<<' '<<q1<<' '<<p2<<' '<<q2<<'\n';
		if(p1>n||p2>n) break;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;cin>>T;
	while(T--){
		ans=0;
		cin>>n>>(a+1)>>(b+1)>>(aa+1)>>(bb+1);
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
