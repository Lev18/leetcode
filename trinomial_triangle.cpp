#include <vector>
#include <iostream>

    // Returns the trinomial coefficient T(n, k).
std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result(numRows + 1,
                                std::vector<int>(numRows + 1, 1));
        std::vector<int> prev;
        
        int cur_ind = 3;
        for (int i = 2; i <= numRows; ++i) {
          // std::vector<int>current(cur_ind,1);
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                 // result[i][j] = result[i - 1][j]  + 2 * result[i - 1][j + 1];
                 continue;
                }
                else if (i == j) {
                    result[i][j] = result[i - 1][j - 1]  + 2 * result[i - 1][j - 2];
                }
                else if (j == 1) {
                    result[i][j] = result[i - 1][j] + 1;
                }
                else result[i][j] = result[i - 1] [j - 1] +  result[i - 1][j] 
                                          + result[i - 1][j - 2];
                
                //T[i - 1][j - 1] + T[i - 1][j] + T[i - 1][j + 1];
            }
            
            // prev = current;
            // result.push_back(prev);
            // cur_ind += 2;
        }
        return result;
    } 

    // Takes two integer command-line arguments n and k and prints T(n, k).
  int main(void) {
   std::vector<std::vector<int>> result = generate(3);
   
   for (const auto& in : result) {
    for (const int& in2 : in) {
      std::cout << in2;
    }
    std::cout << std::endl;
   }

   std::cout << result[3][3-2] << std::endl;
  }