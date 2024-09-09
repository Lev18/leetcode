#include <vector>
#include <array>
#include <iostream>

class Solution {
public:
    void dfs(int &n, int idx, std::vector<bool>&visited, std::vector<std::vector<int>>&stones)
    {
        visited[idx] = true;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                if(stones[idx][0] == stones[i][0])
                    dfs(n, i, visited, stones);

                if(stones[idx][1] == stones[i][1])
                    dfs(n, i, visited, stones);
            }
        }
    }
    int removeStones(std::vector<std::vector<int>>& stones) 
    {
        int n = stones.size();
        int group = 0;

        std::vector<bool>visited(n);
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(n, i, visited, stones);
                group += 1;
            }
        }
        return n - group;
    }
};

int main() {
  Solution s;
  
  std::vector<std::vector<int>> stones = {{3,2},{3,1},{4,4},{1,1},{0,2},{4,0}};
  
  std::cout << s.removeStones(stones) << std::endl;

  return 0;
}

// 00100
// 01000
// 00000
// 00000
// 00001