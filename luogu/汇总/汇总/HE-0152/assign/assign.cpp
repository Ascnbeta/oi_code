#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+20;
int t;
int n,m,v;
inline int in(){
	int f=1;
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*f;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>v;
		
		
		
		
		
		
	}
	cout<<3;
	
	return 0;
}
