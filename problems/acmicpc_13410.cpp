#include <cstdio>
#include <algorithm>
#include <vector>
inline int rev(int n) {
	int x = 0;
	while(n) {
		x = x * 10 + n % 10;
		n /= 10;
	}
	return x;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	std::vector<int> v;
	for(int i = 1; i <= k; i++) {
		v.push_back(rev(i * n));
	}
	sort(v.begin(), v.end());
	printf("%d", v.back());
}