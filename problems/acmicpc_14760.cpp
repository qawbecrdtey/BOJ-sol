#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        auto a = new char*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new char[n + 1];
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            vector<int> v; v.push_back(0);
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 'X') v.back()++;
                else if(v.back() != 0) v.push_back(0);
            }
            while(!v.empty() && v.back() == 0) v.pop_back();
            if(v.empty()) cout << "0\n";
            else { for(int i : v) cout << i << ' '; cout << '\n'; }
        }
        for(int j = 0; j < n; j++) {
            vector<int> v; v.push_back(0);
            for(int i = 0; i < n; i++) {
                if(a[i][j] == 'X') v.back()++;
                else if(v.back() != 0) v.push_back(0);
            }
            while(!v.empty() && v.back() == 0) v.pop_back();
            if(v.empty()) cout << "0\n";
            else { for(int i : v) cout << i << ' '; cout << '\n'; }
        }
        for(int i = 0; i < n; i++) delete[] a[i];
        delete[] a;
    }
}
