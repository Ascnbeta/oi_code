#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int T;
int main() {
    while (++T) {
        cout << T << '\n';
        system("genT1.exe");
        system("T1.exe");
        system("T1bl.exe");
        if (system("fc /n a.out b.out")) {
            system("pause");
        }
    }
    return 0;
}