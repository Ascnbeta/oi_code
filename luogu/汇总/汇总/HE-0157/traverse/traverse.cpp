#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
		clear();
		scanf("%d",&n);
		cin>>s1+1>>s2+1>>t1+1>>t2+1;
		bool flag_0=0,flag_1=0;
		for(int i=1;i<=n;i++){
			if(s1[i]=='0') flag_0=1;
			if(s1[i]=='1') flag_1=1;
		}
		if(flag_0&&!flag_1){//all 1
			for(int i=1;i<=n;i++){
				if(s2[i]=='0') ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		if(!flag_0&&flag_1){//all 0
			for(int i=1;i<=n;i++){
				if(s2[i]=='1') ans++;
			}
			printf("%d\n",ans);
			continue;
		}
	return 0;
}
