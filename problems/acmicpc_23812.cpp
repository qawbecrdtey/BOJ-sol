#include <iostream>
#include <string>
using namespace std;
void print(string s, int n) {
    int start = 0;
    int piv = 0;
    while(start < s.size()) {
        while(piv < s.size() && s[piv] != '\n') piv++;
        for(int x = 0; x < n; x++) {
            for(int i = start; i < piv; i++) {
                for(int j = 0; j < n; j++) printf("%c", s[i]);
            } if(x != n - 1) printf("\n");
        } if(piv != s.size()) printf("\n");
        start = piv + 1;
        piv = start;
    }
}
int main() {
    int n; cin >> n;
    print("@   @\n@@@@@\n@   @\n@@@@@\n@   @", n);
}