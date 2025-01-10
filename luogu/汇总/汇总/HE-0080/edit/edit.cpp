#include<bits/stdc++.h>

using namespace std;

int T,n;
string s1,s2;
string t1,t2;
int ans;
vector< int> ve[3];

bool A(){
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s1[i+1])return 0;
	}
	return 1;
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		cin>>s1>>s2;
		cin>>t1>>t2;
		if(A()){
			for(int i=0;i<n;i++){
				if(s1[i]==s2[i]){
					ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(s1==s2){
			ans=n;
			cout<<ans<<"\n";
			continue;
		}
		if(t1==t2){
		int cnt1_1=0,cnt0_1=0;
		int cnt1_2=0,cnt0_2=0;
			for(int i=0;i<=n;i++){
				if(t1[i]=='1'){
					if(s1[i]=='1')cnt1_1++;
					if(s1[i]=='0')cnt0_1++;
					if(s2[i]=='1')cnt1_2++;
					if(s2[i]=='0')cnt0_2++;
				}
				else{
					ans=max(ans,ans+min(cnt1_1,cnt1_2)+min(cnt0_1,cnt0_2));
					cnt1_1=0,cnt0_1=0,cnt1_2=0,cnt0_2=0;
					if(s1[i]==s2[i]&&i!=n)ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
