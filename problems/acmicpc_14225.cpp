#include <algorithm>
#include <stdio.h>
#include <set>
void sums(int const *a, std::set<int> &s, bool *visited, int const n, int idx) {
	if(idx == n) {
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += visited[i] * a[i];
		}
		s.insert(sum);
		return;
	}
	visited[idx] = false;
	sums(a, s, visited, n, idx + 1);
	visited[idx] = true;
	sums(a, s, visited, n, idx + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	std::set<int> s;
	auto visited = new bool[n];
	sums(a, s, visited, n, 0);
	int cur = 0;
	for(int val : s) {
		if(val != cur) {
			printf("%d", cur);
			return 0;
		}
		cur++;
	}
	printf("%d", cur);
	delete[] a;
}