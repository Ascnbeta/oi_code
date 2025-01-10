#include<bits/stdc++.h>
#define int long long
#define th1 first
#define th2 second
#define vadd emplace_back
#define mp make_pair
#define qr(x) x=read()
#define Type int
using namespace std;

inline Type read(){
    char c=getchar(); Type x=0, f=1;
    while(!isdigit(c)) (c=='-'?f=-1:f=1), c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48), c=getchar();
    return x*f;
}

const int N = 1e5 + 5;

int T, n, nxt[2][N];
char s[2][N], t[2][N];
set<int>se[2][2];

signed main(){ //edit
   freopen("edit.in", "r", stdin); freopen("edit.out", "w", stdout);

    qr(T);
    while(T--)
    {
        qr(n); 
        for(int i=1; i<=n; i++) cin>>s[0][i];
        for(int i=1; i<=n; i++) cin>>s[1][i];
        for(int i=1; i<=n; i++) cin>>t[0][i];
        for(int i=1; i<=n; i++) cin>>t[1][i];
	
		for(int i=0; i<2; i++)
        	for(int j=0; j<2; j++) se[i][j].clear();
        for(int i=1; i<=n; i++){
        	se[0][s[0][i]-'0'].insert(i);
        	se[1][s[1][i]-'0'].insert(i);
        }
        for(int i=n; i>=1; i--){
            if(i == n){ nxt[0][i] = nxt[1][i] = n + 1; continue; }
            if(t[0][i] != t[0][i+1]) nxt[0][i] = i + 1;
            else nxt[0][i] = nxt[0][i+1];
            if(t[1][i] != t[1][i+1]) nxt[1][i] = i + 1;
            else nxt[1][i] = nxt[1][i+1];
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
        	if(s[0][i] == s[1][i]){ ans++; continue; }
        	
        	if(s[0][i] == '0'){
        		auto it2 = se[0][1].lower_bound(i),
					 it3 = se[1][0].lower_bound(i);
        		bool f = false;
        		if(t[0][i] == '0' or it2 == se[0][1].end() or *it2 >= nxt[0][i]) f = true;
				if(f){
					if(t[1][i] == '0' or it3 == se[1][0].end() or *it3 >= nxt[1][i]) continue;
					int pos = *it3;	ans++;
					swap(s[1][i], s[1][pos]);
					se[1][0].erase(pos); se[1][1].insert(pos);
					continue;
				}
				else{
					int pos = *it2; ans++;
					swap(s[0][i], s[0][pos]);
					se[0][1].erase(pos); se[0][0].insert(pos);
				}
			}
			
			else{
					auto it2 = se[0][0].lower_bound(i),
						 it3 = se[1][1].lower_bound(i);
	        		bool f = false;
	        		if(t[0][i] == '0' or it2 == se[0][0].end() or *it2 >= nxt[0][i]) f = true;
					if(f){
						if(t[1][i] == '0' or it3 == se[1][1].end() or *it3 >= nxt[1][i]) continue;
						int pos = *it3;
						ans++; swap(s[1][i], s[1][pos]);
						se[1][1].erase(pos); se[1][0].insert(pos);
						continue;
					}
					else{
						int pos = *it2; ans++;
						swap(s[0][i], s[0][pos]);
						se[0][0].erase(pos); se[0][1].insert(pos);
					}
			}
		}
		cout<<ans<<"\n";
    }


    return 0;
}
