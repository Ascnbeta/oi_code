#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const long long inf=1e5;
int t,n,m,v,c,d;
long long ans;
int s[inf];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
//	cout<<"sdf"; 
	cin>>t;
	for(int icnt=1;icnt<=t;icnt++){
		ans=1;
		bool sign=0;
		memset(s,0,sizeof(s));
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&c,&d);
			if(s[c]&&s[c]!=d){
				sign=1;
				break;
			}
			s[c]=1;
		}
		if(sign==1){
			printf("0\n");
			continue; 
		}
		else{
			for(int i=1;i<n;i++){
				if(s[i]&&s[i+1]) ans*=3,ans%=mod;
				else ans*=4,ans%=mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
3
2 1 2
1 1
2 2 2
1 1 
2 2
2 2 2
1 1
1 2
*/

