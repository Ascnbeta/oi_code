#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,s1[N],s2[N],flag=1,flag1=1,ans=0,tot=0,l[N],r[N];
char t1[N],t2[N];
int main(){
	freopen("edit.in","r",stdin);freopen("edit.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;ans=tot=0;flag=flag1=1;
		memset(l,0,sizeof(l));memset(r,0,sizeof(r));memset(s1,-1,sizeof(s1));memset(s2,-1,sizeof(s2));
		for(int i=1;i<=n;i++){char c;cin>>c;s1[i]=c-'0';if(i>1&&s1[i]!=s1[i-1])flag=0;}
		for(int i=1;i<=n;i++){char c;cin>>c;s2[i]=c-'0';}
		for(int i=1;i<=n;i++)cin>>t1[i];
		for(int i=1;i<=n;i++){cin>>t2[i];if(t1[i]!=t2[i])flag1=0;}
		if(flag){
			for(int i=1;i<=n;i++)if(s1[i]==s2[i])ans++;
			cout<<ans<<'\n' ;
			continue;
		}
		if(flag1){
			int len=1;
			for(int i=1;i<=n;i+=len){
				if(t1[i]=='1'){
					int j=i+1;len=1;
					while(t1[j]=='1'){j++;len++;}
					l[++tot]=i;r[tot]=i+len-1;
				}
				else len=1;
			}
			for(int i=1;i<=tot;i++){
				if(l[i]==r[i])continue;
				sort(s1+l[i]+1,s1+r[i]+1);
				sort(s2+l[i]+1,s2+r[i]+1);
			}
			for(int i=1;i<=n;i++){
				if(s1[i]==s2[i])ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n<=10){
			
			continue;
		}
		
	}
	return 0;
}
