#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if(n <= 220) cout << "220 284";
    else if(n <= 284) cout << "284 220";
    else if(n <= 1184) cout << "1184 1210";
    else if(n <= 1210) cout << "1210 1184";
    else if(n <= 2620) cout << "2620 2924";
    else if(n <= 2924) cout << "2924 2620";
    else if(n <= 5020) cout << "5020 5564";
    else if(n <= 5564) cout << "5564 5020";
    else if(n <= 6232) cout << "6232 6368";
    else if(n <= 6368) cout << "6368 6232";
    else if(n <= 10744) cout << "10744 10856";
    else if(n <= 10856) cout << "10856 10744";
    else if(n <= 12285) cout << "12285 14595";
    else if(n <= 14595) cout << "14595 12285";
    else if(n <= 17296) cout << "17296 18416";
    else if(n <= 18416) cout << "18416 17296";
}
