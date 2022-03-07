#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, q; cin >> n >> q;
    ll r = 0, c = 0;
    ll rcnt = 0, ccnt = 0;
    vector<bool> rv(n + 1), cv(n + 1);
    while(q--) {
        char s[2]; ll x;
        cin >> s >> x;
        if(*s == 'R') {
            if(rv[x]) { cout << "0\n"; continue; }
            cout << x * (n - ccnt) + n * (n + 1) / 2 - c << '\n';
            rv[x] = true; r += x; rcnt++;
        }
        else {
            if(cv[x]) { cout << "0\n"; continue;}
            cout << x * (n - rcnt) + n * (n + 1) / 2 - r << '\n';
            cv[x] = true; c += x; ccnt++;
        }
    }
}