#include <bits/stdc++.h>
using namespace std;
int zhi(int x,int y) {
	int z=abs(x)+abs(y);
	return z;
}
bool quan(string s) {
	int l=s.size(),n1=0,n0=0;
	for(int i=0; i<l; i++) {
		if(s[i]=='1') {
			n1++;
		} else {
			n0++;
		}
	}
	if((n1==0)||(n0==0)) {
		return true;
	} else {
		return false;
	}
}
int main() {

	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);

	string s1,s2,t1,t2;
	int T,n;
	cin>>T;
	for(int i=0; i<T; i++) {
		int temp1=0,temp2=0,suo=0,ans=0;
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		if(quan(s1)) {
			for(int j=0; j<n; j++) {
				if(s1[j]==s2[j]) {
					ans++;
				}
			}
			cout<<ans<<"\n";
		} else {
			for(int k=0; k<n; k++) {
				if((t1[k-1]=='0')&&(t1[k+1]=='0')) {
					t1[k]='0';
				}
				if((t2[k-1]=='0')&&(t2[k+1]=='0')) {
					t2[k]='0';
				}
			}
			for(int k=0; k<n; k++) {
				if((t1[k]=='0')&&(t2[k]!='0')) {
					ans++;
					if(s1[k]!=s2[k]) {
						if(s1[k]=='1') {
							temp2--;
						} else {
							temp2++;
						}
					}
				} else if((t1[k]!='0')&&(t2[k]=='0')) {
					ans++;
					if(s1[k]!=s2[k]) {
						if(s2[k]=='1') {
							temp1--;
						} else {
							temp1++;
						}
					}
				} else if((t1[k]=='0')&&(t2[k]=='0')) {
					if(s1[k]==s2[k]) {
						ans++;
					}
				} else if((t1[k]=='1')&&(t2[k]=='1')) {
					ans++;
					if(s1[k]!=s2[k]) {
						if(s1[k]=='1') {
							temp1++;
						} else if(s2[k]=='1') {
							temp2++;
						}
					}
				}
			}
			ans-=zhi(temp1,temp2);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
