#include <stdio.h>
int main() {
	int k, d, a;
	scanf("%d/%d/%d", &k, &d, &a);
	if(!d || k + a < d) printf("hasu");
	else printf("gosu");
}