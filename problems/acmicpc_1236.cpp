#include <stdio.h>
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char*[n];
	int cntr = 0, cntc = 0;
	for(int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		scanf("%s", a[i]);
		bool flag = false;
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'X') {
				flag = true;
				break;
			}
		}
		cntr += !flag;
	}
	for(int j = 0; j < m; j++) {
		bool flag = false;
		for(int i = 0; i < n; i++) {
			if(a[i][j] == 'X') {
				flag = true;
				break;
			}
		}
		cntc += !flag;
	}
	printf("%d", cntr > cntc ? cntr : cntc);
}