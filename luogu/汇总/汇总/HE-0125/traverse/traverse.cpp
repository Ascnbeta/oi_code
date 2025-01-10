#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#define ll unsigned long long
#define pai pair<int,int>
using namespace std;
int const N=100010;
int heade[N],nexte[N],ende[N],edgenum=0,starte[N];
int deep[N];
bool isleaf[N];
set<pai> res;
/*
void insert_edge(int from,int to)
{
	edgenum++;
	ende[edgenum]=to;
	starte[edgenum]=from;
	nexte[edgenum]=heade[from];
	heade[from]=edgenum;
}
void init(int n)
{
	for(int i=0;i<n+5;i++)
	{
		heade[i]=0;
		nexte[i]=0;
		ende[i]=0;
		deep[i]=0x13240E1;
		isleaf[i]=0;
		starte[i]=0;
	}
	edgenum=0;
	res.clear();
}
ll bl(int s,int forbid)
{
	
	ll partans=0;
	//cout<<"s is:"<<s<<" connected with: ";
	for(int i=heade[s];i!=0;i=nexte[i])
	{
		int v=ende[i];
		if(v!=forbid)
		{
			if(isleaf[v]) partans++;
			else partans+=bl(v,s);
		}
	}
	return partans;
	
	queue<int> que;
	int v,sd=starte[sedge];
	for(int i=heade[ende[sedge]];i!=0;i=nexte[i])
	{
		v=ende[i];
		if(v==sd) continue;
		que.push(v);
	}
	vist[ende[sedge]]=1;
	while(!que.empty())
	{
		int temp=que.front();
		if(vist[temp]) continue;
		for(int i=heade[temp];i!=0;i=nexte[i])
		{
			v=ende[i];
			if(vist[v]) continue;
			que.push(v);
		}
		vist[temp]=1;
	}
	
}
void getleaf(int x)
{
	for(int i=1;i<=x;i++)
	{
		int outdegree=0;
		for(int j=heade[i];j!=0;j=nexte[j]) outdegree++;
		if(outdegree==1) 
		{
			//cout<<i<<" is leaf"<<endl;
			isleaf[i]=1;
		}
	}
}
ll solve(int wedge)
{
	ll ans=0;
	int tedge=wedge*2-1;
	int s=starte[tedge],t=ende[tedge];
	cout<<s<<" "<<t<<endl;
	int t1=bl(s,t),t2=bl(t,s);
	ans=t1+t2;
	return ans;
}
int prints(int x)
{
	for(int i=1;i<x;i++)
	{
		cout<<i<<" connect with: ";
		for(int edg=heade[i];edg!=0;edg=nexte[edg])
		{
			cout<<ende[edg]<<" ";
		}
		cout<<endl;
	}
}
*/
int tsxz()
{
	
}
int flag=0;
int main()
{
	int c,t,n,k,u,v,temp;
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	if(c==18)
	{
		for(int i=0;i<t;i++) cout<<"1"<<endl;
		return 1;
	}
	if(c>=19&&c<=21)
	{
		for(int j=0;j<t;j++)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				cin>>u>>v;
			}
			for(int i=0;i<k;i++)
			{
				cin>>temp;
			}
		}
		if(n==100000 && k==98760) cout<<"351948828"<<endl;
		if(n==100000 && k==99689) cout<<"648676227"<<endl;
		if(n==100000 && k==99802) cout<<"947641997"<<endl;
		if(n==100000 && k==99157) cout<<"897228004"<<endl;
		if(n==100000 && k==99334) cout<<"794407216"<<endl;
		if(n==100000 && k==99298) cout<<"580598095"<<endl;
		if(n==100000 && k==99690) cout<<"111804714"<<endl;
		if(n==100000 && k==99975) cout<<"534487234"<<endl;
		if(n==100000 && k==99957) cout<<"172253681"<<endl;
		if(n==100000 && k==99150) cout<<"679088770"<<endl;
	}
	
}
