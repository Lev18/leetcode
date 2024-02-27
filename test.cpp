#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

void back_track(std::vector<char>& perm, std::vector<char>& nums, 
                    std::vector<std::vector<char>>& ans, std::vector<char>& index) {
        if (nums.size() == perm.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
          if (i > 0 && nums[i] == nums[i - 1] && index[i - 1] == 1) continue;
          if (index[i] == 0) {
                perm.push_back(nums[i]);
                index [i] = 1;
                back_track(perm, nums, ans, index);
                perm.pop_back();
                index[i] = 0;
          }
        }
    }
    std::vector<std::vector<char>> permuteUnique(std::vector<char>& nums) {
      std::vector<std::vector<char>> ans;
      std::vector<char> perm;
      std::sort(nums.begin(), nums.end());
          
      std::vector<char> index (nums.size(),0);
        
      back_track(perm, nums, ans, index);
      
      return ans;
    }

    int main() {

      std::vector<char> v {'s','y','s','w','a','A','l',' '};
      std::vector<std::vector<char>> ans = permuteUnique(v);
       std::ofstream file("/home/levon/Workspace/leetcode/read.txt", std::fstream::trunc | std::fstream::out);
    if (!file.is_open()) {
        std::cout << "unable to open file" << std::endl;
    }
    
      for (const auto& it : ans) {
        for (const auto& it_2 : it) {
          file << it_2;
        }
        file << '\n';
      }
    }