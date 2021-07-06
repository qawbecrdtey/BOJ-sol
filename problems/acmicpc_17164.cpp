#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	auto c = new char[n + 1];
	scanf("%s", c);
	int cnt = 1;
	int max = 1;
	for(int i = 1; i < n; i++) {
		if(c[i] == c[i - 1] || c[i] == 'V' || c[i - 1] == 'V') cnt = 1;
		else cnt++;
		if(max < cnt) max = cnt;
	}
	printf("%d", max);
	delete[] c;
}