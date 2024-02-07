#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
private:
    void back_track(std::vector<int>& perm, std::vector<int>& nums, 
                    std::vector<std::vector<int>>& ans, std::vector<int>& index) {
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
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
      std::vector<std::vector<int>> ans;
      std::vector<int> perm;
      std::sort(nums.begin(), nums.end());
          
      std::vector<int> index (nums.size(),0);
        
      back_track(perm, nums, ans, index);
      
      return ans;
    }
};

int main() {
  Solution sol;
  std::vector<int> nums {1, 1, 2};
  sol.permuteUnique(nums);
  return 0;
}