#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int T = 0;
map<string,int> mp;
int n,m,k;
int main() {
    while (++T) {
        cout << T << '\n';
        // system("genT2.exe");
        system("T2.exe < D:/codes/exe/a.in > D:/codes/exe/a.out");
        freopen("D:/codes/exe/a.in","r",stdin);
        cin >> n >> m >> k;
        cout << n << m << k;
        mp.clear();
        fclose(stdin);
        freopen("D:/codes/exe/a.out","r",stdin);
        for (int i = 1; i <= k; i++) {
            string s;
            cout << s << '\n';
            getline(cin,s);
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == ' ') continue;
                string t = s;
                t[j] = '0';
                if (mp.find(t) != mp.end()) {
                    printf("Wrong Answer,the line %d is the same as line %d.\n",i,mp[t]);
                    system("pause");
                }else{
                    mp[t] = i;
                }
            }
            
        }
        printf("The answer is correct.\n");
        fclose(stdin);
    }
    return 0;
}