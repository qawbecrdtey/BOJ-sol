#include <iostream>
#include <vector>
using namespace std;
inline bool palindrome(int x) {
	for(int i = 2; i <= 64; i++) {
		int n = x;
		vector<int> v; while(n) { v.push_back(n % i); n /= i; }
		for(int j = 0; j < v.size() / 2; j++) {
			if(v[j] != v[v.size() - 1 - j]) goto CNT;
		} return true;
	CNT:continue;
	} return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int x; cin >> x;
		cout << palindrome(x) << '\n';
	}
}