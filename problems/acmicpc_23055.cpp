#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	auto a = new char*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new char[n + 1];
		for(int j = 0; j < n; j++) {
			if(!i || !j || (i == n - 1) || (j == n - 1) || (i == j) || (i + j == n - 1)) a[i][j] = '*';
			else a[i][j] = ' ';
		} a[i][n] = '\0';
		printf("%s", a[i]);
		if(i != n - 1) printf("\n");
	}
}