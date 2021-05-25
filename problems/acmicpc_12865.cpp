#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	auto a = new pair<int, int>[n];
	auto b = new int*[n + 1];
	b[0] = new int[k + 1]();
	for(int i = 1; i <= n; i++) {
		b[i] = new int[k + 1]();
		scanf("%d%d", &a[i].first, &a[i].second);
		for(int j = 0; j <= k; j++) {
			b[i][j] = b[i - 1][j];
			if(j >= a[i].first && b[i - 1][j - a[i].first] + a[i].second > b[i][j]) b[i][j] = b[i - 1][j - a[i].first] + a[i].second;
		}
	}
	printf("%d", b[n][k]);
}