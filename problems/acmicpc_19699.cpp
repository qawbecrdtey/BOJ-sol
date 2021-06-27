#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool is_prime(int x) {
	if(x < 2) return false;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}
bool f(int const *a, bool *visited, int n, int m, int idx, int cnt, vector<int> &v) {
	if(cnt == m) {
		int sum = 0;
		for(int i = 0; i < idx; i++) {
			if(visited[i]) sum += a[i];
		}
		if(!is_prime(sum)) return false;
		v.push_back(sum);
		return true;
	}
	if(idx == n && cnt != m) return false;
	visited[idx] = true;
	bool const b = f(a, visited, n, m, idx + 1, cnt + 1, v);
	visited[idx] = false;
	bool const c = f(a, visited, n, m, idx + 1, cnt, v);
	return b || c;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	auto visited = new bool[n]();
	vector<int> v;
	if(!f(a, visited, n, m, 0, 0, v)) {
		printf("-1");
	}
	else {
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++) {
			if(!i || v[i] != v[i - 1]) printf("%d ", v[i]);
		}
	}
	delete[] visited;
	delete[] a;
}