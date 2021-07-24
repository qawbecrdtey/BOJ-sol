#include <iostream>
#include <string>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		n--;
		int max;
		string maxs;
		cin >> max >> maxs;
		while(n--) {
			int x; string s;
			cin >> x >> s;
			if(max < x) {
				max = x;
				maxs = s;
			}
		}
		cout << maxs << '\n';
	}
}