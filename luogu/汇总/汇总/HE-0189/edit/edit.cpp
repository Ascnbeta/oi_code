#include<bits/stdc++.h>
using namespace std;

string sf,ss;
string tf,ts;
string sy1,sy2;
int T;//多组数据，记得clear 
int n;
int sum;

int s_1[100009],s_2[100009];

struct Node_2{
	int num_0,num_1;
	int be,en;
};
vector<Node_2>son_1;
vector<Node_2>son_2;
void part_1(bool fors){
	string s,t;
	if(fors){
		s=sf;t=tf;
	}else{
		s=ss;t=ts;
	}
	Node_2 now; 
	now.num_0=0;now.num_1=0;
	bool kai =false;
	bool full=false;
	int x=0;
	while(x<=n-1){
		if(kai){
			//找en
			now.en=n-1;//到最后也没找到
			full=true; 
			for(int j=x;j<n-1;j++){
				x=j+1;
				if(t[j+1]=='0'){
					now.en=j;
					kai=false;
					break;
				}
				if(j==n-2&&t[j+1]=='1'){
					x=n;
				} 
			}
		}else{
			//找be
			for(int j=x;j<n;j++){
				x=j;
				if(j==n-1){
					if(t[j]=='1'){
						now.be=j;now.en=j;
						full=true;
					}
					x=n;
				}
				if(t[j]=='1'){
					now.be=j;
					kai=true;
					break;
				}
			} 
		}
		if(full){
			for(int i=now.be;i<=now.en;i++){
				if(s[i]=='1')
					now.num_1++;
				if(s[i]=='0')
					now.num_0++;
			}
			if(fors){
				son_1.push_back(now);
				
			}else{
				son_2.push_back(now);
			}
			now.num_0=0;now.num_1=0;
			full=false;
		}
	}
}
void clean(){
	sum=0;
	son_1.clear();
	son_1.clear();
	for(int i=0;i<n;i++){
		s_1[i]=0;
		s_2[i]=0;
	}
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	bool h4=1;
	for(int o=0;o<T;o++){
		cin>>n;
		cin>>sf>>ss>>tf>>ts;
		
		for(int i=0;i<n;i++){
			if(sf[0]!=sf[i]){
				h4=0;
				break;
			}
		}
		if(h4){
			for(int i=0;i<n;i++){
				if(sf[0]==ss[i]){
					sum++;
				}
			}
			cout<<sum<<endl;
			sum=0;h4=1;
			clean();
			continue;
		}

			part_1(1);
			part_1(0);
			
			if(tf==ts){
				for(int i=0;i<son_1.size();i++){
					sum+=min(son_1[i].num_1,son_2[i].num_1)+min(son_1[i].num_0,son_2[i].num_0);
				}
				for(int i=0;i<n;i++){
					if(tf[i]=='0'){
						if(sf[i]==ss[i]){
							sum++;
						}
					}
				}
				cout<<sum<<endl;
				sum=0;
				clean();
				continue;
			}
			
			
			for(int i=0;i<son_1.size();i++){
				for(int j=son_1[i].be;j<=son_1[i].en;j++){
					s_1[j]=i;
				}
			}
			for(int i=0;i<son_2.size();i++){
				for(int j=son_2[i].be;j<=son_2[i].en;j++){
					s_2[j]=i;
				}
			}
		

			sy1=sf;
			sy2=ss;
			for(int i=0;i<=n;i++){
				if(tf[i]=='0'&&ts[i]=='1'&&sf[i]!=ss[i]){
					if(sy1[i]=='1'&&son_2[s_2[i]].num_1!=0){
						sy2[i]='1';
						son_2[s_2[i]].num_1--;
					}
					if(sy1[i]=='0'&&son_2[s_2[i]].num_0!=0){
						sy2[i]='0';
						son_2[s_2[i]].num_0--;
					}
				}
				if(tf[i]=='1'&&ts[i]=='0'&&sf[i]!=ss[i]){
					if(sy2[i]=='1'&&son_1[s_1[i]].num_1!=0){
						sy1[i]='1';
						son_1[s_1[i]].num_1--;
					}
					if(sy2[i]=='0'&&son_1[s_1[i]].num_0!=0){
						sy1[i]='0';
						son_1[s_1[i]].num_0--;
					}
				}
			}
			for(int i=0;i<son_1.size();i++){
				sum+=min(son_1[i].num_1,son_2[i].num_1)+min(son_1[i].num_0,son_2[i].num_0);
			}
			for(int i=0;i<n;i++){
				if(tf[i]=='0'||ts[i]=='0'){
					if(sy1[i]==sy2[i]){
						sum++;
					}
				}
			}
			cout<<sum<<endl;
			sum=0;
			clean();
	}
	return 0;
}
