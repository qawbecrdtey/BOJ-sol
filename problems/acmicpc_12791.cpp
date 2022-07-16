#include <iostream>
#include <vector>
using namespace std;
struct info {
	int year;
	char const *name;
};
static constexpr info const albums[]{
		{1967, "DavidBowie"},
		{1969, "SpaceOddity"},
		{1970, "TheManWhoSoldTheWorld"},
		{1971, "HunkyDory"},
		{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
		{1973, "AladdinSane"},
		{1973, "PinUps"},
		{1974, "DiamondDogs"},
		{1975, "YoungAmericans"},
		{1976, "StationToStation"},
		{1977, "Low"},
		{1977, "Heroes"},
		{1979, "Lodger"},
		{1980, "ScaryMonstersAndSuperCreeps"},
		{1983, "LetsDance"},
		{1984, "Tonight"},
		{1987, "NeverLetMeDown"},
		{1993, "BlackTieWhiteNoise"},
		{1995, "1.Outside"},
		{1997, "Earthling"},
		{1999, "Hours"},
		{2002, "Heathen"},
		{2003, "Reality"},
		{2013, "TheNextDay"},
		{2016, "BlackStar"}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int a, b; cin >> a >> b;
		vector<info> v;
		for(auto const &now : albums) {
			if(now.year >= a && now.year <= b) {
				v.push_back(now);
			}
		}
		cout << v.size() << '\n';
		for(auto const &now : v) {
			cout << now.year << ' ' << now.name << '\n';
		}
	}
}