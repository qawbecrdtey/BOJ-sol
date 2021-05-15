#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[4] = {};
	for(auto const c : s) {
		switch(c) {
			case 'L': a[0]++; break;
			case 'O': a[1]++; break;
			case 'V': a[2]++; break;
			case 'E': a[3]++; break;
			default: break;
		}
	}
	int n;
	cin >> n;
	int max = -1;
	string maxs;
	while(n--) {
		string t;
		cin >> t;
		int b[4] = {};
		for(auto const c : t) {
			switch (c) {
				case 'L': b[0]++; break;
				case 'O': b[1]++; break;
				case 'V': b[2]++; break;
				case 'E': b[3]++; break;
				default: break;
			}
		}
		int const c[4] = { a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] };
		int res = 1;
		for(int i = 0; i < 3; i++) {
			for(int j = i + 1; j < 4; j++) {
				res = (res * (c[i] + c[j])) % 100;
			}
		}
		if(max < res || (max == res && t < maxs)) {
			max = res;
			maxs = t;
		}
	}
	cout << maxs;
}