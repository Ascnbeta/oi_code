#include <bits/stdc++.h>
using namespace std;
char ch[1000004];
bool c[1000004];
int ans,maxx;
stack<int> s;
int main () {
    scanf("%s",ch);
 //   for (int i = 0; i < strlen(ch); i++) {
 //       cout << ch[i];
//}
 //   cout << '\n';
    int len = strlen(ch);
    for (int i = 0; i < len; i++) {
        if (ch[i] == '(') {
            s.push(i);
        }else{
            if (!s.empty()) {
                c[s.top()] = true;
                c[i] = true;
                s.pop();
            }
        }
    }
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        if (c[i]) {
            ++tmp;
            if (tmp > maxx) {
                maxx = tmp;
                ans = 1;
            }else if (tmp == maxx) {
                ++ans;
            }
        }else{
            tmp = 0;
        }
    }
    if (maxx == 0) {
        printf("%d %d",0,1);
    }else{
        printf("%d %d",maxx,ans);
    }
    return 0;
}