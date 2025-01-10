#include<bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int n,T,ans;
string sa,sb,ta,tb;
int suma1=0,suma0=0,sumb1=0,sumb0=0;
int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	int fla=0,kkk=0;
	while(T--) {//T
		scanf("%d",&n);
		cin>>sa>>sb>>ta>>tb;ta+='9';tb+='9';
		suma1=suma0=sumb1=sumb0;
		for(int i=0;i<n;i++) {
			if(sa[i]=='1') suma1++;
			if(sa[i]=='0') suma0++;
			if(sb[i]=='1') sumb1++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
			if(sb[i]=='0') sumb0++;
		}
//		cout<<suma1<<" "<<suma0<<" "<<sumb1<<" "<<sumb0<<endl ;
		for(int i=0,j=0,l=0,r=0;i<n;i++,j++) {//n
			if(l==i) suma1=suma0=0;
			if(r==j) sumb1=sumb0=0;
			if(ta[i]=='1'&&ta[i+1]=='1'&&l<=i) {
				kkk=0;
				for(int k=i;k<n;k++) {
					if(ta[k]=='0'){l=k;kkk=1;break;}
					if(sa[k]=='1') suma1++;
					else suma0++;
				}
				if(!kkk) l=n;
			}
			if(tb[j]=='1'&&tb[j+1]=='1'&&r<=j) {
				kkk=0;
				for(int k=j;k<n;k++) {
					if(tb[k]=='0') {r=k;kkk=1;break;}
					if(sb[k]=='1') sumb1++;
					else sumb0++;
				}
				if(!kkk) r=n;
			}
			if(l<=i&&r<=j) {
				if(sa[i]==sb[j]) ans++;
			}
			else {
				if(r>j&&l<=i) {
					if(sa[i]=='0') {
						if(sumb0>0) sumb0--,ans++;
					}
					else if(sa[i]=='1'){
						if(sumb1>0) sumb1--,ans++;
					}
				}
				else if(l>i&&r<=j){
					if(sb[j]=='0') {
						if(suma0>0) suma0--,ans++;
					}
					else if(sb[j]=='1'){
						if(suma1>0) suma1--,ans++;
					}
				}
				else {
					if(suma1>0&&suma0>0&&sumb1>0&&sumb0>0) {
						if(min(suma1,sumb1)>min(suma0,sumb0))
						suma1--,sumb1--,ans++;
						else 
						suma0--,sumb0--,ans++;
					}
					else if(suma0>0&&sumb0>0) suma0--,sumb0--,ans++;
					else if(suma1>0&&sumb1>0) suma1--,sumb1--,ans++;
				}
			}
//			cout<<i<<" "<<l<<" "<<suma1<<" "<<suma0<<endl; 
//			cout<<j<<" "<<r<<" "<<sumb1<<" "<<sumb0<<endl<<ans<<endl<<endl;
		}
		printf("%d\n",ans);
		ans=0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
