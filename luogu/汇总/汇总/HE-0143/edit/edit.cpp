#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,T,s1[MAXN],s2[MAXN],t1[MAXN],t2[MAXN];
int belong1[MAXN],belong2[MAXN];
struct node {
	int l,r,n1,n0;
} u[MAXN],v[MAXN];

int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		cin>>n;
		string ss1;
		cin>>ss1;
		for(int i=0; i<n; i++) {
			s1[i+1]=(ss1[i]-'0');
		}
		string ss2;
		cin>>ss2;
		for(int i=0; i<n; i++) {
			s2[i+1]=(ss2[i]-'0');
		}
		string tt1;
		cin>>tt1;
		for(int i=0; i<n; i++) {
			t1[i+1]=(tt1[i]-'0');
		}
		string tt2;
		cin>>tt2;
		for(int i=0; i<n; i++) {
			t2[i+1]=(tt2[i]-'0');
		}
		int cnt=0,l=1,r;
		for(int i=1; i<=n; i++) {
			if(t1[i]==1&&t1[i-1]==0) {
				l=i;
				cnt++;
			} else if(t1[i]==0) {
				cnt++;
				belong1[i]=cnt;
				if(s1[i]==0) u[cnt].n0++;
				if(s1[i]==1) u[cnt].n1++;
				u[cnt].l=u[cnt].r=i;
				continue;
			}
			if(s1[i]==0) u[cnt].n0++;
			if(s1[i]==1) u[cnt].n1++;
			belong1[i]=cnt;
			if(t1[i]==1&&t1[i+1]==0) {
				r=i;
				u[cnt].r=r;
				u[cnt].l=l;
			}
		}
		cnt=0,l=1,r=0;
		for(int i=1; i<=n; i++) {
			if(t2[i]==1&&t2[i-1]==0) {
				l=i;
				cnt++;
			} else if(t2[i]==0) {
				cnt++;
				belong2[i]=cnt;
				if(s2[i]==0) v[cnt].n0++;
				if(s2[i]==1) v[cnt].n1++;
				v[cnt].l=v[cnt].r=i;
				continue;
			}
			if(s2[i]==0) v[cnt].n0++;
			if(s2[i]==1) v[cnt].n1++;
			belong2[i]=cnt;
			if(t2[i]==1&&t2[i+1]==0) {
				r=i;
				v[cnt].r=r;
				v[cnt].l=l;
			}
		}
		int b1,b2,ans=0;
		for(int i=1; i<=n; i++) {
			b1=belong1[i];
			b2=belong2[i];
			if(u[b1].n0>0&&v[b2].n0>0){
				ans++;
				u[b1].n0--;
				v[b2].n0--;
			}else if(u[b1].n1>0&&v[b2].n1>0){
				ans++;
				u[b1].n1--;
				v[b2].n1--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
