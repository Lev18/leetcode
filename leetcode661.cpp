#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
   const int rows = img.size();
    const int cols = img[0].size();
    if (rows == 1 && cols == 1) {
        return img;
    }
    
    int count = 0;
    std::vector<std::vector<int>> arr(rows + 2, std::vector<int>(cols + 2, 0));
    std::vector<int> tmp;
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i + 1][j + 1] = img[i][j];  
        }
    }

    int sum {0};

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            sum +=  arr[i][j]; 
            sum +=  arr[i + 1][j + 1];
            sum +=  arr[i - 1][j - 1]; 
            sum +=  arr[i][j - 1]; 
            sum +=  arr[i - 1][j]; 
            sum +=  arr[i + 1][j]; 
            sum +=  arr[i][j + 1]; 
            sum +=  arr[i + 1][j - 1];
            sum +=  arr[i - 1][j + 1]; 

            if (rows == 1 || cols == 1) {
                tmp.push_back(sum / 2);
            }

            else if ((i == 1 && j == 1) || (i == 1 && j == cols)
                ||  (i == rows && j == 1) || (i == rows && j == cols)) {
                    tmp.push_back(sum / 4);
            }
            else if ((j == 1 && i != rows && i != 1)
                ||   (j == cols && i != rows && i != 1)
                ||   (i == 1 &&  j != cols && j != 1)
                ||   (i == rows &&  j != cols && j != 1)) {
                    tmp.push_back(sum / 6);
            }
            else {
               
                tmp.push_back(sum / count);
            }
            sum = 0;
            count = 9;
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}

int main() {
    // Sample usage
    std::vector<std::vector<int>> img = {{2,3}};
    std::unordered_map<int, int> map;
    map[0] = 8;
    std::vector<std::vector<int>> smoothedImg = imageSmoother(img);
    
    // Printing the smoothed image for demonstration
    for (const auto& row : smoothedImg) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

