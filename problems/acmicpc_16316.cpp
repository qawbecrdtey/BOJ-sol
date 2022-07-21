#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; string s;
	for(int i = 1; i <= n; i++) {
		cin >> s; if(s == "mumble") continue;
		if(stoi(s) != i) {
			cout << "something is fishy";
			return 0;
		}
	} cout << "makes sense";
}