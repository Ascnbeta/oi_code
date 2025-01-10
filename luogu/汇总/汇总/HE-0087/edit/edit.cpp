#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

inline int max(int x,int y) { return x>y?x:y; }
inline int min(int x,int y) { return x<y?x:y; }

//bool vis[1<<20][2];
int t[3][3];
int ans;

string s1,s2,s3,s4;

int n;

void solve1()
{
	for(int i=0;i<n;i++) ans+=s1[i]==s2[i];
}

void solve2()
{
	for(int i=0;i<n;i++)
	{
		if(s3[i]=='0') 
		{
			ans+=s1[i]==s2[i];
			ans+=min(t[1][0],t[2][0])+min(t[1][1],t[2][1]);
			
			t[1][0]=t[2][0]=t[1][1]=t[2][1]=0;
		}
		else 
		{
			int nw1=s1[i]-'0',nw2=s2[i]-'0';
			t[1][nw1]++;
			t[2][nw2]++;
		}
	}
	ans+=min(t[1][0],t[2][0])+min(t[1][1],t[2][1]);
}

/*
void solve3()
{
	int l[3][2]={},r[3][2]={};
	
	int i=0,p1,p2;
	for(i=0;i<n&&s3[i]=='1';i++) l[1][s1[i]-'0']++;
	p1=i;
	for(++i;i<n;i++) r[1][s1[i]-'0']++;
	
	
	for(i=0;i<n&&s4[i]=='1';i++) l[2][s2[i]-'0']++;
	
	p2=i;
	for(++i;i<n;i++) r[2][s2[i]-'0']++;
	
	if(p1==p2)
		ans=min(l[1][0],l[2][0])+min(l[1][1],l[2][1])+min(r[1][0],r[2][0])+min(r[1][1],r[2][1]);
	if(p1>p2)
	{
		ans=min(l[1][0],l[2][0])+min(l[1][1],l[2][1])+min(r[1][0],r[2][0])+min(r[1][1],r[2][1]);
		ans+=(r[2][s1[p1]-'0']!=r[1][s1[p1]-'0']);
		ans+=(l[2][s2[p2]-'0']!=l[2][s2[p2]-'0']);
	}
	if(p1<p2)
	{
		ans=min(l[1][0],l[2][0])+min(l[1][1],l[2][1])+min(r[1][0],r[2][0])+min(r[1][1],r[2][1]);
		ans+=(l[2][s1[p1]-'0']!=l[1][s1[p1]-'0']);
		ans+=(r[2][s2[p2]-'0']!=r[2][s2[p2]-'0']);
	}
}
*/
void Baoli()
{
	
	for(int i=0;i<n;i++)
	{
		bool f=0;
		int nw=i-1;
		if(s1[i]==s2[i])
		{
			ans++;
			continue;
		}
		
		while(s4[++nw]=='1')
		{
			if(s1[i]==s2[nw])
			{
				swap(s2[nw],s2[i]);
				ans++;
				
		//		cout<<i<<" "<<nw<<"\n";
				
				f=1;
				break;
			}
		}
		if(f) continue;
		
		nw=i-1;
		while(s3[++nw]=='1')
		{
			if(s1[nw]==s2[i])
			{
				swap(s1[nw],s1[i]);
				ans++;
				
		//		cout<<i<<" "<<nw<<"\n";
				break;
			}
		}
		
	}
}

void solve()
{
//	memset(need,0,sizeof(need));
	memset(t,0,sizeof(t));
//	memset(vis,0,sizeof(vis));
	ans=0;
	
	n=read();
	cin>>s1>>s2>>s3>>s4;
	
	if(s3==s4) solve2();
	else
	{
		int tot=1;
		for(int i=1;i<n;i++) tot+=s1[i]==s1[i-1];
		
		if(tot==n) solve1();
		else Baoli();
	}
	
	/*
	for(int i=0;i<n;i++)
	{
		if(s3[i]=='0'&&s4[i]=='0')
		{
			ans+=s1[i]==s2[i];
			ans+=max(0ll,min(t[1][0],t[2][0]))+max(0ll,min(t[1][1],t[2][1]));
		
//			need[1][0]=need[1][1]=need[2][0]=need[2][1]=0;
			t[1][0]=t[1][1]=t[2][0]=t[2][1]=0;
		}
		else if(s3[i]=='0')
		{
			if(t[2][s2[i]-'0']<0) ans++;
			t[2][s2[i]-'0']++;
			
			ans+=max(0ll,min(t[1][0],t[2][0]))+max(0ll,min(t[1][1],t[2][1]));
			t[2][0]-=t[1][0];
			t[2][1]-=t[1][1];
			t[2][s1[i]-'0']--;
			
			t[1][0]=t[1][1]=0;
		//	
		//	if(t[2][s1[i]-'0']>0)
		//	{
		//		t[2][s1[i]-'0']--;
		//		ans++;
		//	}
		}
		else if(s4[i]=='0')
		{
			if(t[1][s1[i]-'0']<'0') ans++;
		//	if(t[1][s1[i]-'0']=='0') t[1][s1[i]-'0']++;
		//	if(t[1][s1[i]-'0']>'0') 
			
			t[1][0]-=t[2][0];
			t[1][1]-=t[2][1];
			t[1][s2[i]-'0']--;
			
		}
		else
		{
			t[1][s1[i]-'0']++;
			t[2][s1[i]-'0']++;
			
			if(t[1][0]>0&&t[2][0]>0)
			{
				int Dt=min(t[1][0],t[2][0]);
				ans+=Dt;
				t[1][0]-=Dt;
				t[2][0]-=Dt;
			}
			if(t[1][1]>0&&t[2][1]>0)
			{
				int Dt=min(t[1][1],t[2][1]);
				ans+=Dt;
				t[1][1]-=Dt;
				t[2][1]-=Dt;
			}
			
	//		t[1][s2[i]-'0']--;
	//		t[2][s1[i]-'0']--;
		}
	}
	*/
	/*
	for(int i=0;i<n;i++)
	{
		if(s3[i]=='1') t[1][s1[i]-'0']++;
		if(s4[i]=='1') t[2][s2[i]-'0']++;
	}
	
	cout<<t[1][0]<<" "<<t[1][1]<<"\n"<<t[2][0]<<" "<<t[2][1]<<" \n";
	
	for(int i=0;i<n;i++)
	{
		if(s3[i]=='0'&&s4[i]=='0'&&s1[i]==s2[i]) ans++;
		else if(s3[i]=='0')
		{
			if(s1[i]=='0'&&t[2][0]) t[2][0]--,ans++;
			if(s1[i]=='1'&&t[2][1]) t[2][1]--,ans++;
		}
		else if(s4[i]=='0')
		{
			if(s2[i]=='0'&&t[1][0]) t[1][0]--,ans++; 
			if(s2[i]=='1'&&t[1][1]) t[1][1]--,ans++;
		}
	}
	
	ans+=min(t[1][0],t[2][0])+min(t[1][1],t[2][1]);
	*/
	write(ans);
	putchar('\n');
}

signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int t=read();
	while(t--) solve();
	
	return 0;
}

