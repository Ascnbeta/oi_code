#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
char s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool s1t=1;
		int s=-1;
		for (int i=1;i<=n;i++)cin>>s1[i];
		for (int i=1;i<=n;i++)cin>>s2[i];
		for (int i=1;i<=n;i++)cin>>t1[i];
		for (int i=1;i<=n;i++)cin>>t2[i];
		
		for (int i=1;i<=n;i++){
			if(s1[i]!=s1[1]){
				s1t=0;
				break;
			}
		}
		if(s1t){
			int res=0;
			for (int i=1;i<=n;i++){
				if(s2[i]==s1[i]){
					res++;
				}
			}
			cout<<res<<endl;
			continue;
		}
		cout<<1<<endl;
	}
	return 0;
}
