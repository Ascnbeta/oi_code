#include<bits/stdc++.h>
using namespace std;
long long n,ans,t;
string a1,b1,a2,b2;
struct edit{
	long long num,val;
};
long long c[100005];
edit a[100005],b[100005];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout); 
	cin>>t;
	while(t--){//
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n;
	cin>>a1>>b1>>a2>>b2;
	int nn=0,ss0=0,tt0=0;
	for(int i=1;i<=n;i++){
		a[i].num=a1[i-1]-'0';
		if(a[i].num!=a[i-1].num&&i!=1){
			nn++;
		}
	}
	for(int i=1;i<=n;i++){
		b[i].num=b1[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		a[i].val=a2[i-1]-'0';
		if(a[i].val==0){
			ss0++;
		}
	}
	for(int i=1;i<=n;i++){
		b[i].val=b2[i-1]-'0';
		if(b[i].val==0){
			tt0++;
		}
	}
	int nn1=0;
	for(int i=1;i<=n;i++){
		if(a[i].val!=b[i].val){
			nn1++;
		}
	}
	if(nn==0){
		for(int i=1;i<=n;i++){
			if(a[i].num==b[i].num){
				ans++;
			}
		}
	}else if(nn1==0){
		for(int i=1;i<=n;i++){
			if(a[i].val==0){
				c[i]=1;
				if(a[i].num==b[i].num){
					ans++;
				} 
			}
		}
		int s1=0,s0=0,t1=0,t0=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=1){
				if(a[i].num==1){
					s1++;
				}else{
					s0++;
				}
				if(b[i].num==1){
				    t1++;
			    }else{
			        t0++; 
	     	    }
			}else{
				ans+=min(s1,t1);
				ans+=min(s0,t0);
				s1=0,t1=0,s0=0,t0=0;
			}
		}
		ans+=min(s1,t1);
		ans+=min(s0,t0);
	}else if(ss0==1&&tt0==1){
		int s1=0,s0=0,t1=0,t0=0;
	for(int i=1;i<=n;i++){
		if(a[i].num==1&&a[i].val!=0){
			s1++;
		}else if(a[i].val!=0){
			s0++;
		}
		if(b[i].num==1&&b[i].val!=0){
			t1++;
		}else if(b[i].val!=0){
			t0++;
		}
		if(a[i].val==0){
			ans+=min(s1,t1);
			ans+=min(s0,t0);
			s1=0;
			s0=0;
			t1=t1-min(s1,t1);
			t0=t0-min(s0,t0);
			if(a[i].num==1&&t1!=0){
				ans++;
				t1--;
			}else if(a[i].num==0&&t0!=0){
				ans++;
				t0--;
			}
		}else if(b[i].val==0){
			ans+=min(s1,t1);
			ans+=min(s0,t0);
			t1=0;
			t0=0;
			s1=s1-min(s1,t1);
		    s0=s0-min(s0,t0);
		    if(b[i].num==1&&s1!=0){
			ans++;
			s1--;
			}else if(b[i].num==0&&s0!=0){
				ans++;
				s0--;
			}
		}
	}
	ans+=min(s1,t1);
	ans+=min(s0,t0);
	}else{
		for(int i=1;i<=n;i++){
			if(a[i].num==b[i].num){
				ans++;
			}
		}
	}
	cout<<ans<<endl; 
	ans=0;
   }
   return 0;
}
