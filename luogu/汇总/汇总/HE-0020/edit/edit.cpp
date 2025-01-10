#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int T,n,num1[2],num2[2],ans;
char s1[N],s2[N],t1[N],t2[N];

inline void solve(){
	if(num1[0]>=num2[0]){
		ans+=num2[0];
		num1[0]-=num2[0];num2[0]=0;
	}
	else {
		ans+=num1[0];
		num2[0]-=num1[0];num1[0]=0;
	}
	if(num1[1]>=num2[1]){
		ans+=num2[1];
		num1[1]-=num2[1];num2[1]=0;
	}
	else {
		ans+=num1[1];
		num2[1]-=num1[1];num1[1]=0;
	}
	if(num1[0]&&num2[1]){
		if(num1[0]>=num2[1])num1[0]-=num2[1],num2[1]=0;
		else num2[1]-=num1[0],num1[0]=0;
	}
	if(num1[1]&&num2[0]){
		if(num1[1]>=num2[0])num1[1]-=num2[0],num2[0]=0;
		else num2[0]-=num1[1],num1[1]=0;
	}
}
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		scanf("%s",t1+1);t1[n+1]='0';
		scanf("%s",t2+1);t2[n+1]='0';
		int i=1,j=1;
		while(t1[i]!='0'&&i<=n)num1[s1[i++]-'0']++;
		while(t2[j]!='0'&&j<=n)num2[s2[j++]-'0']++;
		while(i<=n||j<=n){
			if(i>j){
				num2[s2[j]-'0']++;
			}
			if(i<j){
				num1[s1[i]-'0']++;
			}
			solve();
			if(i==j){
				if(s1[i]==s2[j])ans++;
				i++;j++;
				while(t1[i]!='0'&&i<=n)num1[s1[i++]-'0']++;
				while(t2[j]!='0'&&j<=n)num2[s2[j++]-'0']++;
			}
			else if(i>j){
				j++;
				while(t2[j]!='0'&&j<=n)num2[s2[j++]-'0']++;
			}
			else {
				i++;
				while(t1[i]!='0'&&i<=n)num1[s1[i++]-'0']++;
			}
		}
		solve();
		printf("%d\n",ans);
	}
}
