#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		bool flag = true;
		for(int j = 0; j < 10; j++) {
			int x;
			scanf("%d", &x);
			if(x != j % 5 + 1) flag = false;
		}
		if(flag) printf("%d\n", i);
	}
}