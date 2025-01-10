#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int bl1[1000000],bl2[1000000],ss1[3],ss2[3];
int sum1[1000000][3],sum2[1000000][3];int n;
int dfs(int nw){
	if(nw>=n){
		int cnt=0;
		for(int i=1;i<=n;i++)if(s1[i]==s2[i])cnt++;
		return cnt;
	}
	int mx=dfs(nw+1);
	if(t1[nw]!='0'&&t1[nw+1]!='0'&&!(t2[nw]!='0'&&t2[nw+1]!='0')){
		swap(s1[nw],s1[nw+1]);
		mx=max(mx,dfs(nw+1));
		swap(s1[nw],s1[nw+1]);
	}
	if(t2[nw]!='0'&&t2[nw+1]!='0'&&!(t1[nw]!='0'&&t1[nw+1]!='0')){
		swap(s2[nw],s2[nw+1]);
		mx=max(mx,dfs(nw+1));
		swap(s2[nw],s2[nw+1]);
	}
	if(t2[nw]!='0'&&t2[nw+1]!='0'&&t1[nw]!='0'&&t1[nw+1]!='0'){
		swap(s2[nw],s2[nw+1]);
		swap(s1[nw],s1[nw+1]);
		mx=max(mx,dfs(nw+1));
		swap(s2[nw],s2[nw+1]);
		swap(s1[nw],s1[nw+1]);
	}
	return mx;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int ans=0,v=0,sub1=1,sub2=1,sub3=1,sub4=1;
		cin>>n;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		s1[n+1]='$';
		s2[n+1]='@';
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		int c1=0,c2=0;
		for(int i=1;i<n;i++)if(s1[i]!=s1[i+1])sub1=0;
		if(t1!=t2)sub2=0;
		for(int i=1;i<=n;i++){
			if(t1[i]=='0')c1++;
			if(t2[i]=='0')c2++;
		}
		if(c1!=c2||c1!=1)sub3=0;
		if(n<=10){
			cout<<dfs(1)<<endl;
			continue;
		}
		if(sub1){
			int ans[2]={};
			for(int i=1;i<=n;i++){
				ans[s2[i]-'0']++;
			}
			cout<<ans[s1[1]-'0']<<endl;
			continue;
		}
		if(sub2){
			int ans=0;
			ss1[0]=ss1[1]=ss2[0]=ss2[1]=0;
			for(int i=1;i<=n;i++){
				if(t1[i]!='0')ss1[s1[i]-'0']++;
				if(t2[i]!='0')ss2[s2[i]-'0']++;
				if(t1[i]=='0'){
					if(s1[i]==s2[i])ans++;
					int w0=min(ss1[0],ss2[0]),w1=min(ss1[1],ss2[1]);
					ss1[0]=ss1[1]=ss2[0]=ss2[1]=0;
					ans+=w1+w0;
				}
			}
			ans+=min(ss1[0],ss2[0])+min(ss1[1],ss2[1]);
			cout<<ans<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
