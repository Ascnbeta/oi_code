#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005],t1[100005],t2[100005];
int T,n,ans,sum1[100005],sum2[100005];
vector<pair<int,int> >p1,p2;

void solve(){
	scanf("%d%s%s%s%s",&n,s1+1,s2+1,t1+1,t2+1);
	ans=0;p1.clear(),p2.clear();
	for(int i=1;i<=n;++i){
		sum1[i]=sum1[i-1]+s1[i]-'0';
		sum2[i]=sum2[i-1]+s2[i]-'0';
	}
	for(int l=1,r=1;l<=n;){
		if(t1[l]=='0'){p1.push_back(make_pair(l,l));++l;continue;}
		r=l;
		while(r<n&&t1[r+1]=='1')++r;
		p1.push_back(make_pair(l,r));
		l=r+1;
	}
	for(int l=1,r=1;l<=n;){
		if(t2[l]=='0'){p2.push_back(make_pair(l,l));++l;continue;}
		r=l;
		while(r<n&&t2[r+1]=='1')++r;
		p2.push_back(make_pair(l,r));
		l=r+1;
	}
	for(int i=1,s1_0=0,s1_1=0,s2_0=0,s2_1=0,it1=0,it2=0,l,r;i<=n;++i){
		if(s1_0==0&&s1_1==0){
			l=p1[it1].first,r=p1[it1].second;it1++;
			s1_1=sum1[r]-sum1[l-1],s1_0=r-l+1-s1_1;
		}
		if(s2_0==0&&s2_1==0){
			l=p2[it2].first,r=p2[it2].second;it2++;
			s2_1=sum2[r]-sum2[l-1],s2_0=r-l+1-s2_1;
		}
		
		if(s1_0!=0&&s2_0!=0)--s1_0,--s2_0,++ans;
		else if(s1_1!=0&&s2_1!=0)--s1_1,--s2_1,++ans;
		else{
			if(s1_0!=0)--s1_0;
			if(s1_1!=0)--s1_1;
			if(s2_0!=0)--s2_0;
			if(s2_1!=0)--s2_1;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
