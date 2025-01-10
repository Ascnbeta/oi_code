#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=100010,mod=1e9+7;
int T,n,m,v;
int x[10001000],c[N],d[N],cnt[N];

bool chk(int a,int b,int pos){
	if(x[pos]!=a) return 1;
	else if(x[pos+1]==b||x[pos+1]==0) return 1;
	else return 0;
}

void work(){
	fill(x,x+10000100,0);
	fill(cnt,cnt+100000,0);
	bool flg=0;
	
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i];
		if(x[c[i]]!=d[i]&&x[c[i]]!=0){
			flg=1;
		}
		x[c[i]]=d[i];
	}
	
	if(flg){
		cout<<0<<'\n';
		return ;
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=v;j++){
			for(int k=1;k<=v;k++){
				if(chk(j,k,i)){
					++cnt[i];
				}
			}
		}
	}
	int ans=1;
	for(int i=1;i<n;i++){
		ans*=cnt[i];
		ans%=mod;
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) work();
	
	return 0;
}
