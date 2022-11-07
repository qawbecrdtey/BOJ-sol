#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		bool mack{}, zack{};
		int a[10]; for(int &i : a) {
			cin >> i; cout << i << ' ';
			if(i == 18) mack = true;
			if(i == 17) zack = true;
		} cout << '\n';
		if(mack && zack) cout << "both\n\n";
		else if(mack) cout << "mack\n\n";
		else if(zack) cout << "zack\n\n";
		else cout << "none\n\n";
	}
}