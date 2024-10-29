#include <bits/stdc++.h> 

// Function for swapping two numbers 
void swap(int& x, int& y) 
{ 
    int temp = x; 
    x = y; 
    y = temp; 
} 

// Function to find the possible 
// permutations 
void permutations(std::vector<std::vector<int> >& res, 
                std::vector<int> nums, int l, int h) 
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
std::vector<std::vector<int> > permute(std::vector<int>& nums) 
{ 
    // Declaring result variable 
    std::vector<std::vector<int> > res; 
    int x = nums.size() - 1; 

    // Calling permutations for the first 
    // time by passing l 
    // as 0 and h = nums.size()-1 
    permutations(res, nums, 0, x); 
    return res; 
} 

bool check(std::array<std::array<char, 4>, 4>& board, int row, int col) {
	int n = board.size();
    std::vector<std::pair<int, int>> diag_coordinates{};
	for(int i = 1; i < n; i++) {
		// if(board[i][col] == 'Q') return false; // checking if any queen already placed on same column previously
		// checking all diagonals-
		if(row + i >= 0 && col - i >= 0 && board[row + i][col - i] == 'Q') return false; // left-down diag
		if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false; // right-up diag
		if(row - i <  n && col - i >= 0 && board[row - i][col - i] == 'Q') return false; // left-up diag
		if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; // right-down diag
        // if(row + i < n && col - i >= 0) diag_coordinates.push_back({row + i, col - i});
        // if(row - i >= 0 && col + i <  n) diag_coordinates.push_back({row - i, col + i});
        // if(row - i >= 0 && col - i >= 0) diag_coordinates.push_back({row - i, col - i});
        // if(row + i <  n && col + i <  n) diag_coordinates.push_back({row + i, col + i});
	}

    // for (const auto& it : diag_coordinates) {
    //     std::cout << it.first << ' ' << it.second << std::endl;
    // }


	return true;
}

bool is_valid_order(std::vector<int>& queen_ord) {
    std::array<std::array<char, 4>, 4> board {};

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = '.';
        }
    }

    for (int i = 0; i < board.size(); ++i) {
      board[i][queen_ord[i]] = 'Q';  
    }

    std::array<bool, 4> is_inPlase {};
    int k = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
           if (board[i][j] == 'Q') {
            is_inPlase[i] = check(board, i ,j);
           }
        } 
    }

    for (const auto& it : is_inPlase) {
        if (it == false) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<int> nums{};
    for (int i = 0; i < n; ++i) {
        nums.push_back(i);
    }
    std::vector<std::vector<int> > res = permute(nums); 

    std::vector<std::vector<int>> ans{};
    for (std::vector<int>& it : res) {
        if (is_valid_order(it)) {
            ans.push_back(it);
        }
    }

    return ans;
}

// Driver Code 
int main() 
{ 
    
    // for (int i = 0; i < res.size(); ++i) {
    //     for (int j = 0; j < res[i].size(); ++j) {
    //         std::cout << res[i][j] << ',';
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<std::vector<int>> ans = solveNQueens(1);
    
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            std::cout << ans[i][j] << ',';
        }
        std::cout << std::endl;
    }
    return 0; 
}




// void swap(int& x, int& y) { 
//         int temp = x; 
//         x = y; 
//         y = temp; 
//     } 

// // Function to find the possible 
// // permutations 
// void permutations(std::vector<std::vector<int> >& res, 
//                 std::vector<int> nums, int l, int h) 
// { 
//     // Base case 
//     // Add the vector to result and return 
//     if (l == h) { 
//         res.push_back(nums); 
//         return; 
//     } 

//     // Permutations made 
//     for (int i = l; i <= h; i++) { 

//         // Swapping 
//         swap(nums[l], nums[i]); 

//         // Calling permutations for 
//         // next greater value of l 
//         permutations(res, nums, l + 1, h); 

//         // Backtracking 
//         swap(nums[l], nums[i]); 
//     } 
// } 

// // Function to get the permutations 
// std::vector<std::vector<int> > permute(std::vector<int>& nums) 
// { 
//     // Declaring result variable 
//     std::vector<std::vector<int> > res; 
//     int x = nums.size() - 1; 

//     // Calling permutations for the first 
//     // time by passing l 
//     // as 0 and h = nums.size()-1 
//     permutations(res, nums, 0, x); 
//     return res; 
// } 

// bool check(std::vector<std::vector<char>>& board, int row, int col) {
// 	int n = board.size();
// 	for(int i = 1; i < n; i++) {
// 		// if(board[i][col] == 'Q') return false; // checking if any queen already placed on same column previously
// 		// checking all diagonals-
// 		if(row + i >= 0 && col - i >= 0 && board[row + i][col - i] == 'Q') return false; // left-down diag
// 		if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false; // right-up diag
// 		if(row - i <  n && col - i >= 0 && board[row - i][col - i] == 'Q') return false; // left-up diag
// 		if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; // right-down diag
//         // if(row + i < n && col - i >= 0) diag_coordinates.push_back({row + i, col - i});
//         // if(row - i >= 0 && col + i <  n) diag_coordinates.push_back({row - i, col + i});
//         // if(row - i >= 0 && col - i >= 0) diag_coordinates.push_back({row - i, col - i});
//         // if(row + i <  n && col + i <  n) diag_coordinates.push_back({row + i, col + i});
// 	}

//     // for (const auto& it : diag_coordinates) {
//     //     std::cout << it.first << ' ' << it.second << std::endl;
//     // }


// 	return true;
// }
// bool is_every_ok (std::vector<bool>& is_inPlase) {
//      for (const auto& it : is_inPlase) {
//         if (it == false) {
//             return false;
//         }
//     }
//     return true;
// }

// std::vector<std::string> is_valid_order(std::vector<int>& queen_ord) {
//     int size = queen_ord.size();
//     std::vector<std::vector<char>> board (size, std::vector<char>(size));

//     for (int i = 0; i < queen_ord.size(); ++i) {
//         for (int j = 0; j < queen_ord.size(); ++j) {
//             board[i][j] = '.';
//         }
//     }

//     for (int i = 0; i < board.size(); ++i) {
//       board[i][queen_ord[i]] = 'Q';  
//     }

//     std::vector<bool> is_inPlase(size);
//     int k = 0;
//     for (int i = 0; i < board.size(); ++i) {
//         for (int j = 0; j < board[i].size(); ++j) {
//            if (board[i][j] == 'Q') {
//             is_inPlase[i] = check(board, i ,j);
//            }
//         } 
//     }

//     std::vector<std::string> ans{};
//     if (is_every_ok(is_inPlase)) {
//         std::string sub_ans{};
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[i].size(); ++j) {
//                 sub_ans += board[i][j];
//             }
//             if (i != board.size() - 1) {
//                 sub_ans += ',';
//             }
//         }
//         ans.push_back(sub_ans);
//         return ans;
//     }
//     return ans;
// }

//     std::vector<std::vector<std::string>> solveNQueens(int n) {
//         std::vector<int> nums{};
//         for (int i = 0; i < n; ++i) {
//             nums.push_back(i);
//         }

//         std::vector<std::vector<int>> res = permute(nums); 

//         std::vector<std::vector<std::string>> ans{};

//         for (std::vector<int>& it : res) {
//             ans.push_back(is_valid_order(it));
//         }

//         return ans;
//     }



//     void swap(int& x, int& y) 
//     { 
//         int temp = x; 
//         x = y; 
//         y = temp; 
//     } 

// // Function to find the possible 
// // permutations 
// void permutations(std::vector<std::vector<int> >& res, 
//                 std::vector<int> nums, int l, int h) 
// { 
//     // Base case 
//     // Add the vector to result and return 
//     if (l == h) { 
//         res.push_back(nums); 
//         return; 
//     } 

//     // Permutations made 
//     for (int i = l; i <= h; i++) { 

//         // Swapping 
//         swap(nums[l], nums[i]); 

//         // Calling permutations for 
//         // next greater value of l 
//         permutations(res, nums, l + 1, h); 

//         // Backtracking 
//         swap(nums[l], nums[i]); 
//     } 
// } 

// // Function to get the permutations 
// std::vector<std::vector<int> > permute(std::vector<int>& nums) 
// { 
//     // Declaring result variable 
//     std::vector<std::vector<int> > res; 
//     int x = nums.size() - 1; 

//     // Calling permutations for the first 
//     // time by passing l 
//     // as 0 and h = nums.size()-1 
//     permutations(res, nums, 0, x); 
//     return res; 
// } 

// bool check(std::vector<std::vector<char>>& board, int row, int col) {
// 	int n = board.size();
// 	for(int i = 1; i < n; i++) {
// 		// if(board[i][col] == 'Q') return false; // checking if any queen already placed on same column previously
// 		// checking all diagonals-
// 		if(row + i >= 0 && col - i >= 0 && board[row + i][col - i] == 'Q') return false; // left-down diag
// 		if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false; // right-up diag
// 		if(row - i <  n && col - i >= 0 && board[row - i][col - i] == 'Q') return false; // left-up diag
// 		if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; // right-down diag
//         // if(row + i < n && col - i >= 0) diag_coordinates.push_back({row + i, col - i});
//         // if(row - i >= 0 && col + i <  n) diag_coordinates.push_back({row - i, col + i});
//         // if(row - i >= 0 && col - i >= 0) diag_coordinates.push_back({row - i, col - i});
//         // if(row + i <  n && col + i <  n) diag_coordinates.push_back({row + i, col + i});
// 	}

//     // for (const auto& it : diag_coordinates) {
//     //     std::cout << it.first << ' ' << it.second << std::endl;
//     // }


// 	return true;
// }
// bool is_every_ok (std::vector<bool>& is_inPlase) {
//      for (const auto& it : is_inPlase) {
//         if (it == false) {
//             return false;
//         }
//     }
//     return true;
// }

// std::vector<std::string> is_valid_order(std::vector<int>& queen_ord) {
//     int size = queen_ord.size();
//     std::vector<std::vector<char>> board (size, std::vector<char>(size));

//     for (int i = 0; i < queen_ord.size(); ++i) {
//         for (int j = 0; j < queen_ord.size(); ++j) {
//             board[i][j] = '.';
//         }
//     }

//     for (int i = 0; i < board.size(); ++i) {
//       board[i][queen_ord[i]] = 'Q';  
//     }

//     std::vector<bool> is_inPlase(size);
//     int k = 0;
//     for (int i = 0; i < board.size(); ++i) {
//         for (int j = 0; j < board[i].size(); ++j) {
//            if (board[i][j] == 'Q') {
//             is_inPlase[i] = check(board, i ,j);
//            }
//         } 
//     }

//     std::vector<std::string> ans{};
//     if (is_every_ok(is_inPlase)) {
//         std::string sub_ans{};
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[i].size(); ++j) {
//                 sub_ans += board[i][j];
//             }
//             if (i != board.size() - 1) {
//                 sub_ans += ',';
//             }
//         }
//         ans.push_back(sub_ans);
//         return ans;
//     }
//     return ans;
// }

//    std::vector<std::vector<std::string>> solveNQueens(int n) {
//        std::vector<int> nums{};
//         for (int i = 0; i < n; ++i) {
//             nums.push_back(i);
//         }

//         std::vector<std::vector<int>> res = permute(nums); 

//         std::vector<std::vector<std::string>> ans{};

//         for (std::vector<int>& it : res) {
//             ans.push_back(is_valid_order(it));
//         }
//         return ans;
//     }


//      int main() 
// { 
    
//     // for (int i = 0; i < res.size(); ++i) {
//     //     for (int j = 0; j < res[i].size(); ++j) {
//     //         std::cout << res[i][j] << ',';
//     //     }
//     //     std::cout << std::endl;
//     // }

//     std::vector<std::vector<std::string>> ans = solveNQueens(4);
    
//     for (int i = 0; i < ans.size(); ++i) {
//         for (int j = 0; j < ans[i].size(); ++j) {
//             std::cout << ans[i][j] << ',';
//         }
//         std::cout << std::endl;
//     }
//     return 0; 
// }