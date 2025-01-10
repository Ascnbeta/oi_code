#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int s1[N],s2[N];
int ss1[N],ss2[N];
int ans;
queue<int>a,b;
int lt1,lt2;
int main() {
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=0;
		cin>>n;
		s1[0]=s2[0]=ss1[0]=ss2[0]=0;
		for(int i=1; i<=n; i++) {
			char s;
			cin>>s;
			if(s=='1') s1[i]=s1[i-1]+1;
			else s2[i]=s2[i-1]+1;
		}
		for(int i=1; i<=n; i++) {
			char s;
			cin>>s;
			if(s=='1') ss1[i]=ss1[i-1]+1;
		    else ss2[i]=ss2[i-1]+1;
		}
		for(int i=1;i<=n;i++)
	  {  char c;
	    cin>>c;
	  	if(c=='0') a.push(i);
	  }
	   for(int i=1;i<=n;i++)
	   {
	   	char c;
	   	cin>>c;
	   	if(c=='0') b.push(i);
	   }
	   lt1=lt2=1;
	   while(a.size()||b.size())
	   {   if(a.empty())
	      {
	      	int t=b.front();
			b.pop();
			int u=n;
			ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1]);
			if(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1]>=ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1])	   
		      {
		      	   s1[lt1-1]+=ss1[u]-ss1[lt2-1];
		      	   s2[lt1-1]+=ss2[u]-ss2[lt2-1];
		      	   ss1[lt2-1]+=ss1[u]-ss1[lt2-1];
		      	   ss2[lt2-1]+=ss2[u]-ss2[lt2-1];
		      	   lt2=t+1;
			  }
			  else{
			  	   ss1[lt1-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt1-1]+=s2[u]-s2[lt2-1];
		      	   ss1[lt2-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt2-1]+=s2[u]-s2[lt2-1];
		      	   lt2=t+1;
			  }
		  }                                                                                                                                                                                                             
		  else if(b.empty())
		  {
		  	int t=a.front();
	   	 	a.pop();
	   	 	int u=n;
	   	 		ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1]);
	   	     //ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[])	
			if(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1]>=ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1])	   
		      {
		      	   s1[lt1-1]+=ss1[u]-ss1[lt2-1];
		      	   s2[lt1-1]+=ss2[u]-ss2[lt2-1];
		      	   ss1[lt2-1]+=ss1[u]-ss1[lt2-1];
		      	   ss2[lt2-1]+=ss2[u]-ss2[lt2-1];
		      	   lt1=t+1;
			  }
			  else{
			  	   ss1[lt1-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt1-1]+=s2[u]-s2[lt2-1];
		      	   ss1[lt2-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt2-1]+=s2[u]-s2[lt2-1];
		      	   lt1=t+1;
			  }
		  }
	   	else if(a.front()<b.front())
	   	 {
	   	 	int t=a.front();
	   	 	a.pop();
	   	 	int u=b.front();
	   	 		ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1]);
	   	     //ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[])	
			if(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1]>=ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1])	   
		      {
		      	   s1[lt1-1]+=ss1[u]-ss1[lt2-1];
		      	   s2[lt1-1]+=ss2[u]-ss2[lt2-1];
		      	   ss1[lt2-1]+=ss1[u]-ss1[lt2-1];
		      	   ss2[lt2-1]+=ss2[u]-ss2[lt2-1];
		      	   lt1=t+1;
			  }
			  else{
			  	   ss1[lt1-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt1-1]+=s2[u]-s2[lt2-1];
		      	   ss1[lt2-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt2-1]+=s2[u]-s2[lt2-1];
		      	   lt1=t+1;
			  }
		}
		else{
			int t=b.front();
			b.pop();
			int u=a.front();
				ans+=min(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1],ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1]);
			if(s1[t]-s1[lt1-1]+s2[t]-s2[lt1-1]>=ss1[u]-ss1[lt2-1]+ss2[u]-ss2[lt2-1])	   
		      {
		      	   s1[lt1-1]+=ss1[u]-ss1[lt2-1];
		      	   s2[lt1-1]+=ss2[u]-ss2[lt2-1];
		      	   ss1[lt2-1]+=ss1[u]-ss1[lt2-1];
		      	   ss2[lt2-1]+=ss2[u]-ss2[lt2-1];
		      	   lt2=t+1;
			  }
			  else{
			  	   ss1[lt1-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt1-1]+=s2[u]-s2[lt2-1];
		      	   ss1[lt2-1]+=s1[u]-s1[lt2-1];
		      	   ss2[lt2-1]+=s2[u]-s2[lt2-1];
		      	   lt2=t+1;
			  }
		}
	   }
	   cout<<(abs)(ans)<<'\n';
	}
return 0;
}
