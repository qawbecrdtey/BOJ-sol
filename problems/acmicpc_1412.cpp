#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new char*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new char[n + 1];
        cin >> a[i];
    }
    auto deg = new int[n]();
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i][j] == 'Y' && a[j][i] == 'Y') { a[i][j] = a[j][i] = 'N'; continue; }
            if(a[i][j] == 'Y') deg[j]++;
            if(a[j][i] == 'Y') deg[i]++;
        }
    }
    vector<int> s;
    for(int i = 0; i < n; i++) {
        if(!deg[i]) s.push_back(i);
    }
    while(!s.empty()) {
        int const now = s.back(); s.pop_back();
        for(int i = 0; i < n; i++) {
            if(a[now][i] == 'Y') {
                if(!--deg[i]) {
                    s.push_back(i);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(deg[i]) { cout << "NO"; return 0; }
    }
    cout << "YES";
}
