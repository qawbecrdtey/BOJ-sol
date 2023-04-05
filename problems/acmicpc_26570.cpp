#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        vector<int> v{1};
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                v.push_back(i);
                if(i * i != n) v.push_back(n / i);
            }
        }
        bool flag = false;
        for(int i = 0; i < (1 << v.size()); i++) {
            int sum = 0;
            for(int j = 0; j < v.size(); j++) {
                if((i >> j) & 1) sum += v[j];
            } if(sum == n) {
                flag = true;
                break;
            }
        } if(!flag) cout << "NOT ";
        cout << "Semiperfect\n";
    }
}