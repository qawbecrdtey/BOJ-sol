#include <stdio.h>
#include <utility>
using std::pair;
int main() {
	pair<pair<int, int>, pair<int, int>> a[4];
	for(auto & i : a) {
		scanf("%d%d%d%d", &i.first.first, &i.first.second, &i.second.first, &i.second.second);
	}
	int cnt = 0;
	for(int i = 1; i < 100; i++) {
		for(int j = 1; j < 100; j++) {
			for(auto & k : a) {
				if(k.first.first <= i && k.first.second <= j && k.second.first > i && k.second.second > j) { cnt++; break; }
			}
		}
	}
	printf("%d", cnt);
}