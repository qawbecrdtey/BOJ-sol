#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	auto a = new int*[s.size() + 1];
	int max = 0;
	for(int i = 0; i <= s.size(); i++) {
		a[i] = new int[t.size() + 1]();
		if(!i) continue;
		for(int j = 1; j <= t.size(); j++) {
			if(s[i - 1] == t[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
			if(max < a[i][j]) max = a[i][j];
		}
	}
	printf("%d", max);
	for(int i = 0; i <= s.size(); i++) delete[] a[i];
	delete[] a;
}