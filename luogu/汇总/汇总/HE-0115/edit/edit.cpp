#include<bits/stdc++.h>
using namespace std;
int t;
int n;
char a[100005];
char b[100005];
char c[100005];
char d[100005];

long long int ans;
priority_queue<int,vector<int>,greater<int> > q,p,pp,qq;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		while(q.size()){
			q.pop();
		}
		while(p.size()){
			p.pop();
		}
		while(qq.size()){
			qq.pop();
		}
		while(pp.size()){
			pp.pop();
		}
		ans=0;
		int e=0;
		int f=0;
		scanf("%d",&n);
		cin>>a>>b>>c>>d;
		
		int flag=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]!=flag){
				flag=2;
				break;
			}
		}
		if(flag!=2){
			for(int i=0;i<n;i++)
			{
				if(b[i]==flag){
					ans++;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(c[i]!=d[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(int i=0;i<n;i++)
			{
				if(c[i]=='0'){
					p.push(i);
				}
			}
			int j=0;
			while(p.size()){
				int js000=0,js0000=0;
				int js111=0,js1111=0;
				for(int i=j;i<p.top();i++)
				{
					if(a[i]=='0'){
						js000++;
					}else{
						js111++;
					}
					if(b[i]=='0'){
						js0000++;
					}else{
						js1111++;
					}
				}
				if(a[p.top()]==b[p.top()]){
					ans++;
				}
				ans+=min(js000,js0000);
				ans+=min(js111,js1111);
				j=p.top()+1;
				p.pop();
			}
			int js000=0,js0000=0;
			int js111=0,js1111=0;
			for(int i=j;i<n;i++)
			{
				if(a[i]=='0'){
					js000++;
				}else{
					js111++;
				}
				if(b[i]=='0'){
					js0000++;
				}else{
					js1111++;
				}
			}
			ans+=min(js000,js0000);
			ans+=min(js111,js1111);
			printf("%lld",ans);
			cout<<endl;
			continue;
		}
		
		flag=0;
		int jjjj=0;
		int jj,jjj;	
		for(int i=0;i<n;i++)
		{
			if(c[i]=='0'){
				flag++;
				if(flag>1){
					break;
				}
				jj=i;
			}
			if(d[i]=='0'){
				jjjj++;
				if(jjjj>1){
					break;
				}
				jjj=i;
			}
		}
		if(flag==1&&jjjj==1){
			int js0=0,js00=0;
			int js1=0,js11=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==b[jjj]&&c[jjj]=='1'){
					if(jj>jjj){
						if(i<jj){
							swap(a[i],a[jjj]);
							c[jjj]=0;
						}
					}
					if(jj<jjj){
						if(i>jj){
							swap(a[i],a[jjj]);
							c[jjj]=0;
						}
					}
				}
				if(b[i]==a[jj]&&d[jj]=='1'){
					if(jj>jjj){
						if(i>jjj){
							swap(b[i],b[jj]);
							d[jj]=0;
						}
					}
					if(jj<jjj){
						if(i<jjj){
							swap(b[i],b[jj]);
							d[jj]=0;
						}
					}
				}
			}
			c[jjj]=1;
			d[jj]=1;
			for(int i=0;i<n;i++)
			{
				if(a[i]==b[i]){
					continue;
				}
				for(int j=i+1;j<n;j++)
				{
					if(a[i]==b[j]&&(d[j]>jj&&d[j]<jjj || d[j]>jjj&&d[j]<jj)){
						swap(b[i],b[j]);
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				if(a[i]==b[i]){
					ans++;
				}
			}
			printf("%lld",ans);
			cout<<endl;
			continue;
		}
		
		for(int i=0;i<n;i++)
		{
			if(c[i]=='0'){
				q.push(i);
				p.push(i);
			}
			if(d[i]=='0'){
				pp.push(i);
				qq.push(i);
			}
		}
		if(p.size()==0 || q.size()==0){
			int js0=0,js1=0;
			int js00=0,js11=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]=='0'){
					js0++;
				}else{
					js1++;
				}
				if(b[i]=='0'){
					js00++;
				}else{
					js11++;
				}
			}
			ans+=min(js0,js00);
			ans+=min(js1,js11);
			printf("%lld",ans);
			cout<<endl;
			continue;
		}
		if(q.size()){
			f=q.top();	
			q.pop();
		}
		while(pp.size()){
			if(pp.top()==e||pp.top()==f){
				pp.pop();
				continue;
			}
			if(pp.top()<f){
				for(int i=e;i<f;i++)
				{
					if(a[i]==b[pp.top()]){
						if(i==pp.top()){
							pp.pop();
						}else{
							swap(a[i],a[pp.top()]);
							pp.pop();
						}
						break;
					}
				}
			}else{
				e=f+1;
				if(q.size()){
					f=q.top();
					q.pop();
				}else{
					while(pp.size()){
						for(int i=e;i<n;i++)
						{
							if(a[i]==b[pp.top()]){
								if(i==pp.top()){
									pp.pop();
								}else{
									swap(a[i],a[pp.top()]);
									pp.pop();	
								}
								break;
							}
						}
					}
				}
			}
		}
		int x=0;
		while(qq.size()){
			for(int i=x;i<qq.top();i++)
			{
				if(a[i]==b[i]){
					continue;
				}
				if( i+1 >= p.top()){
					p.pop();
					if(p.size()==0){
						p.push(n);
					}
				}
				for(int j=i+1;j<p.top();j++)
				{
					if(a[j]==b[i]){
						swap(a[i],a[j]);
						continue;
					}
				}
			}
			x=qq.top()+1;
			qq.pop();
		}
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i]){
				ans++;
			}
		}
		printf("%lld",ans);
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
