#include <iostream>
#include <vector>
using namespace std;
class polynomial {
	vector<int> coef;
	void clean() noexcept { while(!coef.empty() && !coef.back()) coef.pop_back(); }
public:
	polynomial operator*(polynomial const &poly) const {
		polynomial result; result.coef.resize(coef.size() + poly.coef.size());
		for(int i = 0; i < coef.size(); i++) {
			for(int j = 0; j < poly.coef.size(); j++) {
				result.coef[i + j] ^= (coef[i] & poly.coef[j]);
			}
		} result.clean();
		return result;
	}
	polynomial operator%(polynomial const &poly) {
		while(poly.coef.size() <= coef.size()) {
			auto mul = coef.size() - poly.coef.size();
			if(!coef[mul + poly.coef.size() - 1]) continue;
			for(int i = 0; i < poly.coef.size(); i++) {
				coef[i + mul] ^= poly.coef[i];
			} clean();
		}
		return *this;
	}
	friend istream &operator>>(istream &is, polynomial &poly) {
		int n; is >> n;
		poly.coef.resize(n);
		while(n--) is >> poly.coef[n];
		return is;
	}
	friend ostream &operator<<(ostream &os, polynomial const &poly) {
		os << poly.coef.size();
		for(auto it = poly.coef.rbegin(); it != poly.coef.rend(); ++it) {
			cout << ' ' << *it;
		} return os;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		polynomial f, g, h; cin >> f >> g >> h;
		cout << f * g % h << '\n';
	}
}