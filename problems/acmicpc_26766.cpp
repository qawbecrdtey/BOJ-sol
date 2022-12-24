#include <iostream>
static constexpr char const *heart = " @@@   @@@ \n"
                                     "@   @ @   @\n"
                                     "@    @    @\n"
                                     "@         @\n"
                                     " @       @ \n"
                                     "  @     @  \n"
                                     "   @   @   \n"
                                     "    @ @    \n"
                                     "     @     ";
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n; std::cin >> n;
    while(n--) {
        std::cout << heart;
        if(n) std::cout << '\n';
    }
}