#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string a, b; cin >> a >> b;
		int arr[26]{};
		if(a.size() != b.size()) {
			cout << "Imp";
			goto END;
		}
		for(char c : a) arr[c - 'a']++;
		for(char c : b) {
			if(--arr[c - 'a'] < 0) {
				cout << "Imp";
				goto END;
			}
		}
		cout << "P";
	END:cout << "ossible\n";
	}
}