#include <algorithm>
#include <cstdio>
#include <vector>
int main() {
	int a[3];
	std::vector<int> v;
	scanf("%d%d%d", a, a + 1, a + 2);
	for(int i = 1; i < 8; i++) {
		int res = 1;
		for(int j = 0; j < 3; j++) {
			if(i & (1 << j)) res *= a[j];
		} v.push_back(res);
	} std::sort(v.begin(), v.end());
	auto it = v.rbegin();
	while(it != v.rend()) {
		if(*it & 1) {
			printf("%d", *it);
			return 0;
		} ++it;
	} printf("%d", v[6]);
}