#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n;
char s1[MAXN],s2[MAXN],t1[MAXN],t2[MAXN];
int num1[3],num2[3]; 
int ans;
void init(){
	 num1[0]=num1[1]=num2[0]=num2[1]=0;
	ans=0;
	scanf("%d%s%s%s%s",&n,s1+1,s2+1,t1+1,t2+1);
}
void solve(){
	int l1=0,l2=0,r1=0,r2=0;
	while(1){
		while(r1+1<=n&&t1[r1+1]!='0') num1[s1[r1+1]-'0']++,r1++;
		while(r2+1<=n&&t2[r2+1]!='0') num2[s2[r2+1]-'0']++,r2++;
//		printf("%d %d %d %d\n",l1,r1,l2,r2);
//		printf("----%d %d %d %d %d\n",num1[0],num1[1],num2[0],num2[1],ans);
		int L=max(l1,l2),R=min(r1,r2);
		if(R>L){
			int cnt1=min(num1[1],num2[1]),cnt0=min(num2[0],num1[0]);
			ans+=cnt1+cnt0; num1[1]-=cnt1; num2[1]-=cnt1; num1[0]-=cnt0; num2[0]-=cnt0;
		}
		if(r1<r2){
//			printf("-1\n");
			num1[0]=num1[1]=0;
//			printf("-----%d\n",num2[s1[r1+1]-'0']);
			if(r1+1<=n&&num2[s1[r1+1]-'0']!=0&&r1+1>l2) ans++,num2[s1[r1+1]-'0']--;
			r1++; l1=r1;
		}
		else if(r2<r1){
//			printf("-2");
			num2[0]=num2[1]=0;
			if(r2+1<=n&&num1[s2[r2+1]-'0']!=0&&r2+1>l1) ans++,num1[s2[r2+1]-'0']--;
			r2++; l2=r2;
		}
		else {
			num1[0]=num1[1]=num2[1]=num2[0]=0;
			if(s2[r2+1]==s1[r1+1]&&r1+1<=n) ans++;
			if(r2+1<=n) r2++,r1++,l1=r1,l2=r2;
		}
//		printf("%d\n",ans);
		if(r1==n&&r2==n) break;
	}
	printf("%d\n",ans);
}

int main(){
	
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
    	init(); solve();
	}
	return 0;
}
/*
1
6
011101
111010
111010
101101
*/
