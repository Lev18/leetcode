#include <math.h>
#include <limits.h>

class Solution {
public:

int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        } 

        if (divisor == 1) {
            return dividend;
        }  
        // if dividend and divisor are equal
        if (!(dividend^divisor)) {
          return 1;
        }        
        int divis_sign{0};
        if (divisor < 0) {
            ++divis_sign;
            divisor = abs(divisor);
        }
        
        unsigned int div_dend {0};
        int divid_sign{0};
        if (dividend < 0) {
            ++divid_sign;
        }
        div_dend = abs(dividend);

        if (divisor > div_dend) {
            return 0;
        }
        
        int ans {0};
        if (!(div_dend & (div_dend - 1)) && !(divisor & (divisor - 1)) ) {
            divisor -= 1;
            while (divisor > 0) {
                div_dend >>= 1;
                divisor >>= 1;
            }
            if ((divis_sign && !divid_sign) || (divid_sign && !divis_sign)) {
              return -div_dend;
            }
            return div_dend;
        }
        // if divisor is power of 2
        if (!(divisor & (divisor - 1))) {
          int pow_2 {0};
          while (divisor > 1) {
            divisor >>= 1;
            ++pow_2;
          }
          div_dend >>= pow_2;
          if ((divis_sign && !divid_sign) || (divid_sign && !divis_sign)) {
            return -div_dend;
          }
          return div_dend;
        }
        // if divisor is even number
        if (!(divisor & 1)) {
            int two_div{0};
            while (!(divisor & 1)) {
                divisor >>= 1;
                ++two_div;
            }
            div_dend >>= two_div;

            unsigned int rem_div = divisor;
            while (rem_div <= div_dend) {
               rem_div += divisor;
               ++ans;
            }
        }
        else {
            unsigned int rem_div = divisor;
            while (rem_div <= div_dend) {
               rem_div += divisor;
               ++ans;
            }
        }
    
        if ((divis_sign && !divid_sign) || (divid_sign && !divis_sign)) {
            ans = -ans;
        }
        return ans;
    }
    
};
