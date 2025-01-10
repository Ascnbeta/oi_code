#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
char s1[N],s2[N],t1[N],t2[N];
//struct tree{
//	int l,r,sum;
//	int add;
//}t[N<<2];
//inline void pushup(int p){
//	t[p].sum=(t[p<<1].sum+t[p<<1|1].sum);
//}
//inline void build(int p,int l,int r){
//	t[p].l=l;
//	t[p].r=r;
//	t[p].add=0;
//	if(l==r){
//		t[p].sum=s[l]-'0';
//		return;
//	}
//	int mid=l+r>>1;
//	build(p<<1,l,mid);
//	build(p<<1|1,mid+1,r);
//	pushup(p);
//}
//inline void change(int p,int l,int r,int k);
int ans=0;
int sum1[N][2];
int sum2[N][2];
inline void solve(){
	scanf("%d\n",&n);
	ans=0;
	int cnt1=0;
	int cnt2=0;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	scanf("%s\n%s\n%s\n%s",s1+1,s2+1,t1+1,t2+1);
	for(int i=2;i<=n;i++){
		if(s1[i]!=s1[i-1]) {
			flag1=1;
			break;
		}
	}
	if(!flag1){
		for(int i=1;i<=n;i++){
			if(s2[i]==s1[i]){
				ans++;
			}
		}
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(s1[i]!=s2[i]){
			flag2=1;
			break;
		}
	}
	if(!flag2){
		printf("%d\n",n);
		return;
	}
	flag1=0;
	flag2=0;
	for(int i=1;i<=n;i++){
		if(t1[i]=='0') flag1++;
		if(t2[i]=='0') flag2++;
	}
	if(flag1==1&&flag2==1){
		int a,b;
		for(int i=1;i<=n;i++){
			if(t1[i]=='0') a=i;
			if(t2[i]=='0') b=i;
		}
		int sum[2][2]={},sum1[2][2]={};
		for(int i=1;i<a;i++){
			sum[0][s1[i]-'0']++;
		}
		for(int i=a+1;i<=n;i++){
			sum[1][s1[i]-'0']++;
		}
		for(int i=1;i<b;i++){
			sum1[0][s2[i]-'0']++;
		}
		for(int i=b+1;i<=n;i++){
			sum1[1][s2[i]-'0']++;
		}
		if(a==b){
			ans+=min(sum[0][0],sum1[0][0]);
			ans+=min(sum[1][1],sum1[1][1]);
			ans+=min(sum[0][1],sum1[0][1]);
			ans+=min(sum[1][0],sum1[1][0]);
			ans+=(s1[a]==s2[b]);
		}else{
			if(a<b){
				swap(a,b);
				swap(sum,sum1);
				swap(s1,s2);
			}
			sum1[0][s2[b]-'0']++;
			ans+=min(sum[0][0],sum1[0][0]);
			ans+=min(sum[0][1],sum1[0][1]);
			sum[0][0]-=min(sum[0][0],sum1[0][0]);
			sum[0][1]-=min(sum[0][1],sum1[0][1]);
			sum[0][s1[a]-'0']++;
			ans+=min(sum[0][0],min(sum1[1][0],a-b));
			ans+=min(sum[0][1],min(sum1[1][1],a-b-min(sum[0][0],min(sum1[1][0],a-b))));
			sum1[1][0]-=min(sum[0][0],min(sum1[1][0],a-b));
			sum1[1][1]-=min(sum[0][1],min(sum1[1][1],a-b));
			ans+=min(sum[1][0],min(sum1[1][0],n-a));
			ans+=min(sum[1][1],min(sum1[1][1],n-a-min(sum[1][0],min(sum1[1][0],n-a))));
		}
		printf("%d\n",ans);
		return;
	}
	int x[2]={},y[2]={};
	int a=0,b=0;
	t1[n+1]='0';
	t2[n+1]='0';
	s1[n+1]='!';
	s2[n+1]='#';
	int last1[2]={};
	int last2[2]={};
	for(int i=1;i<=n+1;i++){
		if(t1[i]=='0'&&t2[i]=='0'){
			a=0,b=0;
		//	cout<<1111<<endl;
			ans+=min(x[0],y[0]);
			ans+=min(x[1],y[1]);
			ans+=(s1[i]==s2[i]);
			for(int j=0;j<=1;j++) x[j]=y[j]=last1[j]=last2[j]=0;
		}else  if(t1[i]=='0'){
			if(b!=0){
				ans+=min(x[1],last2[1]);
				ans+=min(x[0],last2[0]);
				last1[0]=x[0]-min(x[0],last2[0]);
				last1[1]=x[1]-min(x[1],last2[1]);
				x[0]=x[1]=0;
				x[s1[i]-'0']++;
				a=i;
			}else if(b==0){
				
				x[s1[i]-'0']++;
				y[s2[i]-'0']++;a=i;last1[0]=x[0];
				last1[1]=x[1];
				x[0]=x[1]=0;
			}
		}else if(t2[i]=='0'){
			if(a!=0){
				ans+=min(y[1],last1[1]);
				ans+=min(y[0],last1[0]);
				last2[0]=x[0]-min(y[0],last1[0]);
				last2[1]=x[1]-min(y[1],last1[1]);
				y[0]=y[1]=0;
				y[s2[i]-'0']++;
				b=i;
			}else if(a==0){
				
				x[s1[i]-'0']++;
				y[s2[i]-'0']++;b=i;
				last2[0]=y[0];
				last2[1]=y[1];
				y[0]=y[1]=0;
			}
		}else{
			x[s1[i]-'0']++;
			y[s2[i]-'0']++;
		}
		
//			cout<<"x="<<x[0]<<' '<<x[1]<<endl;
//			cout<<"y="<<y[0]<<' '<<y[1]<<endl;
//			cout<<"la"<<last1[0]<<' '<<last1[1]<<endl;
//			cout<<"lb"<<last2[0]<<' '<<last2[1]<<endl;
//			cout<<a<<' '<<b<<endl;
//			cout<<ans<<endl;
		
	}
	printf("%d\n",ans);
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
