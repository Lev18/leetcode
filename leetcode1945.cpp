#include <string>
#include <iostream>
    int ans = 0;
    int getLucky(std::string s, int k) {
        
        if (k < 0) return 0;
        ans = 0;
        std::string to_integer{};
        for (const auto& it : s) {
            if (isalpha(it)) {
                to_integer += std::to_string(it - 96) ;
            }
            else if (isdigit(it)) { 
                ans += it - 48; 
            }
        }
        to_integer += std::to_string(ans) ;
        getLucky(to_integer, k - 1);

        return ans;
    }

int main() {
 std::cout<<getLucky("iiii", 2) << std::endl;
}