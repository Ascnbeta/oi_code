#include<bits/stdc++.h>
using namespace std;
int n,T,MAXN=0x7fffffff;
const int N=1e5+7;
long long ans;
int a[N],b[N],fa[N],fb[N];
char init[N];
long long sum1,sum2;
struct node
{
	int l,r=MAXN,w1,w2;
}k1[N],k2[N];
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		bool f1=true,f2=true;
	//init
		cin>>n;
		//a
		cin>>(init+1);
		for (int i=1;i<=n;i++)
		{
			if (init[i]=='0') a[i]=0;
			else if (init[i]=='1') a[i]=1;
			sum1+=a[i];
			if(i>1 && a[i]!=a[i-1])f1=false;
		}
		//b
		cin>>(init+1);
		for (int i=1;i<=n;i++)
		{
			if (init[i]=='0')b[i]=0;
			else if (init[i]=='1')b[i]=1;
			sum2+=b[i];
		}
		//fa
		//cnt1：a的区间数 
		cin>>(init+1);
		int cnt1=1;k1[1].l=1;
//		for (int i=1;i<=n;i++)
//		{
//			if (init[i]=='0')fa[i]=0;
//			else if (init[i]=='1')fa[i]=1;
//			if (fa[i]==0)
//			{
//				k1[cnt1].r=i,k1[cnt1+1].l=i+1,
//				k1[cnt1].w1=sum1[i]-sum1[k1[cnt1].l-1]-a[i], k1[cnt1].w2=i-k1[cnt1].l+1-k1[cnt1].w1;
//				if(i!=n)cnt1++;
//			}
//		}
//		
//		//fb
//		cin>>(init+1);
//		int cnt2=1;k2[1].l=1;
//		for (int i=1;i<=n;i++)
//		{
//			if (init[i]=='0')fb[i]=0;
//			else if (init[i]=='1')fb[i]=1;
//			if(fb[i]==0)
//			{
//				k2[cnt2].r=i,k2[cnt2+1].l=i+1,
//				k2[cnt2].w1=sum2[i]-sum2[k2[cnt2].l-1]-b[i],k2[cnt2].w2=i-k2[cnt2].l+1-k2[cnt2].w1;
//				if(i!=n)cnt2++;
//			}
//		}
		fa[0]=fa[n+1]=fb[0]=fb[n+1]=0;
	//body
		for (int i=1;i<=n;i++)
		{
			if (fa[i]!=fb[i])
			{
				f2=false;
				break;
			}
		}
		if (f1==true)
		{
			if (a[1]==0)
			{
				cout<<n-sum2<<'\n';
			}
			else if (a[1]==1)
				cout<<sum2<<'\n';
		}
//		cout<<n<<" "<<sum2;
		else if (f2==true)
		{
			for (int i=1;i<=cnt2;i++)
			{
				int byds=k2[i].w1-b[k2[i].r];
				int ayds=k1[i].w1-a[k1[i].r];
				ans+=abs(ayds-byds);
				ans+=(b[k2[i].r]==a[k1[i].r]);
			}
			cout<<ans;
		}
	}
	return 0;
}
