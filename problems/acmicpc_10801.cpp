#include <stdio.h>
int main() {
	int a[10];
	int b[10];
	for(int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}
	for(int i = 0; i < 10; i++) {
		scanf("%d", b + i);
	}
	int aa = 0, bb = 0;
	for(int i = 0; i < 10; i++) {
		if(a[i] < b[i]) bb++;
		else if(a[i] > b[i]) aa++;
	}
	if(aa < bb) printf("B");
	else if(aa > bb) printf("A");
	else printf("D");
}