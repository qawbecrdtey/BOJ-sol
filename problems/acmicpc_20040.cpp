#include <stdio.h>
#include <memory>
using namespace std;
struct uf {
	uf(int n) : n(n), arr(make_unique<int[]>(n)), rank(make_unique<int[]>(n)) {
		for(int i = 0; i < n; i++) {
			arr[i] = i;
			rank[i] = 1;
		}
	}
	int find(int idx) {
		if(arr[idx] == idx) return idx;
		return arr[idx] = find(arr[idx]);
	}
	void join(int a, int b) {
		int const x = find(a);
		int const y = find(b);
		if(rank[x] < rank[y]) {
			rank[y] += rank[x];
			arr[x] = y;
		}
		else {
			rank[x] += rank[y];
			arr[y] = x;
		}
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
	int n;
	unique_ptr<int[]> arr;
	unique_ptr<int[]> rank;
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	uf u(n);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(u.check(a, b)) {
			printf("%d", i);
			return 0;
		}
		u.join(a, b);
	}
	printf("0");
}