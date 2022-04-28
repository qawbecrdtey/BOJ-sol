#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a, b, g; cin >> a >> b >> g;
	auto sa = new string[a];
	auto sb = new string[b];
	for(int i = 0; i < a; i++) cin >> sa[i];
	for(int i = 0; i < b; i++) cin >> sb[i];
	sort(sa, sa + a); sort(sb, sb + b);
	int resa = 0, resb = 0;
	while(g--) {
		string s; cin >> s;
		resa += binary_search(sa, sa + a, s);
		resb += binary_search(sb, sb + b, s);
	}
	if(resa > resb) cout << 'A';
	else if(resa < resb) cout << 'B';
	else cout << "TIE";
}