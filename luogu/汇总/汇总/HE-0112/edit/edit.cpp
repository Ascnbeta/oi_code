#include<bits/stdc++.h>
using namespace std;
#define ll int
ll T;
ll sl[100005],sz[100005],tl[100005],tz[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--){
		ll ans=0,cnt1=0,cnt2=0,n=0;
		cin>>n;
		memset(tl,0,sizeof(tl));
		memset(tz,0,sizeof(tz));
		for(int i=1;i<=n;i++){
			char x;
			cin>>x;
			sl[i]=(int)x-'0';
		}
		for(int i=1;i<=n;i++){
			char x;
			cin>>x;
			sz[i]=(int)x-'0';
		}
		for(int i=1;i<=n;i++){
			char x;
			cin>>x;
			if(x=='0')
				tl[++cnt1]=i;
		}
		for(int i=1;i<=n;i++){
			char x;
			cin>>x;
			if(x=='0')
				tz[++cnt2]=i;
		}
		int prlt=0,prlf=0,przf=0,przt=0;
		cnt1=cnt2=0;
		for(int i=1;i<=n;i++){
			if(tl[cnt1+1]==i&&tz[cnt2+1]==i){
				ans+=min(min(prlt,przt)+min(prlf,przf),i-max(tl[cnt1],tz[cnt2])-1);
				prlt=0,prlf=0,przf=0,przt=0;
				cnt1++;
				cnt2++;
				if(sl[tl[cnt1]]==sz[tz[cnt2]])
					ans++;
			}else if(tl[cnt1+1]==i&&tz[cnt2+1]!=i){
				cnt1++;
				if(sz[i])
					przt++;
				else
					przf++;
				if(min(prlt,przt)+min(prlf,przf)<=i-tz[cnt2]-1){
					ans+=min(prlt,przt)+min(prlf,przf);
					przt=max(0,przt-prlt);
					przf=max(0,przf-prlf);
					prlt=prlf=0;
				}else{
					ans+=i-tz[cnt2]-1;
					przt=max(0,przt-min((i-tz[cnt2]-1),prlt));
					przf=max(0,przf-min((i-tz[cnt2]-1),prlf));
					prlt=prlf=0;
				}
				if(przt&&sl[i])
					ans++,przt--;
				else if(przf&&!sl[i])
					ans++,przf--;
			}else if(tl[cnt1+1]!=i&&tz[cnt2+1]==i){
				cnt2++;
				if(sl[i])
					prlt++;
				else
					prlf++;
				if(min(prlt,przt)+min(prlf,przf)<=i-tl[cnt1]-1){
					ans+=min(prlt,przt)+min(prlf,przf);
					prlt=max(0,prlt-przt);
					prlf=max(0,prlf-przf);
					przt=przf=0;
				}else{
					ans+=i-tl[cnt1]-1;
					prlt=max(0,prlt-min((i-tl[cnt1]-1),przt));
					prlf=max(0,prlf-min((i-tl[cnt1]-1),przf));
					przt=przf=0;
				}
				if(prlt&&sz[i])
					ans++,prlt--;
				else if(prlf&&!sz[i])
					ans++,prlf--;
			}else{
				if(sl[i])
					prlt++;
				else
					prlf++;
				if(sz[i])
					przt++;
				else
					przf++;
			}
//			if(t==1||t==2)
//			cout<<prlt<<' '<<prlf<<" "<<przt<<" "<<przf<<" ";
//			cout<<ans<<"\n";
		}
		ans+=min(prlt,przt)+min(prlf,przf);
		cout<<ans<<"\n";
	}
	return 0;
}
