#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7; 

int T,n,m,v,ans;
int f[1000100];
map<int ,int > mp;

int quick(int a,int b) {
	int w=1;
	while(b) {
		if(b&1) w=w*a%P;
		a=a*a%P;b>>=1;
	}
	return w;
}


signed main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--) {int tot=0;
		cin>>n>>m>>v;bool flg=0;
		mp.clear();
		ans=0;
		for(int i=1,c,d;i<=m;i++) {
			scanf("%lld %lld",&c,&d);
			if(!mp[c]) f[++tot]=c;
			if(mp[c]&&mp[c]!=d) flg=1;
			else mp[c]=d;
			f[i]=c;
//			f[c]=d;
		}
		if(flg) { cout<<0<<endl;continue; }
		sort(f+1,f+1+tot); 
		if(m==n) {
			int sum=1;
			for(int i=1;i<n;i++) {
				sum=(sum+sum*v%P*(v-1))%P;
			}
			cout<<sum<<endl;
		}
		else if(m==1) {
//				int sum=1;
//				if(n>1e7) { cout<<0<<endl;continue; }
//				for(int i=1;i<n;i++) {
//					sum=(sum*v%P*v)%P;
//				}
				cout<<quick(v*v%P,n-1)<<endl;
		}
		else {
			int sum=1;
			for(int i=1;i<=tot;i++) {
				sum=(sum*quick(v*v%P,f[i]-f[i-1]-1))%P;
				if(f[i]==n) continue;
				if(f[i+1]==f[i]+1) sum=(sum+sum*v%P*(v-1))%P;
				else sum=sum*v%P*v%P;
			}
			if(f[tot]<n-1) sum=(sum*quick(v*v%P,n-f[tot]-1))%P;
			cout<<sum<<endl;
		}
	}
	return 0;
} 
