#include <stdio.h>
#include <utility>
int main() {
	int n;
	scanf("%d", &n);
	auto a = new std::pair<int, int>[n];
	auto b = new int[n]();
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		for(int j = 0; j < i; j++) {
			if(a[j].first < a[i].first && a[j].second < a[i].second) {
				b[j]++;
			}
			if(a[j].first > a[i].first && a[j].second > a[i].second) {
				b[i]++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", b[i] + 1);
	}
}