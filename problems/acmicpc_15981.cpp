#include <cstdio>
#include <vector>
inline int len(int n) {
	int res = 0;
	while(n) n >>= 1, res++;
	return res;
}
inline void insert(std::vector<int> &v, int step, int start, int n, bool inserting) {
	if(start > n) return;
	if(!inserting) {
		insert(v, step, start + step, n, true);
		return;
	}
	for(int i = start; i < start + step && i <= n; i++) v.push_back(i);
	insert(v, step, start + step, n, false);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", len(n - 1));
	for(int i = 1; i < n; i <<= 1) {
		std::vector<int> v;
		insert(v, i, 1, n, true);
		printf("\n%zu", v.size());
		for(auto now : v) printf(" %d", now);
	}
}