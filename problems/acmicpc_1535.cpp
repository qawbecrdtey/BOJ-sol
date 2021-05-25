#include <stdio.h>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n + 1];
	auto b = new int*[n + 1];
	b[0] = new int[100]();
	for(int i = 1; i <= n; i++) {
		b[i] = new int[100]();
		scanf("%d", &a[i].first);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i].second);
		for(int j = 1; j < 100; j++) {
			b[i][j] = b[i - 1][j];
			if(a[i].first <= j && b[i - 1][j - a[i].first] + a[i].second > b[i][j]) b[i][j] = b[i - 1][j - a[i].first] + a[i].second;
		}
	}
	printf("%d", b[n][99]);
}