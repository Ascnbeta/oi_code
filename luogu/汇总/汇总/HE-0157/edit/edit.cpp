#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
//struct jtr{
//	int l,r;
//	bool able_move;
//	int numof_one;
//}a[inf],b[inf];
struct qwq{
	int num[2],kr;
	bool del_tag[2];
}ka,kb;
char s1[inf],s2[inf],t1[inf],t2[inf];
int t,n,/*posa[inf],posb[inf],*/ans;//pos : pos->cnt
void ina(int i){
//	cout<<"init";
//	cout<<t1[1]<<endl;
	ka.kr=i;
	if(t1[i]=='0'){
//		cout<<"is 0"<<endl;
		ka.num[s1[i]=='1']++;
		ka.del_tag[s1[i]=='1']=1;
	}
	else{
		while(t1[ka.kr]=='1'){
			ka.num[s1[ka.kr]=='1']++;
			ka.kr++;
		}
		ka.kr--;
	}
}
void inb(int i){
	kb.kr=i;
	if(t2[i]=='0'){
		kb.num[s2[i]=='1']++;
		kb.del_tag[s2[i]=='1']=1;
	}
	else{
//		cout<<"tiii"<<endl;
		while(t2[kb.kr]=='1'){
			kb.num[s2[kb.kr]=='1']++;
			kb.kr++;
		}
		kb.kr--;
	}
}
void clear(){
	ans=0;
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(t1,0,sizeof(t1));
	memset(t2,0,sizeof(t2));
	ka.num[0]=ka.num[1]=ka.kr=ka.del_tag[0]=ka.del_tag[1]=0;
	kb.num[0]=kb.num[1]=kb.kr=kb.del_tag[0]=kb.del_tag[1]=0;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int cnti=1;cnti<=t;cnti++){
		clear();
		scanf("%d",&n);
		cin>>s1+1>>s2+1>>t1+1>>t2+1;
		bool flag_0=0,flag_1=0;
		for(int i=1;i<=n;i++){
			if(s1[i]=='0') flag_0=1;
			if(s1[i]=='1') flag_1=1;
		}
		if(flag_0&&!flag_1){//all 1
			for(int i=1;i<=n;i++){
				if(s2[i]=='0') ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		if(!flag_0&&flag_1){//all 0
			for(int i=1;i<=n;i++){
				if(s2[i]=='1') ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		ina(1);
		inb(1);
//		cout<<ka.num[0]<<" "<<ka.num[1]<<" "<<kb.num[0]<<" "<<kb.num[1]<<endl;
		while(min(ka.kr,kb.kr)<n){
			if((!ka.num[0]&&!kb.num[1])||(!ka.num[1]&&!kb.num[0])){
//				cout<<"nojian"<<ka.kr<<" "<<kb.kr<<" "<<ka.num[0]<<" "<<ka.num[1]<<" "<<kb.num[0]<<" "<<kb.num[1]<<" "<<ans<<endl;;
				ka.num[0]-=ka.del_tag[0];
				ka.num[1]-=ka.del_tag[1];
				kb.num[0]-=kb.del_tag[0];
				kb.num[1]-=kb.del_tag[1];
				ka.del_tag[0]=ka.del_tag[1]=kb.del_tag[0]=kb.del_tag[1]=0;
			}
			else{
//				cout<<"jian"<<endl;
				int m0=min(ka.num[0],kb.num[0]),m1=min(ka.num[1],kb.num[1]);
				ka.num[1]-=m1;
				ka.num[0]-=m0;
				kb.num[1]-=m1;
				kb.num[0]-=m0;
				ka.del_tag[0]=ka.del_tag[1]=kb.del_tag[0]=kb.del_tag[1]=0;
				ans+=m0+m1;
//				cout<<ka.num[0]<<" "<<ka.num[1]<<" "<<kb.num[0]<<" "<<kb.num[1]<<" "<<ans<<endl;
			}
			if(ka.kr>kb.kr){
//				cout<<ka.kr<<" "<<kb.kr<<"a>b"<<kb.num[0]<<" "<<kb.num[1]<<endl;
				inb(kb.kr+1);
//				cout<<ka.kr<<" "<<kb.kr<<" "<<kb.num[0]<<" "<<kb.num[1]<<endl;
				continue;
			} 
			if(ka.kr<kb.kr){
//				cout<<ka.kr<<" "<<kb.kr<<"a<b"<<endl;
				ina(ka.kr+1);
				continue;
			}
			if(ka.kr==kb.kr){
//				cout<<ka.kr<<" "<<kb.kr<<" "<<ans;
//				cout<<"a=b"<<endl;
				ina(ka.kr+1);
				inb(kb.kr+1);
			}
//			cout<<ka.kr<<" "<<kb.kr<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
6
011101
111010
111010
101101
*/
