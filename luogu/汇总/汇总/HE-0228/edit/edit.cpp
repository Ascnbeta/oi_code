#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,l1[N],r1[N],l2[N],r2[N],num1[N][2],num2[N][2],num3[N][2],num4[N][2];
bool check[N];
int cnt1,cnt2;
string s1,s2,t1,t2;
//l[i],r[i]表示第i个区间的左右端点,num[i][0/1]表示第i个区间0/1的数量
void init(int n){
	for(int i=0;i<n;i++){
		if(t1[i]=='1'&&(t1[i+1]=='0'||i==n-1)&&t1[i-1]=='1') r1[cnt1]=i;
		if(t1[i]=='1'&&t1[i+1]=='1'&&(i==0||t1[i-1]=='0')) l1[++cnt1]=i;
		if(t2[i]=='1'&&(t2[i+1]=='0'||i==n-1)&&t2[i-1]=='1') r2[cnt2]=i;
		if(t2[i]=='1'&&t2[i+1]=='1'&&(i==0||t2[i-1]=='0')) l2[++cnt2]=i;
	}
	for(int i=1;i<=cnt1;i++)
		for(int j=l1[i];j<=r1[i];j++)
			num1[i][s1[j]-'0']++,num3[i][s1[j]-'0']++;
	for(int i=1;i<=cnt2;i++)
		for(int j=l2[i];j<=r2[i];j++)
			num2[i][s2[j]-'0']++,num4[i][s2[j]-'0']++;
} 
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		memset(l1,0,sizeof(l1));
		memset(r1,0,sizeof(r1));
		memset(l2,0,sizeof(l2));
		memset(r2,0,sizeof(r2));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(num3,0,sizeof(num3));
		memset(num4,0,sizeof(num4));
		memset(check,0,sizeof(check));
		cin>>n;
		cnt1=0,cnt2=0;
		cin>>s1>>s2>>t1>>t2;
		init(n);
		for(int i=1;i<=cnt1;i++)
			for(int j=l1[i];j<=r1[i];j++){
				int q=s2[j]-'0';
				if(num1[i][q]>0) num1[i][q]--,s1[j]=s2[j];
				else num1[i][q^1]--,s1[j]=(q^1)+'0';
			}
		for(int i=1;i<=cnt2;i++) 
			for(int j=l2[i];j<=r2[i];j++){
				int q=s1[j]-'0';
				if(num2[i][q]>0) num2[i][q]--,s2[j]=s1[j];
				else num2[i][q^1]--,s2[j]=(q^1)+'0';
			}
		for(int i=1;i<=cnt1;i++)
			for(int j=l1[i];j<=r1[i];j++){
				int q=s2[j]-'0';
				if(num3[i][q]>0) num3[i][q]--,s1[j]=s2[j];
				else num3[i][q^1]--,s1[j]=(q^1)+'0';
			}
		for(int i=1;i<=cnt2;i++) 
			for(int j=l2[i];j<=r2[i];j++){
				int q=s1[j]-'0';
				if(num4[i][q]>0) num4[i][q]--,s2[j]=s1[j];
				else num4[i][q^1]--,s2[j]=(q^1)+'0';
			}
		int ans=0;
		for(int i=0;i<n;i++) 
			if(s1[i]==s2[i]) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
