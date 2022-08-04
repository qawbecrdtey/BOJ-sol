#include <algorithm>
#include <iostream>
using namespace std;
static constexpr int M = 1234567;
int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(nullptr); cout.tie(nullptr);
	 int t; cin >> t;
	 auto a = new int[t];
	 for(int i = 0; i < t; i++) cin >> a[i];
	 int n = *max_element(a, a + t);
	 int *arr[10];
	 for(auto &i : arr) {
		 i = new int[n + 1]();
		 i[1] = 1;
	 }
	 for(int i = 2; i <= n; i++) {
		 arr[0][i] = (arr[7][i - 1]) % M;
		 arr[1][i] = (arr[2][i - 1] + arr[4][i - 1]) % M;
		 arr[2][i] = (arr[1][i - 1] + arr[3][i - 1] + arr[5][i - 1]) % M;
		 arr[3][i] = (arr[2][i - 1] + arr[6][i - 1]) % M;
		 arr[4][i] = (arr[1][i - 1] + arr[5][i - 1] + arr[7][i - 1]) % M;
		 arr[5][i] = (arr[2][i - 1] + arr[4][i - 1] + arr[6][i - 1] + arr[8][i - 1]) % M;
		 arr[6][i] = (arr[3][i - 1] + arr[5][i - 1] + arr[9][i - 1]) % M;
		 arr[7][i] = (arr[4][i - 1] + arr[8][i - 1] + arr[0][i - 1]) % M;
		 arr[8][i] = (arr[5][i - 1] + arr[7][i - 1] + arr[9][i - 1]) % M;
		 arr[9][i] = (arr[6][i - 1] + arr[8][i - 1]) % M;
	 }
	 for(int i = 0; i < t; i++) {
		 int res = 0;
		 for(auto const j : arr) {
			 res = (res + j[a[i]]) % M;
		 } cout << res << '\n';
	 }
}