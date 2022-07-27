#include <cstdio>
int main() {
	int a[5]; for(int &i : a) scanf("%d", &i);
	int nikky = 0, byron = 0;
	for(int i = 0; i < a[4]; i++) {
		if(i % (a[0] + a[1]) >= a[0]) nikky--;
		else nikky++;
		if(i % (a[2] + a[3]) >= a[2]) byron--;
		else byron++;
	} printf(nikky > byron ? "Nikky" : (nikky == byron ? "Tied" : "Byron"));
}