#include <bits/stdc++.h>
using namespace std;//pianfen
const int MN=1e5+10;
int T,n,ans;
int jini[3],taimei[3];
int me1[MN],me2[MN],mem[MN];
int a[MN],b[MN];
string str1,str2,str3,str4;
//chengsi50fen,bunengzaigaole
bool panduan(int i,int j){
	if(me1[i]==me2[i] && me1[i]==0) return false;
	if(me1[j]==me2[j] && me1[j]==0) return false;
	if(me1[i]==0&&(me1[j]==0 || me2[j]==0)) return false;
	if(me2[i]==0&&(me1[j]==0 || me2[j]==0)) return false; 
	return true;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	//scanf("%d",&T);到底能不能用，虚拟机下老是警告 
	for(int mmm=0;mmm<T;++mmm){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(me1,0,sizeof(me1));
		memset(me2,0,sizeof(me2));
		memset(mem,0,sizeof(mem));
		memset(jini,0,sizeof(jini));
		memset(taimei,0,sizeof(taimei));
		ans=0; 
		//scanf("%d",&n);
		cin>>n;
		cin>>str1>>str2>>str3>>str4;
		for(int i=0;i<n;++i){
			a[i+1]=str1[i]-'0';
			b[i+1]=str2[i]-'0';
			me1[i+1]=str3[i]-'0';
			me2[i+1]=str4[i]-'0';
			jini[a[i+1]]++;
			taimei[b[i+1]]++;
		}
		
		//A
		if(jini[1]==n){
			ans=taimei[1];
			cout<<ans<<endl;
			continue;
		}
		if(jini[0]==n){
			ans=taimei[0];
			cout<<ans<<endl;
			continue;
		}
		
		//baoli
		for(int i=1;i<=n;++i){
			if(a[i]==b[i]){
				ans++;
			}
			else{
				if(a[i]==b[i]){
					++ans;
					continue;
				}
				mem[i]=a[i]*10+b[i];
				if(i==1){
					if(me1[i]!=0 || me2[i]!=0){
						continue;
					}
				}
				else{
					for(int j=i-1;j>0;--j){
						if(mem[j]!=0 && mem[i]!=0 && mem[i]!=mem[j]){
							if(panduan(i,j)){
								mem[i]=0,mem[j]=0;
								ans+=2;
							}
						}
					}
				}
			}
		}
		//printf("%d",ans);
		cout<<ans<<endl;
	}
	return 0;
}
