#include <stdio.h>
struct uf {
	int *root, n;
	uf(int n) : n(n), root(new int[n + 1]) {
		for(int i = 1; i <= n; i++) {
			root[i] = i;
		}
	}
	int find(int a) {
		if(root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		root[x] = y;
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int main() {
	int n;
	scanf("%d", &n);
	uf u(n);
	for(int i = 2; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		u.merge(x, y);
	}
	for(int i = 2; i <= n; i++) {
		if(!u.check(1, i)) {
			printf("1 %d", i);
			return 0;
		}
	}
}