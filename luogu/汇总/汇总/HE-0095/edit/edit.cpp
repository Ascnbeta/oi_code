#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s1[N],s2[N],t1[N],t2[N];
int sum1[10],sum2[10];
char a;
int ans,n;
int T,fc;
bool fa,fb;
int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		fa=0,fb=0,fc=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			cin>>a;
			s1[i]=(int)(a-'0');
			if(s1[i]!=s1[i-1]&&i!=1) {
				fa=1;
			}
		}
		for(int i=1; i<=n; i++) {
			cin>>a;
			s2[i]=(int)(a-'0');
		}
		for(int i=1; i<=n; i++) {
			cin>>a;
			t1[i]=(int)(a-'0');
			fc+=t1[i];
		}
		for(int i=1; i<=n; i++) {
			cin>>a;
			t2[i]=(int)(a-'0');
			fc+=t2[i];
			if(t1[i]!=t2[i])fb=1;
//			if((!t1[i]&&!t2[i])&&s1[i]==s2[i]) {
//				ans++;
//			}
		}
		for(int i=1; i<=n; i++) {
			if((t1[i]&&!t1[i-1])&&(!t1[i+1])) {
			//	if(s1[i]==s2[i])ans++;
				t1[i]=0;
			}
			if((t2[i]&&!t2[i-1])&&(!t2[i+1])) {
			//	if(s1[i]==s2[i])ans++;
				t2[i]=0;
			}
			if(t1[i]) {
				sum1[t1[i]]++;
			}
			if(t2[i]) {
				sum2[t2[i]]++;
			}
		}
		if(!fa) {
			ans=0;
			//cout<<"*&"<<endl;
			for(int i=1; i<=n; i++) {
				if(s2[i]==s1[1]) {
					ans++;
				}
			}
			printf("%d\n",ans);
		} else {
			//cout<<"(^"<<endl;
			if(!fb) {
			//	cout<<"))"<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<t1[i];
//			}
//			cout<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<t2[i];
//			}
//			cout<<endl;
				ans=0;
				for(int i=1;i<=n;i++){
					if(((!t1[i])&&(!t2[i]))&&(s1[i]==s2[i])){
						ans++;
					}
				}
				for(int i=1; i<=n; i++) {
					if(t1[i]&&t2[i]) {
						int d=0,j=i;
						for(; t1[j]&&t2[j]; j++) {
							d+=s1[j];
							d-=s2[j];
						}
						ans+=(j-i-abs(d));
						i=j;
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
