#include <iostream>
static constexpr char const *name[]{nullptr, "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
static constexpr char const *same[]{nullptr, "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
		int a[2]; cin >> a[0] >> a[1];
		if(a[0] < a[1]) swap(a[0], a[1]);
		cout << "Case " << tt << ": ";
		if(a[0] == 6 && a[1] == 5) {
			cout << "Sheesh Beesh\n";
			continue;
		}
		if(a[0] == a[1]) {
			cout << same[a[0]] << '\n';
			continue;
		}
		cout << name[a[0]] << ' ' << name[a[1]] << '\n';
	}
}