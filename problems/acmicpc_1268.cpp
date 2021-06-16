#include <stdio.h>
#include <array>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new array<int, 5>[n];
	int b[5][9] = {};
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	}
	int res = -1;
	int max = -1;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		auto checked = new bool[n]();
		checked[i] = true;
		for(int j = 0; j < 5; j++) {
			for(int k = 0; k < n; k++) {
				if(checked[k]) continue;
				if(a[i][j] == a[k][j]) {
					checked[k] = true;
					sum++;
				}
			}
		}
		if(max < sum) {
			res = i;
			max = sum;
		}
		delete[] checked;
	}
	printf("%d", res + 1);
	delete[] a;
}