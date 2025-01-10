#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,ans,n;
char s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		scanf("%s%s%s%s",s1+1,s2+1,t1+1,t2+1);
		if(t1[1]=='1'&&t1[2]=='0') t1[1]=t1[2];
		if(t2[1]=='1'&&t2[2]=='0') t2[1]=t2[2];
		if(t1[n]=='1'&&t1[n-1]=='0') t1[n]=t1[n-1];
		if(t2[n]=='1'&&t2[n-1]=='0') t2[n]=t2[n-1];
		for(int i=2;i<n;i++){
			if(t1[i]=='1'&&t1[i-1]=='0'&&t1[i+1]=='0') t1[i]=t1[i-1];
			if(t2[i]=='1'&&t2[i-1]=='0'&&t2[i+1]=='0') t2[i]=t2[i-1];
		}
		for(int i=1;i<=n;i++){
			if(s1[i]==s2[i]) continue;
			else{
				if(t1[i]=='1'&&t1[i+1]=='1'){
					swap(s1[i],s1[i+1]);
				}
				if(t1[i]=='0'||t1[i+1]=='0'){
					if(t2[i]=='1'&&t2[i+1]=='1') swap(s2[i],s2[i+1]);
					else continue;
				}
			}
		}
		for(int i=n;i>=1;i--){
			if(s1[i]==s2[i]) continue;
			else{
				if(t1[i]=='1'&&t1[i-1]=='1'){
					swap(s1[i],s1[i-1]);
				}
				if(t1[i]=='0'||t1[i-1]=='0'){
					if(t2[i]=='1'&&t2[i-1]=='1') swap(s2[i],s2[i-1]);
					else continue;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s1[i]==s2[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
