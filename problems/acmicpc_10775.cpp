#include <stdio.h>
struct uf {
	int *root;
	uf(int n) : root(new int[n + 1]) {
		for(int i = 1; i <= n; i++) {
			root[i] = i;
		}
	}
	~uf() { delete[] root; }
	int find(int x) {
		if(root[x] == x) return x;
		return root[x] = find(root[x]);
	}
	void merge(int a, int b) {
		auto x = find(a);
		auto y = find(b);
		if(x == y) return;
		root[y] = x;
	}
};
int main() {
	int g, p;
	scanf("%d%d", &g, &p);
	uf u(g);
	for(int i = 0; i < p; i++) {
		int x;
		scanf("%d", &x);
		int find = u.find(x);
		if(find == 0) {
			printf("%d", i);
			return 0;
		}
		u.merge(find - 1, x);
	}
	printf("%d", p);
}