#include <stdio.h>
#include <vector>
using namespace std;
bool palindrome(int n) {
	vector<int> v;
	while(n) {
		v.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0; i < v.size() / 2; i++) {
		if(v[i] != v[v.size() - i - 1]) return false;
	}
	return true;
}
vector<int> prime() {
	vector<int> p;
	auto b = new bool[1003002]();
	for(int i = 2; i < 1003002; i++) {
		if(!b[i]) {
			if(palindrome(i)) p.push_back(i);
			for (int j = i; j < 1003002; j += i) {
				b[j] = true;
			}
		}
	}
	delete[] b;
	return p;
}
int main() {
	auto v = move(prime());
	int n;
	scanf("%d", &n);
	printf("%d", *lower_bound(v.begin(), v.end(), n));
}