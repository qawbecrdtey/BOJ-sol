#include <cstdio>
int main() {
	int a[3], b[3];
	for(int &i : a) scanf("%d", &i);
	for(int &i : b) scanf("%d", &i);
	int s = 0;
	for(int i = 0; i < 3; i++) s += ((b[i] - a[i]) * (3 - i));
	if(s > 0) printf("B");
	else if(s < 0) printf("A");
	else printf("T");
}