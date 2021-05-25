#include <stdio.h>
int main() {
	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	auto a = new int*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new int[m];
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int mintime = 1000000000;
	int mini;
	for(int k = 0; k <= 256; k++) {
		int time = 0;
		int curb = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] > k) {
					curb += a[i][j] - k;
					time += 2 * (a[i][j] - k);
				}
				if(a[i][j] < k) {
					curb -= k - a[i][j];
					time += k - a[i][j];
				}
			}
		}
		if(curb + b < 0) continue;
		if(mintime >= time) {
			mintime = time;
			mini = k;
		}
	}
	printf("%d %d", mintime, mini);
}