#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T;
char s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s%s%s",&n,s1+1,s2+1,t1+1,t2+1);
		int l1=1,r1=1,l2=1,r2=1,n11=0,n21=0,n10=0,n20=0,res=0;
		bool falg1=true,falg2=true,flag=true;
		while(r1<=n||r2<=n||l1<=n||l2<=n){
			while(t1[r1]-'0'==1&&r1<n){
				if(s1[r1++]-'0'==1) n11++;
				else n10++;
			}
			while(t2[r2]-'0'==1&&r2<n){
				if(s2[r2++]-'0'==1) n21++;
				else n20++;
			}
			if(r1==r2){
				if((s1[r1]=='0'&&s2[r2]=='0')||(s1[r1]=='1'&&s2[r2]=='1')) res++;
				res+=min(n10,n20)+min(n11,n21);
				l1=r1=l2=++r2;
				n10=n11=n20=n21=0;
			}
			else if(r1>r2){//1为长串
				if(falg1&&r1==n&&t1[r1]=='1'){
					if(s1[r1]-'0'==1) n11++;
					else n10++; 
					falg1=false;
				}
				if(s2[r2]-'0'==1) n21++;
				else n20++; 
				res+=min(n10,n20)+min(n11,n21);
				n10=max(0,n10-n20);
				n11=max(0,n11-n21);
				n20=n21=0;
				l1=l2=++r2;
			}
			else{//2为长串
				if(falg2&&r2==n&&t2[r2]=='1'){
					if(s2[r2]-'0'==1) n21++;
					else n20++;
					falg2=false;
				}
				if(s1[r1]-'0'==1) n11++;
				else n10++; 
				res+=min(n10,n20)+min(n11,n21);
				n20=n20-min(n10,n20);
				n21=n21-min(n11,n21);
				n10=n11=0;
				l2=l1=++r1;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
