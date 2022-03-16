#include <iostream>
#include <string>
using namespace std;
inline string star(int n) { return string(n, '*'); }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; int tt = 1; while(true) {
		cin >> n; if(!n) return 0;
		cout << "Case #" << tt++ << ":\n";
		int a[12]{};
		for(int i = 0; i < n; i++) {
			int x, y, z; cin >> x >> y >> z;
			a[y - 1]++;
		}
		cout << "Jan:" << star(a[0]) << '\n'
			 << "Feb:" << star(a[1]) << '\n'
			 << "Mar:" << star(a[2]) << '\n'
			 << "Apr:" << star(a[3]) << '\n'
			 << "May:" << star(a[4]) << '\n'
			 << "Jun:" << star(a[5]) << '\n'
			 << "Jul:" << star(a[6]) << '\n'
			 << "Aug:" << star(a[7]) << '\n'
			 << "Sep:" << star(a[8]) << '\n'
			 << "Oct:" << star(a[9]) << '\n'
			 << "Nov:" << star(a[10]) << '\n'
			 << "Dec:" << star(a[11]) << '\n';
	}
}