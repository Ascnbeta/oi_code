#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+10;
int t,n,ans,cntone,cntze,l,ll;
int acnt[N][2],bcnt[N][2],lena,lenb;
string a,b,c,d;
void pprework(){
	ans=lena=lenb=cntone=cntze=0;
	cin>>n>>a>>b>>c>>d;
	a="@"+a,b="@"+b,c="@"+c,d="@"+d;
	for(int i=1;i<=n;i++){
		if(c[i]=='0')acnt[++lena][0]=cntze,acnt[lena][1]=cntone,cntone=cntze=0;
		else {
			if(a[i]=='0')cntze++;
			else cntone++;
		}
	}
	acnt[++lena][0]=cntze,acnt[lena][1]=cntone,cntone=cntze=0;
	for(int i=1;i<=n;i++){
		if(d[i]=='0')bcnt[++lenb][0]=cntze,bcnt[lenb][1]=cntone,cntone=cntze=0;
		else {
			if(b[i]=='0')cntze++;
			else cntone++;
		}
	}
	bcnt[++lenb][0]=cntze,bcnt[lenb][1]=cntone,cntone=cntze=0;
	l=ll=1;
	for(int i=1;i<=n;i++){
		if(c[i]=='0'&&d[i]=='0'){
			if(a[i]==b[i])ans++;
			l++,ll++;
		}
		else if(c[i]=='0'&&d[i]=='1'){
			if(a[i]=='0'){
				if(bcnt[ll][0]>0)ans++,bcnt[ll][0]--;
			}
			else{
				if(bcnt[ll][1]>0)ans++,bcnt[ll][1]--;
			}
			l++;
		}
		else if(c[i]=='1'&&d[i]=='0'){
			if(b[i]=='0'){
				if(acnt[l][0]>0)ans++,acnt[l][0]--;
			}
			else{
				if(acnt[l][1]>0)ans++,acnt[l][1]--;
			}
			ll++;
		}
	}
	l=ll=1;
	for(int i=1;i<=n;i++){
		if(c[i]=='0')l++;
		if(d[i]=='0')ll++;
		if(c[i]=='1'&&d[i]=='1'){
			if(acnt[l][0]>0&&bcnt[ll][0]>0)ans++,acnt[l][0]--,bcnt[ll][0]--;
			else if(acnt[l][1]>0&&bcnt[ll][1]>0)ans++,acnt[l][1]--,bcnt[ll][1]--;
		}
	}
	cout<<ans<<"\n";
}
void ssolve(){
	for(int i=1;i<=max(lena,lenb);i++)for(int j=0;j<=1;j++)acnt[i][j]=bcnt[i][j]=0;
}
signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		pprework();
		ssolve();
	}
	return 0;
} 
