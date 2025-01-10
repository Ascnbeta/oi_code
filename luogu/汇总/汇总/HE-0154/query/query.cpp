#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,t;
struct node{
	int c0,c1;
}l1[100088],l2[100088];
string s1,s2,t1,t2;
int dn1[100088],dn2[100088],vis[100088];
int chan(int i){
	if(t1[i]=='0'){
		if(s1[i]=='0'){
			if(l2[dn2[i]].c0>0){
				l2[dn2[i]].c0--; return 1;
			}
		}else{
			if(l2[dn2[i]].c1>0){
				l2[dn2[i]].c1--; return 1;
			}
		}
	}else{
		if(s2[i]=='0'){
			if(l1[dn1[i]].c0>0){
				l1[dn1[i]].c0--; return 1;
			}
		}else{
			if(l1[dn1[i]].c1>0){
				l1[dn1[i]].c1--; return 1;
			}
		}
	}
	return 0;
}
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		int ans=0,f10=0,f20=0,f11=0,f21=0;
		int cnt1=1,cnt2=1,f1=1,f2=1;
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		if(s1==s2){
			cout<<n; continue;
		}
		for(int i=1;i<=n;i++){
			l1[i].c0=0; l1[i].c1=0; dn1[i]=0;
			l2[i].c0=0; l2[i].c1=0; dn2[i]=0;
		}
		for(int i=0;i<n;i++){
			if(t1[i]=='1'){
				f1=0; dn1[i]=cnt1;
				if(s1[i]=='1') l1[cnt1].c1++;
				else l1[cnt1].c0++;
			}else if(f1==0){ 
				cnt1++;
			}
			if(t2[i]=='1'){
				f2=0; dn2[i]=cnt2;
				if(s2[i]=='1') l2[cnt2].c1++;
				else l2[cnt2].c0++;
			}else if(f2==0){ 
				cnt2++;
			}
		}
		for(int i=0;i<n;i++){
			if(s1[i]==s2[i]&&t1[i]=='0'&&t2[i]=='0'){
				ans++;
			}else{
				if(t1[i]!='0'&&t2[i]!='0'){
					vis[i]=1;
				}else{
					ans+=chan(i);
				}
			}
		}
		for(int i=0;i<n;i++){
			if(vis[i]){
				if(l1[dn1[i]].c0>0&&l2[dn2[i]].c0>0){
					ans++; l1[dn1[i]].c0--; l2[dn2[i]].c0--;
				}
				if(l1[dn1[i]].c1>0&&l2[dn2[i]].c1>0){
					ans++; l1[dn1[i]].c1--; l2[dn2[i]].c1--;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 6
011101
111010
111010
101101
*/
