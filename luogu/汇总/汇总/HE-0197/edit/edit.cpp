#include<bits/stdc++.h>
using namespace std;


int T=0;
int len=0;
int s1[100005]={},s2[100005]={};
int t1[100005]={},t2[100005]={};
int t1number=0,t2number=0;
int t1swap[50000][4]={},t2swap[50000][4]={};
int ans=0;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf(" %d",&T);
	while(T-->0){
		memset(t1swap,0,sizeof(t1swap));
		memset(t2swap,0,sizeof(t2swap));
		//////////////////////////////////
		scanf("%d",&len);
		for(int i =0;i<len;i++){
			//;
			scanf(" %1d",&s1[i]);
			//getchar();
		}
		for(int i =0;i<len;i++){
			scanf(" %1d",&s2[i]);
		}
//		//////////////////////////////////
//		int ans=0;
		int temp1=1;
		for(int i =0;i<len;i++){
			scanf(" %1d",&t1[i]);
			if(temp1==1 && t1[i] ==1){
				t1swap[t1number][0]=i;
				temp1 = 0;
			}
			if(temp1==0 && t1[i] ==0){
				t1swap[t1number++][1]=i-1;
				temp1 = 1;
			}
			if(s1[i] ==1 && temp1 == 0) t1swap[t1number][2]++;
			if(s1[i] ==0 && temp1 == 0) t1swap[t1number][3]++;
		}
		if(t1swap[t1number][1]==0 && t1swap[t1number][0]!=0)t1swap[t1number++][1]=len-1;
//		//////////////////////////////////
//		ans=0;
		int temp2=1;
		for(int i =0;i<len;i++){
			scanf(" %1d",&t2[i]);
			if(temp2==1 && t2[i] ==1){
				t2swap[t2number][0]=i;
				temp2 = 0;
			}
			if(temp2==0 && t2[i] ==0){
				t2swap[t2number++][1]=i-1;
				temp2 = 1;
			}
			
			if(s2[i] ==1 && temp2 == 0) t2swap[t2number][2]++;
			if(s2[i] ==0 && temp2 == 0) t2swap[t2number][3]++;
			
			
		}
		if(t2swap[t2number][1]==0 && t2swap[t2number][0]!=0)t2swap[t2number++][1]=len-1;
//		//////////////////////////////////
		int flag1=0,flag2=0;
		for(int i =0;i<len;i++){
			
			if(i>t1swap[flag1][1]){
			flag1++;
				if(t1swap[flag1][0] == 0 && 
			t1swap[flag1][1] == 0 && 
			t1swap[flag1][2] == 0 && 
			t1swap[flag1][3] == 0){
				t1swap[flag1][0] = t1swap[flag1][1] = len;
			}
			
			}
			if(i>t2swap[flag2][1]){
				flag2++;
				if(t2swap[flag2][0] == 0 && 
			t2swap[flag2][1] == 0 && 
			t2swap[flag2][2] == 0 && 
			t2swap[flag2][3] == 0){
				t2swap[flag2][0] = t2swap[flag2][1] = len;
			}
			}
			
			if(i>=t2swap[flag2][0]){
				
				if(i>=t1swap[flag1][0]){
					if(t1swap[flag1][2]>0 && t2swap[flag2][2]>0){
						t1swap[flag1][2]--;
						t2swap[flag2][2]--;
						ans++;
					}
					else if(t1swap[flag1][3]>0 && t2swap[flag2][3]>0){
						t1swap[flag1][3]--;
						t2swap[flag2][3]--;
						ans++;
					}
				}
				
				else{
					if(s1[i]==1 && t2swap[flag2][2]>0){
						t2swap[flag2][2]--;
						ans++;
					}
					if(s1[i]==0 && t2swap[flag2][3]>0){
						t2swap[flag2][3]--;
						ans++;
					}
				}
			}
			else if(i>=t1swap[flag1][0]){
				if(s2[i]==1 && t1swap[flag1][2]>0){
						t1swap[flag1][2]--;
						ans++;
					}
				if(s2[i]==0 && t1swap[flag1][3]>0){
					t1swap[flag1][3]--;
					ans++;
				}
			}
			else if(s1[i]==s2[i]) ans++;
//			if(i>t1number && i>t2number){
//				break;
//			}
		}
		printf("%d",ans);
		printf("\n");
		ans=0;
		t1number=0,t2number=0;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




