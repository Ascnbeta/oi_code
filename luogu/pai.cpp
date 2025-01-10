#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main() {
	int cnt = 0;
	while(true) {
		++cnt;
		std::cout << cnt << '\n';
		system("gen.exe > test1.in");
		system("P2471pai.exe < test1.in > correct.out");
		system("P2471.exe < test1.in > wrong.out");
		if (system("fc /n correct.out wrong.out")) {
			system("pause");
		}
	}
}