#include <bits/stdc++.h> 
using namespace std; 

// Function for swapping two numbers 
void swap(int& x, int& y) 
{ 
    int temp = x; 
    x = y; 
    y = temp; 
} 

// Function to find the possible 
// permutations 
void permutations(vector<vector<int> >& res, 
                vector<int> nums, int l, int h) 
{ 
    // Base case 
    // Add the vector to result and return 
    if (l == h) { 
        res.push_back(nums); 
        return; 
    } 

    // Permutations made 
    for (int i = l; i <= h; i++) { 

        // Swapping 
        swap(nums[l], nums[i]); 

        // Calling permutations for 
        // next greater value of l 
        permutations(res, nums, l + 1, h); 

        // Backtracking 
        swap(nums[l], nums[i]); 
    } 
} 

// Function to get the permutations 
vector<vector<int> > permute(vector<int>& nums) 
{ 
    // Declaring result variable 
    vector<vector<int> > res; 
    int x = nums.size() - 1; 

    // Calling permutations for the first 
    // time by passing l 
    // as 0 and h = nums.size()-1 
    permutations(res, nums, 0, x); 
    return res; 
} 

bool is_duplicate(vector<int> row) {
    std::sort(row.begin(), row.end());
    int dup = 0;
    for (int i = 0; i < row.size() - 1; ++i) {
        if (row[i] == row[i + 1]) {
            ++dup;
        }
    }
    return (bool)dup;
}

bool is_valid_view(int view, vector<int>& row) {
    
    int view_count = 0;
    int curent_buid = 0;

    if (is_duplicate(row)) 
        return false;
    
    for (const auto& it : row) {
        if (it > curent_buid) {
            ++view_count;
            curent_buid = it;
        }
    }
    
    return view_count == view;
}

vector<int> arrays (int index, vector<vector<int>>& grid) {
    vector<int> array_of_build {};
    
    if (index >= 0 && index < 4) {
        for (int i = 0; i < 4; ++i) {
            array_of_build.push_back(grid[i][index]);
        }
    }
    
    if (index >= 4 && index < 8) {
        for (int i = 0; i < 4; ++i) {
            array_of_build.push_back(grid[index - 4][3 - i]);
        }
    }
    
    if (index >= 8 && index < 12) {
        for (int i = 0; i < 4; ++i) {
            array_of_build.push_back(grid[3 - i][11 - index] );
        }
    }
    
    if (index >= 12 && index < 16) {
        for (int i = 0; i < 4; ++i) {
            array_of_build.push_back(grid[15 - index][i]);
        }
    }
    
    return array_of_build;
    
}

bool is_all_view_valid (vector<vector<int>>& cruel, vector<vector<int>>& grid) {
    array<vector<int>, 16> build_view {};
    array<bool,16> elements;
    
    for (int i = 0; i < 16; ++i) {
        build_view[i] = arrays(i, grid);
    } 
    
    int k = 0;
    for (int i = 0; i < cruel.size(); ++i) {
        for (int j = 0; j < cruel[i].size(); ++j) {
            if (is_valid_view(cruel[i][j], build_view[k]) == true) {
                elements[k] = true;
            }
            else {
               return false;
            }
            ++k;
        }

    }

    return true;  
}

vector<vector<int>> sky_final( vector<vector<int>>& res, vector<vector<int>>& cruel, int arr_size) {
     vector<vector<int>> grid;
    for(int index1 = 0; index1 < arr_size; ++index1) {
        for(int index2 = 0; index2 < arr_size; ++index2) {
          for(int index3 = 0; index3 < arr_size; ++index3) {
            for(int index4 = 0; index4 < arr_size; ++index4) {
                grid.push_back(res[index1]);
                grid.push_back(res[index2]);
                grid.push_back(res[index3]);
                grid.push_back(res[index4]);
            
                if (is_all_view_valid(cruel, grid)) {
                    return grid;
                }
                else {
                    grid.clear();
                }
            }
          } 
        } 
    }
  return { {0, 0, 0, 0}, {0, 0, 0, 0}};
}

// Driver Code 
int main() 
{ 
    vector<int> nums = { 1, 2, 3, 4 }; 
    vector<vector<int> > res = permute(nums); 
    
    int arr_size = res.size(); 


    
    // cout << is_valid_view(4,nums) << endl;

    // "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
    
    vector<vector<int>> cruel {{  4, 3, 2, 1},
                              {1, 2, 2, 2},
                              {2, 2, 2, 1},
                              {1, 2, 3, 4}  
                                        };

    // 4 2 3 1 3 1 4 2 1 2 3 4 2 4 1 3
    
    
     vector<vector<int>> grid = sky_final(res, cruel, arr_size);
     
   
       for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << ',';
        }
        cout << endl;
    }

    // cout << grid.size();
    // printing result 


    return 0; 
}
