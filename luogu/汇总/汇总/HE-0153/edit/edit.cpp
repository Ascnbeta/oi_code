//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+5;
//int t,n,num;
//int ct1[3],ct2[3],cs1[3],cs2[3],ct10[3],ct20[3],cs10=0,cs11=0,cs20=0,cs21=0;
//int s1[N],s2[N],t1[N],t2[N];
//int main(){
//	freopen("edit.in","r",stdin);
//	freopen("edit.out","w",stdout);
//	cin>>t;
//	while(t--){
//		cin>>n;num=0;
//		for(int i=1;i<=n;i++) scanf("%1d",&s1[i]);
//		for(int i=1;i<=n;i++) scanf("%1d",&s2[i]);
//		for(int i=1;i<=n;i++) scanf("%1d",&t1[i]);
//		for(int i=1;i<=n;i++) scanf("%1d",&t2[i]);
//		for(int i=1;i<=n;i++){
//			if(t1[i]==1) cs1[s1[i]]++;
//			if(t2[i]==1) cs2[s2[i]]++;
//			
//			if(t1[i]==0) ct1[s1[i]]++;
//			if(t2[i]==0) ct2[s2[i]]++;
//			if(t1[i]==0&&t2[i]==0){
//				num+=min(cs1[1]+cs11+ct1[1],cs2[1]+cs21+ct2[1])+min(cs1[0]+cs10+ct1[0],cs2[0]+cs20+ct2[0]); 
//				cs10=0;cs11=0;cs20=0;cs21=0;
//				cs1[0]=0;cs1[2]=0;cs2[1]=0;cs2[0]=0;
//			}			
//			else if(t1[i]==0){
//				num+=min(cs1[1]+cs11+ct1[1],cs2[1])+min(cs1[0]+cs10+ct1[0],cs2[0]);
//				cs10=cs1[0];cs11=cs1[1];
//				cs1[0]=0;cs1[1]=0;
//				ct1[0]=ct1[1]=0;
//				
//			}
//			else if(t2[i]==0){
//				num+=min(cs2[1]+cs21+ct2[1],cs1[1])+min(cs2[0]+cs20+ct2[0],cs1[0]);
//				cs20=cs2[0];cs21=cs2[1];
//				cs2[0]=0;cs2[1]=0;
//				ct2[0]=ct2[0]=0;
//			}									
//		}
//		printf("%d\n",num);
//	}
//	
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,num;
int c10=0,c11=0,c20=0,c21=0;
int s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;num=0;
		for(int i=1;i<=n;i++) scanf("%1d",&s1[i]);
		for(int i=1;i<=n;i++) scanf("%1d",&s2[i]);
		for(int i=1;i<=n;i++) scanf("%1d",&t1[i]);
		for(int i=1;i<=n;i++) scanf("%1d",&t2[i]);
		for(int i=1;i<=n;i++){
			if(s1[i]==0) c10++;
			if(s1[i]==1) c11++;
			if(s2[i]==0) c20++;
			if(s2[i]==1) c21++;			
			if(t1[i]==0||t2[i]==0){
				num+=min(c10,c20)+min(c11,c21);
				c10=0;c11=0;c20=0;c21=0;
			}						
		}
		printf("%d\n",num);
	}
	
	return 0;
}
