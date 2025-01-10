#include<bits/stdc++.h>
//#define int long long
using namespace std;

int T,n;
char a[100100],b[100100],t1[100100],t2[100100];

int ans,to1,to2,p1[100100],p2[100100];

struct node {
	int l,r,c[2];
}g1[100100],g2[100100];

signed main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;to1=to2=0;
		scanf("%s",a+1);scanf("%s",b+1);
		scanf("%s",t1+1);scanf("%s",t2+1);
		for(int i=1;i<=n;i++)  
			g1[i].l=g2[i].l=1e5,g1[i].r=g2[i].r=0,
			g1[i].c[0]=g1[i].c[1]=0,g2[i].c[0]=g2[i].c[1]=0;
		
		for(int i=1;i<=n;i++) {
			if(t1[i]=='1') {
				if(to1==0) to1++;
				g1[to1].l=min(g1[to1].l,i);
				g1[to1].r=i;
			}
			else {++to1;
				g1[to1].l=g1[to1].r=i;
				if(i<n&&t1[i+1]=='1') ++to1; 
			}
			if(t2[i]=='1') {
				if(to2==0) to2++;
				g2[to2].l=min(g2[to2].l,i);
				g2[to2].r=i;
			}
			else {++to2;
				g2[to2].l=g2[to2].r=i;
				if(i<n&&t2[i+1]=='1') ++to2; 
			}
		}
		for(int i=1;i<=to1;i++) 
			for(int j=g1[i].l;j<=g1[i].r;j++) p1[j]=i,g1[i].c[a[j]-'0']++;
		for(int i=1;i<=to2;i++) 
			for(int j=g2[i].l;j<=g2[i].r;j++) p2[j]=i,g2[i].c[b[j]-'0']++;
		for(int i=1;i<=n;i++) {
			if(t1[i]=='0'&&t2[i]=='0') {
				if(a[i]==b[i]) ans++;
			}
			else if(t1[i]=='0') {
				if(g2[p2[i]].c[a[i]-'0']) g2[p2[i]].c[a[i]-'0']--,ans++;
			}
			else if(t2[i]=='0') {
				if(g1[p1[i]].c[b[i]-'0']) g1[p1[i]].c[b[i]-'0']--,ans++;
			}
		}
		int nw1=1,nw2=1;
		for(int i=1;i<=n;i++) {
			nw1=p1[i],nw2=p2[i];
			if(t1[i]=='0'||t2[i]=='0') continue;
			int k=min(g1[nw1].c[0],g2[nw2].c[0]);
			if(k) { g1[nw1].c[0]--,g2[nw2].c[0]--;ans++;continue; }
			k=min(g1[nw1].c[1],g2[nw2].c[1]);
			if(k) { g1[nw1].c[1]--,g2[nw2].c[1]--;ans++;continue; }
			
		}
//		while(nw1<=to1&&nw2<=to2) {
//			int sum=min(g1[nw1].r,g2[nw2].r,
//			int k=min(g1[nw1].c[0],g2[nw2].c[0]);
//			g1[nw1].c[0]-=k,g2[nw2].c[0]-=k;
//			ans+=k;
//			k=min(g1[nw1].c[1],g2[nw2].c[1]);
//			ans+=k;
//			g1[nw1].c[1]-=k,g2[nw2].c[1]-=k;
//			if(g1[nw1].r==g2[nw2].r) nw1++,nw2++;
//			else if(g1[nw1].r<g2[nw2].r) nw1++;
//			else if(g1[nw1].r>g2[nw2].r) nw2++;
//		}
		cout<<ans<<endl;
	}
	return 0;
} 
