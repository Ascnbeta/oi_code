#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int read(){
	int s=0,f=1;
	char _z=getchar();
	while(_z<'0'||_z>'9'){
		if(_z=='-')
		f=-1;
		_z=getchar();
	}
	while(_z>='0'&&_z<='9'){
		s=(s<<3)+(s<<1)+(_z-'0');
		_z=getchar();
	}
	return s*f;
}
const int N=1e5+10;
int s1[N],s2[N],tot[3][3];
bool pd1[N],pd2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t=read();
	while(t--){
		tot[1][0]=tot[2][0]=tot[1][1]=tot[2][1]=0;
		bool flagA=true,flagB=true,flagC=true;
		int flagC_one=0,flagC_two=0;
		int n=read(),ans=0;
		for(int i=1;i<=n;i++){
			char _z=getchar();
			while(_z!='0'&&_z!='1')
			_z=getchar();
			s1[i]=_z-'0';
		}
		for(int i=2;i<=n;i++)
		if(s1[i]!=s1[i-1]){
			flagA=false;
			break;
		}
		for(int i=1;i<=n;i++){
			char _z=getchar();
			while(_z!='0'&&_z!='1')
			_z=getchar();
			s2[i]=_z-'0';
		}
		for(int i=1;i<=n;i++){
			char _z=getchar();
			while(_z!='0'&&_z!='1')
			_z=getchar();
			pd1[i]=_z-'0';
			if(!pd1[i]){
				if(!flagC_one)
				flagC_one=i;
				else
				flagC=false;
			}
		}
		for(int i=1;i<=n;i++){
			char _z=getchar();
			while(_z!='0'&&_z!='1')
			_z=getchar();
			pd2[i]=_z-'0';
			if(pd1[i]!=pd2[i])
			flagB=false;
			if(!pd2[i]){
				if(!flagC_two)
				flagC_two=i;
				else
				flagC=false;
			}
		}
		if(!flagC_one||!flagC_two)
		flagC=false;
		if(flagA){
			for(int i=1;i<=n;i++)
			tot[2][s2[i]]++;
			printf("%d\n",tot[2][s1[1]]);
			continue;
		}else if(flagB){
			for(int i=1;i<=n;i++){
				if(!pd1[i]&&!pd2[i]){
					ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
					if(s1[i]==s2[i])
					ans++;
					tot[1][0]=tot[2][0]=tot[1][1]=tot[2][1]=0;
				}else{
					tot[1][s1[i]]++;
					tot[2][s2[i]]++;
				}
			}
			printf("%d\n",ans);
			continue;
		}else if(flagC){
			if(flagC_one<flagC_two){
				for(int i=1;i<=flagC_one;i++)
				tot[1][s1[i]]++;
				for(int i=1;i<flagC_two;i++)
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				tot[2][0]=max(tot[2][0]-tot[1][0],0);
				tot[2][1]=max(tot[2][1]-tot[1][1],0);
				tot[1][0]=tot[1][1]=0;
				for(int i=flagC_one+1;i<=n;i++)
				tot[1][s1[i]]++;
				for(int i=flagC_two;i<=n;i++)
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				printf("%d\n",ans);
			}else{
				for(int i=1;i<flagC_one;i++)
				tot[1][s1[i]]++;
				for(int i=1;i<=flagC_two;i++)
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				tot[1][0]=max(tot[1][0]-tot[2][0],0);
				tot[1][1]=max(tot[1][1]-tot[2][1],0);
				tot[2][0]=tot[1][0]=0;
				for(int i=flagC_one;i<=n;i++)
				tot[1][s1[i]]++;
				for(int i=flagC_two+1;i<=n;i++)
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				printf("%d\n",ans);
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(pd1[i]&&pd2[i]){
				tot[1][s1[i]]++;
				tot[2][s2[i]]++;
			}else if(!pd1[i]&&!pd2[i]){
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				if(s1[i]==s2[i])
				ans++;
				tot[1][0]=tot[2][0]=tot[1][1]=tot[2][1]=0;
			}else if(!pd1[i]){
				tot[1][s1[i]]++;
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				tot[2][0]=max(tot[2][0]-tot[1][0],0);
				tot[2][1]=max(tot[2][1]-tot[1][1],0);
				tot[1][0]=tot[1][1]=0;
			}else if(!pd2[i]){
				tot[1][s1[i]]++;
				tot[2][s2[i]]++;
				ans+=min(tot[1][0],tot[2][0])+min(tot[1][1],tot[2][1]);
				tot[1][0]=max(tot[1][0]-tot[2][0],0);
				tot[1][1]=max(tot[1][1]-tot[2][1],0);
				tot[2][0]=tot[1][0]=0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
