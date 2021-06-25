#include <stdio.h>
#include <algorithm>
using namespace std;
struct uf {
	int *root, *rank;
	uf(int n) : root(new int[n]), rank(new int[n]) {
		for(int i = 0; i < n; i++) root[i] = i, rank[i] = 1;
	}
	int find(int a) {
		if(root[a] == a) return a;
		return root[a] = find(root[a]);
	}
	void merge(int a, int b) {
		auto x = find(a), y = find(b);
		if(x == y) return;
		if(rank[x] > rank[y]) swap(x, y);
		root[x] = y;
		if(rank[x] == rank[y]) rank[x]++;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		int n, k;
		scanf("%d%d", &n, &k);
		uf u(n);
		for(int i = 0; i < k; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			u.merge(a, b);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(!u.check(i, j)) {
					printf("Not connected.\n");
					goto END;
				}
			}
		}
		printf("Connected.\n");
		END: continue;
	}
}