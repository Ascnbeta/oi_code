#include <iostream>
#include <algorithm>
using namespace std;
const int M=1e6+3;
int n,q,op,x,y,v,tt;
int lg[23],maxx;
long long lans;
struct node{
	long long x,lz,cc;
}a[M];
void ff(int j,int x){
	int p=1;
	a[p].x+=x,a[p].cc++;
	for(int i=0;i<maxx;i++){
		if(j%2==0) p<<=1;
		else p=p<<1|1;
		a[p].x+=x,a[p].cc++,j/=2;
	}
}
void push_down(int p){
    a[p<<1].lz+=a[p].lz,a[p<<1|1].lz+=a[p].lz;
	a[p<<1].x+=a[p<<1].cc*a[p].lz,a[p<<1|1].x+=a[p<<1|1].cc*a[p].lz;
}
void update(int d,int p,int j){
	if(d==x){
		tt=a[p].cc*v;
		a[p].x+=tt;
		a[p].lz+=v;
		return;
	}
	push_down(p);
	if(j%2==0) update(d+1,p<<1,j>>1);
	else update(d+1,p<<1|1,j>>1);
	a[p].x+=tt;
}
long long query(int d,int p,int j){
	if(d==x) return a[p].x;
	push_down(p);
	if(j%2==0) return query(d+1,p<<1,j>>1);
	else return query(d+1,p<<1|1,j>>1);
}
int main(){
	cin>>n>>q;
	lg[0]=1;
	for(int i=1;i<=21;i++) lg[i]=lg[i-1]*2;
	maxx=lower_bound(lg,lg+22,n)-lg;
	for(int i=1;i<=n;i++){
	    cin>>tt;
		ff(i,tt);
	}
	while(q--){
		cin>>op>>x>>y;
		op=(op+lans)%2+1;
		if(op==1){
			cin>>v;
			if(y>n) continue;
			tt=0;
			update(0,1,y);
		}
		else{
			if(y>n) cout<<"0\n";
			lans=query(0,1,y); 
			cout<<lans<<"\n";
		}
	}
	return 0;
}
