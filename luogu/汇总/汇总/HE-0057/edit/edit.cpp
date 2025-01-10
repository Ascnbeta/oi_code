#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
char s1[N],s2[N],t1[N],t2[N];
int ans=0,t,n,a1[N],a2[N],next1[N],next2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		cin>>(s1+1)>>(s2+1)>>(t1+1)>>(t2+1);
		next1[n]=next2[n]=n;
		for(int i=n-1;i>=1;i--){
			if(t1[i]=='0')
			next1[i]=i;
			else{
				if(t1[i+1]=='0')
				next1[i]=i;
				else
				next1[i]=next1[i+1];
			}
		}
		for(int i=n-1;i>=1;i--){
			if(t2[i]=='0')
			next2[i]=i;
			else{
				if(t2[i+1]=='0')
				next2[i]=i;
				else
				next2[i]=next2[i+1];
			}
		}
		int l1=1,i,j,l2=1,cnt10=0,cnt11=0,cnt20=0,cnt21=0;
		while(1){
			for(i=l1;i<=next1[l1];i++){
				if(s1[i]=='0')
				cnt10++;
				else
				cnt11++;
			}
			l1=next1[l1];
			int ss1=min(cnt11,cnt21),ss0=min(cnt20,cnt10);
			ans+=ss1+ss0;
		//	cout<<cnt10<<" "<<cnt11<<" "<<cnt21<<" "<<cnt21<<'\n';
			cnt10-=ss0;
			cnt11-=ss1;
			cnt20-=ss0;
			cnt21-=ss1;
			while(l2<=l1&&l2<=n){
				for(i=l2;i<=next2[l2];i++){
					if(s2[i]=='0')
					cnt20++;
					else
					cnt21++;
				}
				int sh0=min(cnt10,cnt20),sh1=min(cnt21,cnt11);
				ans+=sh0+sh1;
				cnt10-=sh0,cnt11-=sh1;
				cnt21-=sh1;
				cnt20-=sh0;
				if(next2[l2]<=l1){
					cnt21=0,cnt20=0;
				}
				else{
					l2=next2[l2]+1;
					break;
				}
				l2=next2[l2]+1;		
			}
			l1++;
			if(l1>n)
			break;
			cnt11=0;cnt10=0;		
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
