#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
string s1,s2,t1,t2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2>>t1>>t2;
		t1+='0';
		t2+='0';
		s1+='1';
		s2+='0';
		s1=' '+s1;
		s2=' '+s2;
		t1=' '+t1;
		t2=' '+t2;
		int ans=0,i=0,j=0,s11=0,s10=0,s21=0,s20=0;
		while(i<=n||j<=n){
			while(t1[i+1]=='1'){
				i++;
				if(s1[i]=='1') s11++;
				else s10++;
			}
			while(t2[j+1]=='1'){
				j++;
				if(s2[j]=='1') s21++;
				else s20++;
			}
			if(j==i){
				ans+=min(s11,s21);
				ans+=min(s10,s20);
				s11=s21=s10=s20=0;
				i++;
				j++;
				if(s1[i]==s2[j]) ans++;
			}
			else if(j<i){
				int lim=j-(i-s11-s10);
				ans+=min(lim,min(s11,s21));
				s11-=min(lim,min(s11,s21));
				lim-=min(lim,min(s11,s21));
				ans+=min(lim,min(s10,s20));
				s10-=min(lim,min(s10,s20));
				lim-=min(lim,min(s10,s20));
				s21=s20=0;
				j++;
				if(s2[j]=='1'){
					if(s11) ans++,s11--;
				}
				else{
					if(s10) ans++,s10--;
				}
				if(i==j) s10=s11=s20=s21=0;
			}
			else{
				int lim=i-(j-s21-s20);
				ans+=min(lim,min(s11,s21));
				s21-=min(lim,min(s21,s11));
				lim-=min(lim,min(s11,s21));
				ans+=min(lim,min(s10,s20));
				s20-=min(lim,min(s20,s10));
				lim-=min(lim,min(s20,s10));
				s11=s10=0;
				i++;
				if(s1[i]=='1'){
					if(s21) ans++,s21--;
				}
				else{
					if(s20) ans++,s20--;
				}
				if(i==j) s10=s11=s20=s21=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}