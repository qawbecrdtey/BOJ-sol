#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a[4]; int b[4];
		for(int &i : a) scanf("%d", &i);
		for(int &i : b) scanf("%d", &i);
		if(a[0] == b[0]) {
			if(a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[2] && a[2] == b[3] && a[3] == b[1]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[3] && a[2] == b[1] && a[3] == b[2]) {
				printf("1\n"); continue;
			}
		}
		if(a[0] == b[1]) {
			if(a[1] == b[0] && a[2] == b[3] && a[3] == b[2]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[2] && a[2] == b[0] && a[3] == b[3]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[3] && a[2] == b[2] && a[3] == b[0]) {
				printf("1\n"); continue;
			}
		}
		if(a[0] == b[2]) {
			if(a[1] == b[0] && a[2] == b[1] && a[3] == b[3]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[1] && a[2] == b[3] && a[3] == b[0]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[3] && a[2] == b[0] && a[3] == b[1]) {
				printf("1\n"); continue;
			}
		}
		if(a[0] == b[3]) {
			if(a[1] == b[0] && a[2] == b[2] && a[3] == b[1]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[1] && a[2] == b[0] && a[3] == b[2]) {
				printf("1\n"); continue;
			}
			if(a[1] == b[2] && a[2] == b[1] && a[3] == b[0]) {
				printf("1\n"); continue;
			}
		}
		printf("0\n");
	}
}