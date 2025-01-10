#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll T,n,ans;
char slzl[N],slhl[N];
ll sx[N],sy[N],tot,num;
struct node {
	ll l,r,ho;
	ll oe,zer;
}w[N],tr[N];
bool a[N],b[N];
bool cmp(node x,node y) {
	return x.l<y.l;
}
void work() {
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(sx,0,sizeof(sx));
	memset(sy,0,sizeof(sy));
//	memset(w,0,sizeof(w));
//	memset(tr,0,sizeof(tr));
	num=0;
	tot=0;
	ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++) {
		cin>>slzl[i];
		sx[i]=sx[i-1];
		if(slzl[i]=='1') sx[i]++;
	}
	for(ll i=1;i<=n;i++) {
		cin>>slhl[i];
		sy[i]=sy[i-1];
		if(slhl[i]=='1') sy[i]++;
	}
	for(ll i=1;i<=n;i++) {
		char s;
		cin>>s;
		if(s=='1') a[i]=1;
	}
	ll la=0;
	for(ll i=1;i<=n;i++) {
		if(a[i]==0) {
			la=0;
			continue;
		}
		if(a[i]==1&&a[i-1]==0&&a[i+1]==0) continue;
		if(a[i-1]==0&&a[i]==1) la=i;
		if(a[i]==1&&a[i+1]==0) {
			w[++tot].l=la,w[tot].r=i;
			w[tot].ho=0;
			w[tot].oe=sx[i]-sx[la-1];
			w[tot].zer=i-la+1-w[tot].oe;
		}
	}
	for(ll i=1;i<=n;i++) {
		char s;
		cin>>s;
		if(s=='1') b[i]=1;
	}
	la=0;
	for(ll i=1;i<=n;i++) {
		if(b[i]==0) {
			la=0;
			continue;
		}
		if(b[i]==1&&b[i-1]==0&&b[i+1]==0) continue;
		if(b[i-1]==0&&b[i]==1) la=i;
		if(b[i]==1&&b[i+1]==0) {
			w[++tot].l=la,w[tot].r=i;
			w[tot].ho=1;
			w[tot].oe=sy[i]-sy[la-1];
			w[tot].zer=i-la+1-w[tot].oe;
		}
	}
	sort(w+1,w+tot+1,cmp);
	for(int i=1;i<=tot;i++) {
		int pos=i;
		while(w[pos+1].r<=w[i].r&&pos<=tot) pos++;
		tr[++num]=w[i];
		i=pos;
	}
	tr[num+1].l=2e9;
	for(ll i=1;i<=num;i++) {
		int aaa=ans;
		if(tr[i-1].r<tr[i].l) {
			for(ll j=tr[i-1].r+1;j<tr[i].l;j++) {
				if(slzl[j]==slhl[j]) ans++;
			}
			if(tr[i+1].l>tr[i].r) {
				if(tr[i].ho==0) {
					ll ob=sy[tr[i].r]-sy[tr[i].l-1];
					ll zb=tr[i].r-tr[i].l+1-ob;
					ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
					tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
				}
				else {
					ll ob=sx[tr[i].r]-sx[tr[i].l-1];
					ll zb=tr[i].r-tr[i].l+1-ob;
					ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
					tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
				}
			}
			else {
				if(tr[i].ho==0) {
					ll ob=sy[tr[i+1].l-1]-sy[tr[i].l-1];
					ll zb=tr[i+1].l-tr[i].l-ob;
					ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
					tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
				}
				else {
					ll ob=sx[tr[i+1].l-1]-sx[tr[i].l-1];
					ll zb=tr[i+1].l-tr[i].l-ob;
					ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
					tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
				}
			}
			continue;
		}
		ans=ans+min(tr[i].oe,tr[i-1].oe)+min(tr[i].zer,tr[i-1].zer);
		tr[i].oe-=min(tr[i].oe,tr[i-1].oe),tr[i].zer-=min(tr[i].zer,tr[i-1].zer);
		if(tr[i+1].l>tr[i].r) {
			if(tr[i].ho==0) {
				ll ob=sy[tr[i].r]-sy[tr[i-1].r];
				ll zb=tr[i].r-tr[i-1].r-ob;
				ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
				tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
			}
			else {
				ll ob=sx[tr[i].r]-sx[tr[i-1].r];
				ll zb=tr[i].r-tr[i-1].r-ob;
				ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
				tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
			}
		}
		else {
			if(tr[i].ho==0) {
				ll ob=sy[tr[i+1].l-1]-sy[tr[i-1].r];
				ll zb=tr[i+1].l-1-tr[i-1].r-ob;
				ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
				tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
			}
			else {
				ll ob=sx[tr[i+1].l-1]-sx[tr[i-1].r];
				ll zb=tr[i+1].l-1-tr[i-1].r-ob;
				ans=ans+min(tr[i].oe,ob)+min(tr[i].zer,zb);
				tr[i].oe-=min(tr[i].oe,ob),tr[i].zer-=min(tr[i].zer,zb);
			}
		}
	}
	if(tr[num].r<n) {
		for(ll j=tr[num].r+1;j<=n;j++) {
			if(slzl[j]==slhl[j]) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--) work();
	return 0;
}
/*
1
6
011101
111010
111010
101101

1
7
1111111
1111111
1110111
0110110

2
10
0110111100
1111111100
1110000100
0110111011
9
101111111
100111000
110111011
011111111
*/
