#include<bits/stdc++.h>
using namespace std;
#define int long long

int T,n;
string s1,s2,t1,t2;

void work(){
	cin>>n;
	cin>>s1>>s2;
	cin>>t1>>t2;
	
	bool flg=1;
	for(int i=0;i<n-1;i++){
		if(s1[i]!=s1[i+1]){
			flg=0;
			break;
		}
	}
	
	if(flg){
		int ans=0;
		for(int i=0;i<n;i++){
			if(s2[i]==s1[0]) ++ans;
		}
		cout<<ans<<'\n';
	}else if(t1==t2){
		int ans=0,c10=0,c11=0,c20=0,c21=0;
		for(int i=0;i<n;i++){
			if(t1[i]=='0'){
				ans+=min(c10,c20)+min(c11,c21);
				c10=0,c11=0,c20=0,c21=0;
				if(s1[i]==s2[i]) ++ans;
				continue;
			}
			s1[i]=='1'?++c11:++c10;
			s2[i]=='1'?++c21:++c20;
		}
		ans+=min(c10,c20)+min(c11,c21);
		cout<<ans<<'\n';
	}else{
		int ans=0;
		int pos1=-1,pos2=-1;
		int c10=0,c11=0,c20=0,c21=0;
		int p10=0,p11=0,p20=0,p21=0;
		for(int i=0;i<n;i++){
			if(t1[i]=='0'){
				if(c11<0) ans+=c11;
				if(c10<0) ans+=c10;
				if(p20||p21){
					int mn0=min(p20,c10),mn1=min(p21,c11);
					int pos=i-pos2-1;
					if(mn0+mn1<pos){
						ans+=mn0+mn1;
						p20-=mn0,c10-=mn0;
						p21-=mn1,c11-=mn1;
					}else{
						ans+=pos;
						p20-=pos,c10-=pos;
						p21-=pos,c11-=pos;
					}
					
				}
				pos1=i;
				p10=c10,p11=c11;
				c10=0,c11=0;
				
				if(t2[i]=='1'){
					s2[i]=='1'?++c21:++c20;
					s1[i]=='1'?--c21:--c20;
					++ans;
				}else{
					if(s1[i]==s2[i]) ++ans;
				}
				continue;
			}
			if(t2[i]=='0'){
				if(c21<0) ans+=c21;
				if(c20<0) ans+=c20;
				if(p10||p11){
					int mn0=min(p10,c20),mn1=min(p11,c21);
					int pos=i-pos1-1;
					if(mn0+mn1<pos){
						ans+=mn0+mn1;
						p10-=mn0,c20-=mn0;
						p11-=mn1,c21-=mn1;
					}else{
						ans+=pos;
						p10-=pos,c20-=pos;
						p11-=pos,c21-=pos;
					}
				}
				pos2=i;
				p20=c20,p21=c21;
				c20=0,c21=0;
				
				if(t1[i]=='1'){
					s1[i]=='1'?++c11:++c10;
					s2[i]=='1'?--c11:--c10;
					++ans;
				}else{
					if(s1[i]==s2[i]) ++ans;
				}
				continue;
			}
			s1[i]=='1'?++c11:++c10;
			s2[i]=='1'?++c21:++c20;
		}
		if(p20||p21){
					int mn0=min(p20,c10),mn1=min(p21,c11);
					int pos=n-pos2-1;
					if(mn0+mn1<pos){
						ans+=mn0+mn1;
						p20-=mn0,c10-=mn0;
						p21-=mn1,c11-=mn1;
					}else{
						ans+=pos;
						p20-=pos,c10-=pos;
						p21-=pos,c11-=pos;
					}
					
				}
		if(p10||p11){
					int mn0=min(p10,c20),mn1=min(p11,c21);
					int pos=n-pos1-1;
					if(mn0+mn1<pos){
						ans+=mn0+mn1;
						p10-=mn0,c20-=mn0;
						p11-=mn1,c21-=mn1;
					}else{
						ans+=pos;
						p10-=pos,c20-=pos;
						p11-=pos,c21-=pos;
					}
				}
//		ans+=min(c10,c20)+min(c11,c21);
		cout<<ans+1<<'\n';
	}
}

signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) work();
	
	return 0;
}
