#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T;
int n,ans;
int sum1[2],sum2[2];
string s1,s2;
string t1,t2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=sum1[0]=sum1[1]=sum2[0]=sum2[1]=0;
		cin>>n>>s1>>s2>>t1>>t2;
		s1=' '+s1+'?';s2=' '+s2+'!';
		t1=' '+t1;t2=' '+t2;
		int lsti=-1e9,lstj=-1e9;
		for(int i=1,j=1;i<=n||j<=n;){
			while(i<=n&&t1[i]=='1'){
				sum1[s1[i]-'0']++;
				i++;
			}
			while(j<=n&&t2[j]=='1'){
				sum2[s2[j]-'0']++;
				j++;
			}
			int minn=min(j-lsti-1,i-lstj-1);
			int d0=min({sum1[0],sum2[0],minn});
			int d1=min({sum1[1],sum2[1],minn-d0});
			ans+=d0+d1;
			sum1[0]-=d0;sum2[0]-=d0;
			sum1[1]-=d1;sum2[1]-=d1;
			if(i==j){
				ans+=(s1[i]==s2[j]);
				lsti=i;lstj=j;
				i++;j++;
				sum1[0]=sum2[0]=sum1[1]=sum2[1]=0;
			}
			else if(i<j){
				int now=s1[i]-'0';
				if(sum2[now]){
					sum2[now]--;
					ans++;
				}
				lsti=i;
				i++;
				sum1[0]=sum1[1]=0;
			}
			else{
				int now=s2[j]-'0';
				if(sum1[now]){
					sum1[now]--;
					ans++;
				}
				lstj=j;
				j++;
				sum2[0]=sum2[1]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
5
10100
01011
10110
00110
*/
