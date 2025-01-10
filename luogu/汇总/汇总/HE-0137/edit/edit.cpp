#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5+10;
int T;
int n;
char s1[mx],s2[mx];
char a1[mx],a2[mx];
int p1[mx],p2[mx];
int p11[mx],p21[mx];
int p10[mx],p20[mx];
int ans;
int tot11;
int tot21;
int tot1,tot2;
void sol() {
	ans=0;
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	memset(p11,0,sizeof(p11));
	memset(p21,0,sizeof(p21));
	memset(p10,0,sizeof(p10));
	memset(p20,0,sizeof(p20));
	tot1=1;
	tot2=1;
	for(int i=1; i<=n; i++) {
		if(a1[i]=='0') p1[tot1++]=i;
		else if(s1[i]=='1') p11[tot1]++;
		else if(s1[i]=='0') p10[tot1]++;
	}
	for(int i=1; i<=n; i++) {
		if(a2[i]=='0') p2[tot2++]=i;
		else if(s2[i]=='1') p21[tot2]++;
		else if(s2[i]=='0') p20[tot2]++;
	}
//	cout << '\n';
//	for(int i=1;i<=tot2;i++) cout << p21[i] << '\n';
	int l=1,r=1;
	while(l<tot1 and r<tot2) {
//		cout << l << ' ';
//		cout << l << ' ' << r << ' ' << p1[l] << ' ' << p2[r] << '\n';
//		cout << ans << '\n';
		if(p1[l]>p2[r]) {
			if(s2[p2[r]]=='1' and p11[l]!=0) {
				p11[l]--;
				ans++;
			} else if(s2[p2[r]]=='0' and p10[l]!=0) {
				p10[l]--;
				ans++;
			}
			int len = p2[r]-p1[l-1]-1;
			if(p11[l]>=p21[r]) {
				ans+=min(len,p21[r]);
				len-=min(len,p21[r]);
				p11[l]-=min(len,p21[r]);
				p21[r]-=min(len,p21[r]);
			} else {
				ans+=min(len,p11[l]);
				len-=min(len,p11[l]);
				p11[l]-=min(len,p11[l]);
				p21[r]-=min(len,p11[l]);
			}
			if(p10[l]>=p20[r]) {
				ans+=min(len,p20[r]);
				len-=min(len,p20[r]);
				p10[l]-=min(len,p20[r]);
				p20[r]-=min(len,p20[r]);
			} else {
				ans+=min(len,p10[l]);
				len-=min(len,p10[l]);
				p10[l]-=min(len,p10[l]);
				p20[r]-=min(len,p10[l]);
			}
			r++;
		}
		else if(p1[l]<p2[r]){
			if(s1[p1[l]]=='1' and p21[r]!=0) {
				p21[r]--;
				ans++;
			} else if(s1[p1[l]]=='0' and p20[r]!=0) {
				p20[r]--;
				ans++;
			}
			int len = p1[l]-p2[r-1]-1;
			if(p11[l]>=p21[r]) {
				ans+=min(len,p21[r]);
				len-=min(len,p21[r]);
				p11[l]-=min(len,p21[r]);
				p21[r]-=min(len,p21[r]);
			} else {
				ans+=min(len,p11[l]);
				len-=min(len,p11[l]);
				p11[l]-=min(len,p11[l]);
				p21[r]-=min(len,p11[l]);
			}
			if(p10[l]>=p20[r]) {
				ans+=min(len,p20[r]);
				len-=min(len,p20[r]);
				p10[l]-=min(len,p20[r]);
				p20[r]-=min(len,p20[r]);
			} else {
				ans+=min(len,p10[l]);
				len-=min(len,p10[l]);
				p10[l]-=min(len,p10[l]);
				p20[r]-=min(len,p10[l]);
			}
			l++;
		}else if(p1[l]==p2[r]){
			if(s1[p1[l]]==s2[p2[r]]) ans++;
			int len = p1[l]-max(p1[l-1],p2[r-1])-1;
//			cout << len << '\n';
//			cout << p11[l] << ' ' << p21[r] << '\n';
			if(p11[l]>=p21[r]) {
				ans+=min(len,p21[r]);
				len-=min(len,p21[r]);
				p11[l]-=min(len,p21[r]);
				p21[r]-=min(len,p21[r]);
			} else {
				ans+=min(len,p11[l]);
				len-=min(len,p11[l]);
				p11[l]-=min(len,p11[l]);
				p21[r]-=min(len,p11[l]);
			}
			if(p10[l]>=p20[r]) {
				ans+=min(len,p20[r]);
				len-=min(len,p20[r]);
				p10[l]-=min(len,p20[r]);
				p20[r]-=min(len,p20[r]);
			} else {
				ans+=min(len,p10[l]);
				len-=min(len,p10[l]);
				p10[l]-=min(len,p10[l]);
				p20[r]-=min(len,p10[l]);
			}
			l++,r++;
		}
	}
}

signed main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) {
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		n=0;
		cin >> n;
		n++;
		cin >> s1+1;
		cin >> s2+1;
		cin >> a1+1;
		cin >> a2+1;
		s1[n]='?';
		s2[n]='#';
		a2[n]='0';
		a1[n]='0';
		sol();
		cout << ans << '\n';
	}
	return 0;
}
