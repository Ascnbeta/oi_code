#include"bits/stdc++.h"
using namespace std;
const int N=1e5+10;
int T,n;
char s1[N],s2[N],s3[N],s4[N];
int ans,n1[2],n2[2];
bool ok1(){
	for(int i=1;i<n;i++){
		if(s1[i]!=s1[i+1]) return false;
	}
	return true;
}
bool ok2(){
	for(int i=1;i<=n;i++){
		if(s3[i]!=s4[i]) return false;
	}
	return true;
}
bool ok3(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++) cnt1+=(s3[i]=='0');
	for(int i=1;i<=n;i++) cnt2+=(s4[i]=='0');
	return (cnt1==1&&cnt2==1);
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=n1[0]=n1[1]=n2[0]=n2[1]=0;
		cin>>n;
		cin>>s1+1;
		cin>>s2+1;
		cin>>s3+1;
		cin>>s4+1;
		if(ok1()){
			for(int i=1;i<=n;i++){
				if(s2[i]==s1[1]) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(ok2()){
			for(int i=1;i<=n;i++){
				if(s3[i]=='0'){
					if(s1[i]==s2[i]) ans++;
					ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
					n1[0]=n1[1]=n2[0]=n2[1]=0;
				}
				else{
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
			}
			ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
			cout<<ans<<'\n';
			continue;
		}
		if(ok3()){
			int id1,id2,cnt11,cnt12,cnt21,cnt22;
			for(int i=1;i<=n;i++){
				if(s3[i]=='0') id1=i;
				if(s4[i]=='0') id2=i;
			}
			if(id1<id2){
				for(int i=1;i<=id1;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
				ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				n2[0]-=min(n1[0],n2[0]);
				n2[1]-=min(n1[1],n2[1]);
				n1[0]=n1[1]=0;
				for(int i=id1+1;i<=n;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
			    ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				cout<<ans<<'\n';
			}
			else if(id1==id2){
				for(int i=1;i<id1;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
				ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				ans+=(s1[id1]==s2[id2]);
				n2[0]=n2[1]=n1[0]=n1[1]=0;
				for(int i=id1+1;i<=n;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
			    ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				cout<<ans<<'\n';
			}
			else{
				for(int i=1;i<=id2;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
				ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				n1[0]-=min(n1[0],n2[0]);
				n1[1]-=min(n1[1],n2[1]);
				n2[0]=n2[1]=0;
				for(int i=id2+1;i<=n;i++){
					n1[s1[i]-'0']++;
					n2[s2[i]-'0']++;
				}
			    ans+=min(n1[0],n2[0])+min(n1[1],n2[1]);
				cout<<ans<<'\n';
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s3[i]=='0'&&s4[i]=='0'){
				n1[0]=n1[1]=n2[0]=n2[1]=0;
				if(s1[i]==s2[i]) ans++;
			}
			else if(s1[i]==s2[i]) ans++;
			else if(s3[i]=='0'){
				n2[0]=n2[1]=0;
				n1[s1[i]-'0']++;
				if(n1[s2[i]-'0']){
					n1[s2[i]-'0']--;
					ans++;
				}
				else{
					n2[s2[i]-'0']++;
				}
			}
			else if(s4[i]=='0'){
				n1[0]=n1[1]=0;
				n1[s2[i]-'0']++;
				if(n2[s1[i]-'0']){
					n2[s1[i]-'0']--;
					ans++;
				}
				else{
					n1[s1[i]-'0']++;
				}
			}
			else{
				if(n1[s2[i]-'0']){
					n1[s2[i]-'0']--;
					ans++;
				}
				else{
					n2[s2[i]-'0']++;
				}
				if(n2[s1[i]-'0']){
					n2[s1[i]-'0']--;
					ans++;
				}
				else{
					n1[s1[i]-'0']++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
