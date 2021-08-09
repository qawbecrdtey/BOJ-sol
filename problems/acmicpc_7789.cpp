#include <stdio.h>
#include <string>
using namespace std;
void f(string &s, int a) {
	if(!a) return;
	f(s, a / 10);
	s.push_back(a % 10 + '0');
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			printf("No");
			return 0;
		}
	}
	string s;
	s.push_back(b + '0');
	f(s, a);
	a = stoi(s);
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}