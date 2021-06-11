#include <stdio.h>
int main() {
	int r, c, h, w;
	scanf("%d%d%d%d", &r, &c, &h, &w);
	auto a = new int*[r];
	for(int i = 0; i < r; i++) {
		a[i] = new int[c];
		for(int j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int left = 1, right = r * c + 1;
	while(left < right) {
		auto const m = (left + right) / 2;
		auto b = new int*[r];
		for(int i = 0; i < r; i++) {
			b[i] = new int[c];
			for(int j = 0; j < c; j++) {
				if(a[i][j] < m) b[i][j] = -1;
				else if(a[i][j] > m) b[i][j] = 1;
				else b[i][j] = 0;
				if(i) b[i][j] += b[i - 1][j];
				if(j) b[i][j] += b[i][j - 1];
				if(i && j) b[i][j] -= b[i - 1][j - 1];
			}
		}
		int neg = 0, zero = 0, pos = 0;
		for(int i = 0; i <= r - h; i++) {
			for(int j = 0; j <= c - w; j++) {
				auto sum = b[i + h - 1][j + w - 1];
				if(i) sum -= b[i - 1][j + w - 1];
				if(j) sum -= b[i + h - 1][j - 1];
				if(i && j) sum += b[i - 1][j - 1];
				if(sum < 0) neg++;
				else if(sum > 0) pos++;
				else zero++;
			}
		}
		if(zero && !neg) {
			printf("%d", m);
			return 0;
		}
		if(neg) right = m;
		else left = m + 1;

		for(int i = 0; i < r; i++) {
			delete[] b[i];
		}
		delete[] b;
	}
	printf("%d", left);
	for(int i = 0; i < r; i++) {
		delete[] a[i];
	}
	delete[] a;
}