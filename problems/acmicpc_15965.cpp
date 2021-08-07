#include <stdio.h>
#include <vector>
using namespace std;
vector<int> prime() {
	vector<int> v;
	auto visited = new bool[10000001]();
	int i;
	for(i = 2; i * i <= 10000000; i++) {
		if(!visited[i]) {
			v.push_back(i);
			for(int j = i; j <= 10000000; j += i) {
				visited[j] = true;
			}
		}
	}
	for(; i <= 10000000; i++) {
		if(!visited[i]) v.push_back(i);
	}
	delete[] visited;
	return v;
}
int main() {
	auto primes = prime();
	int n;
	scanf("%d", &n);
	printf("%d", primes[n - 1]);
}