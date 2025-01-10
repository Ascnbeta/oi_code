#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T,n,r1[N],r2[N],sum1[N],sum2[N],ans,sum3[N],sum4[N];
string s1,s2,t1,t2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		ans=0;
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		memset(sum3,0,sizeof sum3);
		memset(sum4,0,sizeof sum4);
		cin>>n>>s1>>s2>>t1>>t2;
		s1='0'+s1; s2='0'+s2; t1='0'+t1; t2='0'+t2;
		r1[n]=r2[n]=n;
		for(int i=n-1;i>=1;--i){
			if(t1[i]=='1') r1[i]=r1[i+1];
			else r1[i]=i;
			if(t2[i]=='1') r2[i]=r2[i+1];
			else r2[i]=i;
		}
		for(int i=1;i<=n;++i){
			if(s1[i]=='0') ++sum3[r1[i]];
			else ++sum1[r1[i]];
			if(s2[i]=='0') ++sum4[r2[i]];
			else ++sum2[r2[i]];
		}
		int last=0,k1,k2,k3,k4;
		for(int i=1;i<=n;++i){
			if((t1[i]=='0'&&t2[i]=='0')){
				k1=sum1[i]-(s1[i]=='1');
				k2=sum2[i]-(s2[i]=='1');
				k3=sum3[i]-(s1[i]=='0');
				k4=sum4[i]-(s2[i]=='0');
				ans+=min(k1,k2)+min(k3,k4);
				if(s1[i]==s2[i]) ++ans;
				//cout<<i<<" "<<ans<<endl;
				last=i;
			}
			else if(t1[i]=='0'){
				k1=sum1[i];
				k3=sum3[i];
				k2=sum2[r2[i]]-(s2[r2[i]]=='1');
				k4=sum4[r2[i]]-(s2[r2[i]]=='0');
				if(i==n) {
					k2+=(s2[i]=='1');
					k4+=(s2[i]=='0');
				}
				//cout<<sum1[last]<<" "<<sum2[last]<<" "<<k1<<" "<<k2<<" "<<i<<"\n";
				ans+=min(k1,k2)+min(k3,k4);
				sum2[i]-=min(k1,k2);
				sum4[i]-=min(k3,k4);
				last=i;
				//cout<<i<<" "<<ans<<endl;
			}
			else if(t2[i]=='0'){
				k1=sum1[r1[i]]-(s1[r1[i]]=='1');
				k3=sum3[r1[i]]-(s1[r1[i]]=='0');
				k2=sum2[i];
				k4=sum4[i];
				if(i==n) {
					k1+=(s1[i]=='1');
					k3+=(s1[i]=='0');
				}
				//cout<<sum1[last]<<" "<<sum2[last]<<" "<<k1<<" "<<k2<<" "<<i<<"\n";
				ans+=min(k1,k2)+min(k3,k4);
				sum1[r1[i]]-=min(k1,k2);
				sum3[r1[i]]-=min(k3,k4);
				//cout<<i<<" "<<ans<<endl;
				last=i;
			}
			else if(i==n){
				k1=sum1[i];
				k2=sum2[i];
				k3=sum3[i];
				k4=sum4[i];
				ans+=min(k1,k2)+min(k3,k4);
				//cout<<i<<" "<<ans<<endl;
				last=i;
			}
		}
		cout<<ans<<"\n";
	}
	cout<<endl;
	return 0;
}
/*
1
6
011101
111010
111010
101101
*/

