#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+1;
int T,n,ans;
string s1,s2,t1,t2;
void Main(){
	cin>>n>>s1>>s2>>t1>>t2;
	s1=" "+s1,s2=" "+s2,t1=" "+t1,t2=" "+t2;
	if(t1==t2){
		ans=n;
		for(int i=1,cnt1=0,cnt0=0;i<=n+1;i++){
			if(i==n+1){
				ans-=abs(cnt1);
				break;
			}
			if(t1[i]=='0'){
				if(s1[i]!=s2[i])
					ans--;
				ans-=abs(cnt1);
				cnt1=cnt0=0;
			}
			else{
				if(s1[i]=='1')
					cnt1++;
				else
					cnt0++;
				if(s2[i]=='1')
					cnt1--;
				else
					cnt0--;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	char ch=s1[n],f=1;
	for(int i=1;i<n;i++)
		if(s1[i]!=ch){
			f=0;
			break;
		}
	if(f){
		ans=n;
		for(int i=1;i<=n;i++)
			if(s2[i]==ch)
				continue;
			else
				ans--;
		cout<<ans<<'\n';
		return;
	}
	int p1=0,p2=0;
	for(int i=1;i<=n;i++){
		if(t1[i]=='0')
			p1=i;
		if(t2[i]=='0')
			p2=i;
	}
	ans=0;
	if(p1==p2){
		int cnt10=0,cnt11=0,cnt20=0,cnt21=0;
		ans=0;
		for(int i=1;i<p1;i++){
			if(s1[i]=='1')
				cnt11++;
			else
				cnt10++;
			if(s2[i]=='1')
				cnt21++;
			else
				cnt20++;
		}
		ans+=min(cnt10,cnt20)+min(cnt11,cnt21);
		cnt10=cnt20=cnt11=cnt21=0;
		if(s1[p1]==s2[p1])
			ans++;
		for(int i=p1+1;i<=n;i++){
			if(s1[i]=='1')
				cnt11++;
			else
				cnt10++;
			if(s2[i]=='1')
				cnt21++;
			else
				cnt20++;
		}
		ans+=min(cnt10,cnt20)+min(cnt11,cnt21);
		cout<<ans<<'\n';
		return;
	}
	pair<int,int>a,b,c,d;
	a.first=a.second=b.first=b.second=c.first=c.second=d.first=d.second=0;
	if(p1>p2)
		swap(p1,p2),swap(s1,s2);
	for(int i=1;i<p1;i++){
		if(s1[i]=='1')
			a.second++;
		else
			a.first++;
	}
	for(int i=1;i<p2;i++){
		if(s2[i]=='1')
			c.second++;
		else
			c.first++;
	}
	for(int i=p1+1;i<=n;i++){
		if(s1[i]=='1')
			b.second++;
		else
			b.first++;
	}
	for(int i=p2+1;i<=n;i++){
		if(s2[i]=='1')
			d.second++;
		else
			d.first++;
	}
	ans+=min(a.first,c.first)+min(a.second,c.second);
	a.first-=min(a.first,c.first),c.first-=min(a.first,c.first);
	a.second-=min(a.second,c.second),c.second-=min(a.second,c.second);
	ans+=min(b.first,d.first)+min(b.second,d.second);
	b.first-=min(b.first,d.first),d.first-=min(b.first,d.first);
	b.second-=min(b.second,d.second),d.second-=min(b.second,d.second);
	if(s1[p1]=='1'){
		if(c.second)
			c.second--,ans++;
	}
	else{
		if(c.first)
			c.first--,ans++;
	}
	if(s2[p2]=='1'){
		if(b.second)
			b.second--,ans++;
	}
	else{
		if(b.first)
			b.first--,ans++;
	}
	if(p1+1<=p2-1)
		ans+=min(b.first,c.first)+min(b.second,c.second);
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("edit.in","r",stdin),
	freopen("edit.out","w",stdout);
	for(cin>>T;T;--T)
		Main();
	return 0;
}
