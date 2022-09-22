#include <iostream>
#include <string>
using namespace std;
static constexpr int value[]{3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; int x{}; for(char c : s) x += value[c - 'A']; if(x & 1) cout << "I'm a winner!"; else cout << "You're the winner?";
}