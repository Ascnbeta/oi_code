#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main() {
	int cnt = 0;
	while(true) {
		++cnt;
		std::cout << cnt << '\n';
		system("gen1.exe > test.in");
		system("abc184_e.exe < test.in > correct.out");
		system("abc184_eno.exe < test.in > wrong.out");
		if (system("fc correct.out wrong.out")) {
			system("pause");
		}
	}
}