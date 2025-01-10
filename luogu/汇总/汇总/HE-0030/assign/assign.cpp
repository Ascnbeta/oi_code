#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P=1e9+7;

inline int ksm(int a,int b){
	int ba=a,re=1;
	while(b){
		if(b&1)re*=ba,re%=P;
		ba*=ba,ba%=P;
		b>>=1;
	}
	return re;
}

int f(int l,int V){
	return (ksm(V,2*l)-ksm(V,l-1)*(V-1)%P+P+P)%P;
}

void solve(){
	unordered_map<int,int>mp;
	int n,m,v;cin>>n>>m>>v;
	vector<int>vec;
	while(m--){
		int ci,di;cin>>ci>>di;
		if(mp[ci]==0){
			vec.push_back(ci);
			mp[ci]=di;
		}
		if(mp[ci]!=di){
			cout<<'0'<<'\n';return;
		}
	}
	if(vec.size()<2){
		cout<<ksm(v,2*n-2)<<'\n';return;
	}
	sort(vec.begin(),vec.end());
	int len=vec.size();
	int ans=1;
	for(int i=1;i<len;i++)ans*=f(vec[i]-vec[i-1],v),ans%=P;
	ans*=ksm(v,2*vec[0]-2);ans%=P;
	ans*=ksm(v,2*n-2*vec[len-1]);ans%=P;
	cout<<ans<<'\n';
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;cin>>T;while(T--)solve();
}
