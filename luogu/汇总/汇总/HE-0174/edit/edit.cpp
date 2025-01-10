#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool s1[100005],s2[100005];
bool t1[100005],t2[100005];
int cnt=0;
string readtmp;

void reads(bool *dest,int len){
//	getchar();
	getline(cin,readtmp);
	for(int i=0;i<len;i++)	dest[i]=readtmp[i]-'0';
//	getchar();
//	for(int i=0;i<len;i++)	dest[i]=getchar()-'0';
}
bool fndequ(bool *stat,bool *sear,bool f,int s,int e){
	for(int i=s;i<e;i++){
		if(stat[i]==0)	return 0;
		if(stat[i]==1 && sear[i]==f){	//swap sear[i] sear[s-1]
			int tmp=sear[i];
			sear[i]=sear[s-1];
			sear[s-1]=tmp;
			return 1;
		}
	}
	return 0;
}
void fnd(int len){
	for(int i=0;i<len;i++){
		if(s1[i]==s2[i]){
			cnt++;
			continue;
		}
		if(t1[i] && !t2[i]){	//can only move s1
			cnt+=fndequ(t1,s1,s2[i],i+1,len);
			continue;
		}
		if(!t1[i] && t2[i]){	//can only move s2
			cnt+=fndequ(t2,s2,s1[i],i+1,len);
			continue;
		}
		if(t1[i] && t2[i]){	//s1,then s2
			bool p=fndequ(t1,s1,s2[i],i+1,len);
			if(!p)	p=fndequ(t2,s2,s1[i],i+1,len);
			cnt+=p;
			continue;
		}
	}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	for(scanf("%d",&T);T>0;T--){
		cnt=0;
		int n;
		scanf("%d",&n);
		getchar();
		reads(s1,n);
		reads(s2,n);
		reads(t1,n);
		reads(t2,n);
		fnd(n);
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
