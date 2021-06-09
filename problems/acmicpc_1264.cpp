#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char a[256];
	while(cin.getline(a, 256)) {
		int cnt = 0;
		auto l = strlen(a);
		if(l == 1 && a[0] == '#') break;
		for(int i = 0; i < l; i++) {
			if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] =='u') {
				cnt++;
			}
			if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] =='U') {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}