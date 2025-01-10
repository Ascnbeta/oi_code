#include<bits/stdc++.h>
using namespace std;
int T,n,a1,ans1,minn,maxn,a2,a3,a4,a5,a6,a7,a8,a9;
struct O{
	int s1;
	int t1;
};
O p[100005];
struct Q{
	int s2;
	int t2;
};
Q q[100005];
bool cmp(O a,O b){
	return a.s1>b.s1;
}
bool cnp(Q a,Q b){
	return a.s2>b.s2;
}
int ji(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].s1;
	for(int i=1;i<=n;i++) cin>>q[i].s2;
	for(int i=1;i<=n;i++) cin>>p[i].t1;
	for(int i=1;i<=n;i++) cin>>q[i].t2;
	for(int i=2;i<=n;i++){
		if(p[i].s1==p[i-1].s1) a1++;
	}
	for(int i=1;i<=n;i++){
		if(p[i].t1==p[i].t1) a2++;
	}
	for(int i=1;i<=n;i++){
		if(p[i].t1==0){
			a5++;
			a7=i;
		}
		if(q[i].t2==0){
			a6++;
			a8=i;
		}
	}
	if(a1==n-1){
		for(int i=1;i<=n;i++){
			if(p[i].s1==q[i].s2) ans1++;
		}
		cout<<ans1;
		ans1=0;
		a1=0;
		a2=0;
		a5=0;
		a6=0;
		return 0;
	}
	if(a2==n){
		a3=0;
		for(int i=1;i<=n;i++){
			if(p[i].t1==0){
				if(p[i].s1==q[i].s2) a4++;
				if(i-a3>2){
					sort(p+a3+1,p+i,cmp);
					sort(q+a3+1,q+i,cnp);
				}
				for(int j=a3+1;j<i;j++){
					if(p[j].s1==q[j].s2) a4++;
				}
				a3=i;	
			}
		}
				if(n-a3>1){
					sort(p+a3+1,p+n+1,cmp);
					sort(q+a3+1,q+n+1,cnp);
				}
				for(int j=a3+1;j<=n;j++){
					if(p[j].s1==q[j].s2) a4++;
				}
			cout<<a4;
			a4=0;
		a1=0;
		a2=0;
		a5=0;
		a6=0;
	}
	if(a5==1&&a6==1){
		if(q[a7].s2!=p[a7].s1){
			if(a7>a8){
				for(int i=a8+1;i<=n;i++){
					if(q[i].s2==p[a7].s1){
						a9++;
						swap(q[i].s2,q[a7].s2);
						break;
					}
				}
			}else{
				for(int i=1;i<a8;i++){
					if(q[i].s2==p[a7].s1){
						a9++;
						swap(q[i].s2,q[a7].s2);
						break;
					}
				}
			}
		}
		if(p[a8].s1!=q[a8].s2){
			if(a7>a8){
				for(int i=1;i<a7;i++){
					if(p[i].s1==q[a8].s2){
						a9++;
						swap(p[i].s1,p[a8].s1);
						break;
					}
				}
			}else{
				for(int i=a7+1;i<=n;i++){
					if(p[i].s1==q[a8].s2){
						a9++;
						swap(p[i].s1,p[a8].s1);
						break;
					}
				}
			}
		}
		minn=min(a7,a8);
		maxn=max(a7,a8);
		if(minn>2){
			sort(p+1,p+minn,cmp);
			sort(q+1,q+minn,cnp);
		}
		for(int i=1;i<minn;i++){
			if(p[i].s1==q[i].s2) a9++;
		}
		if(maxn-minn>2){
			sort(p+minn+1,p+maxn,cmp);
			sort(q+minn,q+maxn,cnp);
		}
		for(int i=minn+1;i<maxn;i++){
			if(p[i].s1==q[i].s2) a9++;
		}
		if(maxn<n-1){
			sort(p+maxn+1,p+n+1,cmp);
			sort(q+maxn,q+n+1,cnp);
		}
		for(int i=maxn+1;i<=n;i++){
			if(p[i].s1==q[i].s2) a9++;
		}
		cout<<a9;
		a4=0;
		a1=0;
		a2=0;
		a5=0;
		a6=0;
	}
}
int main(){
	freopen("edit.cpp","r",stdin);
	freopen("edit.cpp","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		ji();
	}
}

