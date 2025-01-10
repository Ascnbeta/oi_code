#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;

int n,T;
string s1,s2,t1,t2;
int tag1[N],tag2[N],a[N],b[N];
int ans;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		cin>>s1>>s2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			tag1[i]=t1[i-1]-'0';
			a[i]=a[i-1]+s1[i-1]-'0';
		}
		for(int i=1;i<=n;i++){
			tag2[i]=t2[i-1]-'0';
			b[i]=b[i-1]+s2[i-1]-'0';
		}
		tag1[n+1]=tag2[n+1]=a[n+1]=b[n+1]=0;
		if(a[n]==0||a[n]==n){
			if(a[n]==0) cout<<n-b[n]<<'\n';
			else cout<<b[n]<<'\n';
			continue;
		}
		if(t1==t2){
			int last=0;
			for(int i=1;i<=n+1;i++){
				if(!tag1[i]){
					int aa=a[i-1]-a[last];
					int bb=b[i-1]-b[last];
					ans+=min(aa,bb)+min(i-1-last-aa,i-1-last-bb);
					if(i<=n) ans+=(s1[i-1]==s2[i-1]);
					last=i;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(a[n]==n-1&&b[n]==n-1){
			int last1,last2,flagg1,flagg2;
			last1=last2=0;
			for(int i=1;i<=n;i++){
				if(s1[i-1]=='0') last1=i;
				if(s2[i-1]=='0') last2=i;
			}
			if(last1==last2){
				cout<<n<<"\n";
			}
			else if(last1<last2){
				flagg1=last2,flagg2=last1;
				for(int i=last1;i<=last2;i++){
					if(flagg1==last2&&!tag1[i]) flagg1=i;
					if(!tag2[i]) flagg2=i;
				}
				cout<<n-(flagg1<=flagg2+1)<<'\n';
			}
			else{
				flagg1=last2,flagg2=last1;
				for(int i=last2;i<=last1;i++){
					if(flagg2==last1&&!tag2[i]) flagg2=i;
					if(!tag1[i]) flagg1=i;
				}
				cout<<n-(flagg1>=flagg2-1)*2<<'\n';
			}
			continue;
		}
	}
	return 0;
}
